//  Adouble-endedqueue(deque)isalinearlistinwhichadditionsanddeletionsmaybe made
//  ateitherend.Obtainadatarepresentationmappingadequeintoaone-dimensionalarray.
//  WriteC++programtosimulatedequewithfunctionstoaddanddeleteelementsfromeither
//  endofthedeque.
#include <iostream>
#include <stdexcept>  // For exception handling
using namespace std;

class Deque {
private:
    int *arr;           // Array to hold deque elements
    int front;          // Front index of the deque
    int back;           // Back index of the deque
    int size;           // Current number of elements in the deque
    int capacity;       // Maximum capacity of the deque

public:
    // Constructor to initialize deque with a fixed size
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        back = -1;
        size = 0;
    }

    // Destructor to free the allocated memory
    ~Deque() {
        delete[] arr;
    }

    // Function to check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to add an element at the front
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add to the front." << endl;
            return;
        }

        if (isEmpty()) {
            front = back = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        cout << "Added " << value << " to the front." << endl;
    }

    // Function to add an element at the back
    void addBack(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add to the back." << endl;
            return;
        }

        if (isEmpty()) {
            front = back = 0;
        } else {
            back = (back + 1) % capacity;
        }
        arr[back] = value;
        size++;
        cout << "Added " << value << " to the back." << endl;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return;
        }

        cout << "Removed " << arr[front] << " from the front." << endl;

        if (front == back) {  // If there's only one element
            front = back = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Function to delete an element from the back
    void deleteBack() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the back." << endl;
            return;
        }

        cout << "Removed " << arr[back] << " from the back." << endl;

        if (front == back) {  // If there's only one element
            front = back = -1;
        } else {
            back = (back - 1 + capacity) % capacity;
        }
        size--;
    }

    // Function to display elements in the deque
    void displayDeque() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque dq(capacity);

    int choice, value;
    do {
        // Display menu options
        cout << "\nDeque Operations Menu\n";
        cout << "1. Add Front\n";
        cout << "2. Add Back\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Back\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to add at the front: ";
                cin >> value;
                dq.addFront(value);
                break;

            case 2:
                cout << "Enter the value to add at the back: ";
                cin >> value;
                dq.addBack(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteBack();
                break;

            case 5:
                dq.displayDeque();
                break;

            case 6:
                cout << "Exiting the deque simulation." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);  // Exit when user chooses option 6

    return 0;
}
