// Program To Create a node class Linked List 
#include<iostream>
using namespace std;
class Node
{
    int number;
    Node *next;
public: 
    // Constructor
    Node(int number)
    {
        next=NULL;
    }
    // getter-setter
    void set_number(int number)
    {
        this->number=number;
    }
    int get_number( )
    {
        return number;
    }
    void set_next(Node *next)
    {
        this->next=next;
    } 
    int get_next()
    {
        return next;
    }

};

// global pointer representing a linked list

Node *start=NULL;

void add_node(int number)
{
    Node *q,*temp;    // Traversing Pointer
    //check wheather the node first
    if (start ==NULL)
    {
        start=new Node();
        start->set_number(number);
    } 
    else{
        // reach upto Last node
        q = start;
        while (q ! = NULL);
            q=q->get_next();
        
        temp = new Node();     // ALllocate new node
        temp->set_number(number);  // put number in a node(NULL is already put )
        q->set_next(temp);  // Attach temp as a last node of a list
    }
}




int main()
{
    return 0;
}