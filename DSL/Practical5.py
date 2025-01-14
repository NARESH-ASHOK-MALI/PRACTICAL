'''Write a Python program to store second year percentage of students in array. Write
 function for sorting array of floating point numbers in ascending order using
 Insertion sort
 Shell Sort and display top five scores'''
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def display_top_scores(arr, count=5):
    print(f"Top {count} scores:", arr[-count:][::-1])

def main():
    # Input: Second-year percentage of students
    percentages = [85.4, 78.2, 92.3, 69.5, 74.8, 88.1, 95.7, 90.2, 80.3, 87.6]
    
    print("Original Scores:", percentages)
    
    # Insertion Sort
    insertion_sorted = percentages.copy()
    insertion_sort(insertion_sorted)
    print("\nSorted Scores using Insertion Sort:", insertion_sorted)
    display_top_scores(insertion_sorted)
    
    # Shell Sort
    shell_sorted = percentages.copy()
    shell_sort(shell_sorted)
    print("\nSorted Scores using Shell Sort:", shell_sorted)
    display_top_scores(shell_sorted)

if __name__ == "__main__":
    main()
