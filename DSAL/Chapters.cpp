//A book consists of chapters, chapters consist of sections and sections consist of
//subsections. Construct a tree and print the nodes. Find the time and space requirements of
//your method
#include<iostream>
using namespace std;

struct node{
    string name;
    int count;
    struct node* child[10];
}*root;

class book{
    public:
    book(){
        root=NULL;
    }
    void createTree() {
        root=new node;
        cout<<"Enter name of book :";
        cin>>root->name;
        cout<<"Enter number of chapters: ";
        cin>>root->count;
        for(int i=0;i<root->count;i++) {
            root->child[i]=new node;
            cout << "Enter name of chapter :";
            cin >> root->child[i]->name;
            cout << "Enter number of section: ";
            cin >> root->child[i]->count;
            for (int j = 0; j < root->child[i]->count;j++) {
                root->child[i]->child[j]= new node;
                cout << "Enter name of section :";
                cin >> root->child[i]->child[j]->name;
                cout << "Enter number of sub-section: ";
                cin >> root->child[i]->child[j]->count;
            }
        }
    }

    void displayTree() {
        cout<<root->name<<endl;
        for (int i = 0; i < root->count; i++) {
            cout<<"  "<<root->child[i]->name<<endl;
            for (int j = 0; j < root->child[i]->count; j++){
                cout << "    " << root->child[i]->child[j]->name << endl;
            }
        }
    }
};

int main() {
    book b;
    b.createTree();
    b.displayTree();

    return 0;
}