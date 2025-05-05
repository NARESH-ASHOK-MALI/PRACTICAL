// Dictionary stores keyword and its meanings using Binary Search Tree (BST) 
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword;
    string meaning;
    Node* left;
    Node* right;

    Node(string keyword, string meaning) {
        this->keyword = keyword;
        this->meaning = meaning;
        left = right = nullptr;
    }
};

class DictionaryBST {
private:
    Node* root;

    // Helper function to insert a new keyword and its meaning
    Node* insert(Node* node, string keyword, string meaning) {
        if (node == nullptr) {
            return new Node(keyword, meaning);
        }
        if (keyword < node->keyword) {
            node->left = insert(node->left, keyword, meaning);
        } else if (keyword > node->keyword) {
            node->right = insert(node->right, keyword, meaning);
        }
        return node;
    }

    // Helper function to search for a keyword
    Node* search(Node* node, string keyword) {
        if (node == nullptr || node->keyword == keyword) {
            return node;
        }
        if (keyword < node->keyword) {
            return search(node->left, keyword);
        }
        return search(node->right, keyword);
    }

    // Helper function for in-order traversal (ascending order)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->keyword << ": " << node->meaning << endl;
            inorder(node->right);
        }
    }

    // Helper function for reverse in-order traversal (descending order)
    void reverseInorder(Node* node) {
        if (node != nullptr) {
            reverseInorder(node->right);
            cout << node->keyword << ": " << node->meaning << endl;
            reverseInorder(node->left);
        }
    }

    // Helper function to delete a keyword
    Node* deleteNode(Node* node, string keyword) {
        if (node == nullptr) {
            return node;
        }

        if (keyword < node->keyword) {
            node->left = deleteNode(node->left, keyword);
        } else if (keyword > node->keyword) {
            node->right = deleteNode(node->right, keyword);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children, get the inorder successor
            Node* temp = minValueNode(node->right);
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }

        return node;
    }

    // Helper function to find the minimum value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to find height of the tree (maximum comparisons)
    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
  public:
    DictionaryBST() {
        root = nullptr;
    }

    // Public insert function
    void insert(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    // Public search function
    void update(string keyword, string newMeaning) {
        Node* node = search(root, keyword);
        if (node != nullptr) {
            node->meaning = newMeaning;
        } else {
            cout << "Keyword '" << keyword << "' not found!" << endl;
        }
    }

    // Public delete function
    void deleteKeyword(string keyword) {
        root = deleteNode(root, keyword);
    }

    // Public display functions
    void displayAscending() {
        cout << "Ascending Order:" << endl;
        inorder(root);
    }

    void displayDescending() {
        cout << "Descending Order:" << endl;
        reverseInorder(root);
    }

    // Public function to find the maximum comparisons (height of the tree)
    int maxComparisons() {
        return height(root);
    }
};

int main() {
    DictionaryBST dictionary;

    // Insert some keywords and meanings
    dictionary.insert("apple", "A fruit");
    dictionary.insert("banana", "A yellow fruit");
    dictionary.insert("grape", "A small fruit");
    dictionary.insert("pear", "A type of fruit");

    // Display the dictionary in ascending order
    dictionary.displayAscending();

    // Display the dictionary in descending order
    dictionary.displayDescending();

    // Update the meaning of a keyword
    dictionary.update("apple", "A sweet fruit");

    // Display updated dictionary
    dictionary.displayAscending();

    // Delete a keyword
    dictionary.deleteKeyword("banana");

    // Display the dictionary after deletion
    dictionary.displayAscending();

    // Find the maximum comparisons (height of the tree)
    cout << "Maximum Comparisons Required: " << dictionary.maxComparisons() << endl;

    return 0;
}
