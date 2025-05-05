#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;  
};

class bt{
    public:
        Node *root;
    bt(){
        root=NULL;
    }

    void createTree(int value[],int n) {
        root=new Node;
        root->data=value[0];
        root->left=NULL;
        root->right=NULL;
        for(int i=1;i<n;i++) {
            insert(root,value[i]);
        }
    }

    void insert(Node *root,int data) {
        Node *temp=new Node;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        if(data<root->data){
            if(root->left==NULL){
                root->left=temp;
            }
            else{
                insert(root->left,data);
            }
        }
        else{
            if(root->right==NULL) {
                root->right=temp;
            }
            else{
                insert(root->right, data);
            }
        }
    }

    void minData() {
        int min=INT_MAX;
        Node *current;
        current=root;
        while(true) {
            if(current->left==NULL) {
                cout<<"Minimum data value is: "<<current->data;
                return;
            }
            else{
                current=current->left;
            }
        }
    }

    void search() {
        cout<<"Enter key to be searched: ";
        int key;
        cin>>key;
        Node*current=root; 
        while(current) {
            if(current->data==key) {
                cout<<"Key found";
                return;
            }
            else if (current->data >key) {
                current=current->left;
            }
            else if (current->data <key) {
                current=current->right;
            }
        }
        cout<<"key not found"<<endl;
    }

    void display(Node* root) {
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }

    void mirror(Node *root) {
        if(root==NULL) {
            return;
        }
        swap(root->left,root->right);
        mirror(root->left);
        mirror(root->right);
    }

    int longestpath(Node* root) {
        if(root==NULL) {
            return 0;
        }
        return 1 + max(longestpath(root->left), longestpath(root->right));
    }
};


int main() {
    int value[]={10,14,2,11};
    int n = sizeof(value) / sizeof(value[0]);
    bt tree;
    tree.createTree(value,n);
    cout<<tree.longestpath(tree.root);
    return 0;
}