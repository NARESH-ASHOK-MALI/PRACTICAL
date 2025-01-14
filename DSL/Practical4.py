''' Write a Python program to store first year percentage of students in array. Write function
 for sorting array of floating point numbers in ascending order using
 Selection Sort
 Bubble sort and display top five scores'''
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def display_top_scores(arr, count=5):
    print(f"Top {count} scores:", arr[-count:][::-1])

def main():
    # Input: First-year percentage of students
    percentages = [88.5, 72.3, 91.2, 68.4, 77.8, 84.0, 95.3, 89.6, 76.4, 83.1]
    
    print("Original Scores:", percentages)
    
    # Selection Sort
    selection_sorted = percentages.copy()
    selection_sort(selection_sorted)
    print("\nSorted Scores using Selection Sort:", selection_sorted)
    display_top_scores(selection_sorted)
    
    # Bubble Sort
    bubble_sorted = percentages.copy()
    bubble_sort(bubble_sorted)
    print("\nSorted Scores using Bubble Sort:", bubble_sorted)
    display_top_scores(bubble_sorted)

if __name__ == "__main__":
    main()

