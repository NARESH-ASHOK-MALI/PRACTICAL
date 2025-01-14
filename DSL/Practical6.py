'''Write a Python program to store first year percentage of students in array. Write function
 for sorting array of floating point numbers in ascending order using quick sort and display
 top five scores.'''
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

def display_top_scores(arr, count=5):
    print(f"Top {count} scores:", arr[-count:][::-1])

def main():
    # Input: First-year percentage of students
    percentages = [78.5, 82.3, 91.4, 69.7, 88.2, 75.5, 94.6, 85.1, 73.4, 89.9]
    
    print("Original Scores:", percentages)
    
    # Quick Sort
    sorted_percentages = quick_sort(percentages)
    print("\nSorted Scores using Quick Sort:", sorted_percentages)
    display_top_scores(sorted_percentages)

if __name__ == "__main__":
    main()
