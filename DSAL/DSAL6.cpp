#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int key;
    Node *ln, *rn;
    Node(int val){
        key = val;
        ln = rn = nullptr;
    }
};
class tree{
    public:
    Node* root;
    tree(){
        root=nullptr;
    }
    
    Node* createtree(int key){
        root=new Node(key);
        return root;
    }
    void insertnode(int key,Node* root){
        Node* node=new Node(key);
        if (key<=root->key){
            if (root->ln==nullptr){
                root->ln=node;
            }else{
                insertnode(key,root->ln);
            }
        }else{
            if (root->rn==nullptr){
                root->rn=node;
            }else{
                insertnode(key,root->rn);
            }
            
        }
        
    }
    void displayinorder(Node* root){
        if (root!=nullptr){
            displayinorder(root->ln);
            cout<<root->key<<" ";
            displayinorder(root->rn);
        } 
    }
    void swapnodes(Node* root){
        if(root!=nullptr){
            Node* temp=root->ln;
            root->ln=root->rn;
            root->rn=temp;
            swapnodes(root->ln);
            swapnodes(root->rn);
        }
    }
    void displaysmallest(Node* root){
        while (root->ln!=nullptr){
            root=root->ln;
        } 
        cout << "The smallest number is " << root->key << endl;
    }
    int maxdepth(Node* root){
        if(root==nullptr ){
            return 0;
        }
        int leftdepth= maxdepth(root->ln);
        int rightdepth=maxdepth(root->rn);
        return max(leftdepth,rightdepth)+1;
    }
    Node* searchTree(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root;
        if (key < root->key)
            return searchTree(root->ln, key);
        return searchTree(root->rn, key);
    }

};

int main() {
    cout<<"Name:Naresh Ashok Mali Roll No.:SCOD16"<<endl;
    int key, choice, flag = 0;
    tree a;
    Node *root = NULL;

    do {
        cout << "<------------------------------------------->"<<endl;
        cout << "|Enter the operation you want to perform:   |"<<endl;
        cout << "|1. Insert a node                           |"<<endl;
        cout << "|2. Display the tree in order               |"<<endl;
        cout << "|3. Display the smallest number             |"<<endl;
        cout << "|4. Search for a node                       |"<<endl;
        cout << "|5. Swap nodes                              |"<<endl;
        cout << "|6. Max Depth                               |"<<endl;
        cout << "|7. Exit                                    |"<<endl;
        cout << "<------------------------------------------->"<<endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the key value: ";
            cin >> key;
            if (flag == 0) {
                root = a.createtree(key);
                flag++;
            } else {
                a.insertnode(key, root);
            }
            break;
        case 2:
            a.displayinorder(root);
            cout << endl;
            break;
        case 3:
            a.displaysmallest(root);
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
             a.swapnodes(root);
             break;


        case 6:
            cout << "MAX DEPTH IS :" << endl;
            cout<<a.maxdepth(root);
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}