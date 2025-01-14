'''Write a Python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using quick sort and display
top five scores.'''
print("USER IS NARESH ASHOK MALI SCOD 16")
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)


percentages = []
num_students = int(input("Enter the number of students: "))
for _ in range(num_students):
        score = float(input("Enter the percentage of the student: "))
        percentages.append(score)
sorted_percentages = quick_sort(percentages)
print("\nTop five scores in ascending order:")
top_five = sorted_percentages[-5:] if len(sorted_percentages) >= 5 else sorted_percentages
for score in top_five:
        print(score)

