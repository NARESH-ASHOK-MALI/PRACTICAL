#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *ln, *rn;
    Node(int val) {
        key = val;
        ln = rn = NULL;
    }
};

class Tree {
public:
    Node *root;

    Tree() { root = NULL; }

    Node* createTree(int key) {
        root = new Node(key);
        return root;
    }

    void insertNode(int key, Node* root) {
        Node* node = new Node(key);
        if (key <= root->key) {
            if (root->ln == NULL) {
                root->ln = node;
            } else {
                insertNode(key, root->ln);
            }
        } else {
            if (root->rn == NULL) {
                root->rn = node;
            } else {
                insertNode(key, root->rn);
            }
        }
    }

    void displayInOrder(Node* root) {
        if (root != NULL) {
            displayInOrder(root->ln);
            cout << root->key << " ";
            displayInOrder(root->rn);
        }
    }

   void swapNodes(Node* root) {
    if (root != NULL) {
        Node* temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;
        swapNodes(root->ln);
        swapNodes(root->rn);
    }
}

    void displaySmallest(Node* root) {
        while (root->ln != NULL) {
            root = root->ln;
        }
        cout << "The smallest number is " << root->key << endl;
    }

    Node* searchTree(Node* root, int key) {
        if (root == NULL || root->key == key)
            return root;
        if (key < root->key)
            return searchTree(root->ln, key);
        return searchTree(root->rn, key);
    }
};

int main() {
    int key, choice, flag = 0;
    Tree a;
    Node *root = NULL;

    do {
        cout << "Enter the operation you want to perform:\n";
        cout << "1. Insert a node\n2. Display the tree in order\n3. Display the smallest number\n4. Search for a node\n5. Swap nodes\n6.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the key value: ";
            cin >> key;
            if (flag == 0) {
                root = a.createTree(key);
                flag++;
            } else {
                a.insertNode(key, root);
            }
            break;
        case 2:
            a.displayInOrder(root);
            cout << endl;
            break;
        case 3:
            a.displaySmallest(root);
            break;
        case 4:
            cout << "Enter key to search: ";
            cin >> key;
            if (a.searchTree(root, key) != NULL)
                cout << "Key found in the tree." << endl;
            else
                cout << "Key not found." << endl;
            break;
    
        case 5:
             cout << "Swapping the nodes" << endl;
             a.swapNodes(root);
             break;


          case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}