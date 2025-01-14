#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    char label[10];         
    int ch_count;           
    Node* child[10];        
} *root;                     

class TREE {
public:
    TREE() {
        root = NULL;
    }

    void create_tree() {
        int tbooks, tchapters, i, j, k;
        root = new Node(); 

        cout << "Enter name of book: ";
        cin >> root->label;

        cout << "Enter number of chapters in book: ";
        cin >> tchapters;
        root->ch_count = tchapters;

        for (i = 0; i < tchapters; i++) { 
            root->child[i] = new Node; 
            cout << "Enter Chapter name: ";
            cin >> root->child[i]->label;

            cout << "Enter number of sections in this Chapter: ";
            cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++) { 
            root->child[i]->child[j] = new Node;
            cout << "Enter Section head: ";
            cin >> root->child[i]->child[j]->label;

            cout << "Enter number of subsections sections in this sections: ";
            cin >> root->child[i]->child[j]->ch_count;

        for ( k = 0; k < root->child[i]->child[j]->ch_count; k++){
            root->child[i]->child[j]->child[k] = new Node;
            cout << "Enter Sub-Section head: ";
            cin >> root->child[i]->child[j]->child[k]->label;
        }
        
        }
    }
}   
void display(Node* rl) {
    if (rl != NULL) {
        cout << "\nBook Hierarchy---" << endl;
        cout << "Book title: " << rl->label << endl;

        int tchapters = rl->ch_count;
        for (int i = 0; i < tchapters; i++) {
            cout << "Chapter " << i + 1 << ": " << rl->child[i]->label << endl;

            for (int j = 0; j < rl->child[i]->ch_count; j++) {
                cout << "  Section " << j + 1 << ": " << rl->child[i]->child[j]->label << endl;

                cout << "    Subsections: ";
                for (int k = 0; k < rl->child[i]->child[j]->ch_count; k++) {
                    cout << rl->child[i]->child[j]->child[k]->label << " ";
                }
                cout << endl;
            }
        }
    }
}

};

int main() {
    int choice;
    TREE BOOK;

    while (1) {
        cout << "Book Tree Creation" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                BOOK.create_tree();
                break;
            case 2:
                BOOK.display(root);
                break;
            case 3:
                exit(1);
            default:
                cout << "Wrong choice" << endl;
        }
    }
}
