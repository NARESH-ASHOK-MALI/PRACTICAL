//  PizzaparloracceptingmaximumMorders.Ordersareservedinfirstcomefirstservedbasis.
//  Orderonceplacedcannotbecancelled.WriteC++programtosimulatethesystemusing
//  circularqueueusingarray.
#include <iostream>
#include <string>
using namespace std;

class PizzaParlor {
private:
    string* queue;    // Array to hold orders
    int front;        // Front index of the queue
    int rear;         // Rear index of the queue
    int size;         // Number of orders currently in the queue
    int capacity;     // Maximum capacity of the queue

public:
    // Constructor to initialize the queue with the specified capacity
    PizzaParlor(int cap) {
        capacity = cap;
        queue = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to clean up dynamically allocated memory
    ~PizzaParlor() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to place an order
    void placeOrder(string order) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is full. Cannot place more orders." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0; // The first order will be at both front and rear
        } else {
            rear = (rear + 1) % capacity; // Circular increment of the rear pointer
        }

        queue[rear] = order;  // Add the order to the rear of the queue
        size++;  // Increase the size of the queue
        cout << "Order placed: " << order << endl;
    }

    // Function to serve the first order (dequeue from the front)
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }

        cout << "Serving order: " << queue[front] << endl;
        front = (front + 1) % capacity; // Circular increment of the front pointer
        size--;  // Decrease the size of the queue

        // Reset front and rear if the queue becomes empty
        if (isEmpty()) {
            front = rear = -1;
        }
    }

    // Function to display all orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity; // Circular increment
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> capacity;

    PizzaParlor pizzaParlor(capacity);

    int choice;
    string order;
    do {
        // Display menu options
        cout << "\nPizza Parlor Menu\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order description: ";
                cin.ignore(); // To ignore the newline character left in the input buffer
                getline(cin, order); // Get the full order description
                pizzaParlor.placeOrder(order);
                break;

            case 2:
                pizzaParlor.serveOrder();
                break;

            case 3:
                pizzaParlor.displayOrders();
                break;

            case 4:
                cout << "Exiting the pizza parlor simulation." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);  // Exit when the user chooses option 4

    return 0;
}
