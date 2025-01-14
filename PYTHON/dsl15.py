#Write a python program to store second year percentage of students in array. Write 
#function for sorting array of floating point numbers in ascending order using 
#a) Insertion sort 
#b) Shell Sort and display top five scores
Percentages = [58.2, 73.1, 85.5, 44.0, 91.3, 65.7, 77.8, 89.4, 52.3, 68.9, 71.0, 95.5, 60.4]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
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
            # Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

percentages_for_insertion = Percentages.copy()
percentages_for_shell = Percentages.copy()

insertion_sort(percentages_for_insertion)
print("Sorted Array using Insertion Sort:")
print(percentages_for_insertion)
print("Top five scores using Insertion Sort:")
print(percentages_for_insertion[-5:])

shell_sort(percentages_for_shell)
print("\nSorted Array using Shell Sort:")
print(percentages_for_shell)
print("Top five scores using Shell Sort:")
top_five_shell = percentages_for_shell[-5:]
print(top_five_shell)
