// '''Write a function template for
// selection sort that inputs, sorts
// and outputs an integer array and
// a float array.'''
#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T>
void displayArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArray[] = {64, 25, 12, 22, 11};
    float floatArray[] = {64.5, 25.2, 12.1, 22.9, 11.4};

    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "Original integer array: ";
    displayArray(intArray, intSize);

    selectionSort(intArray, intSize);

    cout << "Sorted integer array: ";
    displayArray(intArray, intSize);

    cout << "\nOriginal float array: ";
    displayArray(floatArray, floatSize);

    selectionSort(floatArray, floatSize);

    cout << "Sorted float array: ";
    displayArray(floatArray, floatSize);

    return 0;
}
