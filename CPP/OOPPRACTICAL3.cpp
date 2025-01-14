#include <iostream>
using namespace std;
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout<<"User is Naresh Ashok Mali\nSCOD 16\n";
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    float floatArr[] = {64.5, 25.2, 12.1, 22.8, 11.3};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    
    cout << "Original integer array: ";
    printArray(intArr, intSize);
    selectionSort(intArr, intSize);
    cout << "Sorted integer array: ";
    printArray(intArr, intSize);
    cout << "\nOriginal float array: ";
    printArray(floatArr, floatSize);
    selectionSort(floatArr, floatSize);
    cout << "Sorted float array: ";
    printArray(floatArr, floatSize);

    return 0;
}
