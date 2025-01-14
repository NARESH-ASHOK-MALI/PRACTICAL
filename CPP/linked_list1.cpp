#include<iostream>
using namespace std;

class Node {
    int number;
    Node *next;

public: 
    // Constructor
    Node(int number) {
        this->number = number;  // Initialize the number
        next = NULL;            // Initialize next to NULL
    }

    // Getter and Setter for 'number'
    void set_number(int number) {
        this->number = number;
    }

    int get_number() {
        return number;
    }

    // Getter and Setter for 'next' node
    void set_next(Node *next) {
        this->next = next;
    }

    Node* get_next() {  // Return type should be Node*
        return next;
    }
};

// Global pointer representing the start of the linked list
Node *start = NULL;

void add_node(int number) {
    Node *q, *temp;

    // If the linked list is empty, create the first node
    if (start == NULL) {
        start = new Node(number);  // Use constructor to initialize 'number'
    } else {
        // Traverse to the last node
        q = start;
        while (q->get_next() != NULL) {  // Correct condition and removed extra semicolon
            q = q->get_next();
        }

        // Allocate a new node and set its value
        temp = new Node(number);  // Create new node with 'number'
        q->set_next(temp);        // Attach the new node at the end
    }
}

int main() {
    // Example usage:
    // Adding nodes
    add_node(10);
    add_node(20);
    add_node(30);

    // Print the linked list to verify
    Node *current = start;
    while (current != NULL) {
        cout << current->get_number() << " ";
        current = current->get_next();
    }

    return 0;
}
