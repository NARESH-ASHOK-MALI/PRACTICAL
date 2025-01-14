// TheticketbookingsystemofCinemaxtheaterhastobeimplementedusingC++program.
//  Thereare10rowsand7seatsineachrow.Doublycircularlinkedlisthastobemaintained
//  tokeeptrackoffreeseatsat rows.Assumesomerandombookingtostartwith.Usearray
//  tostorepointers(Headpointer)toeachrow.Ondemand
//  Thelistofavailableseatsistobedisplayed
//  Theseatsaretobebooked
//  Thebookingcanbecancelled
#include <iostream>
using namespace std;

// Node for the doubly circular linked list
class Node {
public:
    int seatNumber;
    bool isBooked;
    Node* next;
    Node* prev;

    Node(int seatNumber) : seatNumber(seatNumber), isBooked(false), next(nullptr), prev(nullptr) {}
};

// Doubly Circular Linked List for each row
class Row {
private:
    Node* head;

public:
    Row() : head(nullptr) {}

    // Initialize the row with 7 seats
    void initializeRow(int rowNumber) {
        for (int i = 1; i <= 7; i++) {
            Node* newNode = new Node(i);
            if (!head) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node* tail = head->prev;
                tail->next = newNode;
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
            }
        }
        cout << "Row " << rowNumber << " initialized with 7 seats." << endl;
    }

    // Display available seats
    void displayAvailableSeats(int rowNumber) {
        cout << "Available seats in Row " << rowNumber << ": ";
        Node* temp = head;
        bool anyAvailable = false;
        do {
            if (!temp->isBooked) {
                cout << temp->seatNumber << " ";
                anyAvailable = true;
            }
            temp = temp->next;
        } while (temp != head);

        if (!anyAvailable) {
            cout << "No seats available!";
        }
        cout << endl;
    }

    // Book a seat
    void bookSeat(int seatNumber) {
        Node* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (temp->isBooked) {
                    cout << "Seat " << seatNumber << " is already booked!" << endl;
                } else {
                    temp->isBooked = true;
                    cout << "Seat " << seatNumber << " has been successfully booked." << endl;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Seat " << seatNumber << " does not exist in this row!" << endl;
    }

    // Cancel a booking
    void cancelBooking(int seatNumber) {
        Node* temp = head;
        do {
            if (temp->seatNumber == seatNumber) {
                if (!temp->isBooked) {
                    cout << "Seat " << seatNumber << " is already free!" << endl;
                } else {
                    temp->isBooked = false;
                    cout << "Seat " << seatNumber << " booking has been successfully canceled." << endl;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Seat " << seatNumber << " does not exist in this row!" << endl;
    }
};

int main() {
    const int rows = 10;
    Row theater[rows]; // Array of Row objects

    // Initialize all rows
    for (int i = 0; i < rows; i++) {
        theater[i].initializeRow(i + 1);
    }

    // Simulate some random bookings
    theater[0].bookSeat(3); // Book seat 3 in row 1
    theater[1].bookSeat(5); // Book seat 5 in row 2
    theater[2].bookSeat(7); // Book seat 7 in row 3

    int choice;
    do {
        cout << "\n--- Cinimax Theater Ticket Booking System ---\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < rows; i++) {
                    theater[i].displayAvailableSeats(i + 1);
                }
                break;
            }
            case 2: {
                int rowNumber, seatNumber;
                cout << "Enter row number (1-10): ";
                cin >> rowNumber;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (rowNumber >= 1 && rowNumber <= 10) {
                    theater[rowNumber - 1].bookSeat(seatNumber);
                } else {
                    cout << "Invalid row number!" << endl;
                }
                break;
            }
            case 3: {
                int rowNumber, seatNumber;
                cout << "Enter row number (1-10): ";
                cin >> rowNumber;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (rowNumber >= 1 && rowNumber <= 10) {
                    theater[rowNumber - 1].cancelBooking(seatNumber);
                } else {
                    cout << "Invalid row number!" << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
