/*
NAME: NARESH ASHOK MALI ROLL NO : SCOD16
Problem statement : A Dictionary stores keywords & its meanings. Provide 
facility for adding new keywords, deleting keywords, updating values of 
any entry. Provide facility to display whole data sorted in ascending/ 
Descending order. Also find how many maximum comparisons may require for 
finding any keyword. Use Height balance tree and find the complexity for 
finding a keyword
*/

#include<iostream>
using namespace std;
class Node {
public:
	Node* Ln, *Rn;
	string key, val;
	int height;
};
class Avl {
public:
	Node* create(Node* root, string key, string val) {
	root = new Node();
	root->key = key;
	root->val = val;
	root->Ln = NULL;
	root->Rn = NULL;
	root->height = 1;
	return root;
	}

	Node* insert(Node* root, string key, string val) {
	if (root == NULL)
	return create(root, key, val);
	else if (key < root->key) {
	root->Ln = insert(root->Ln, key, val);
	} else if (key > root->key)

	{
	root->Rn = insert(root->Rn, key, val);
	}
	return root;
	}

	int height(Node *temp) {
	int h = 0;
	if (temp != NULL) {
	int l_height = height(temp->Ln);
	int r_height = height(temp->Rn);
	int max_height = max(l_height, r_height);
	h = max_height + 1;
	}
	return h;
	}

	int balFac(Node* temp) {
	int l_height = height(temp->Ln);
	int r_height = height(temp->Rn);
	int b_factor = l_height - r_height;
	return b_factor;
	}

	Node* rr(Node* root) {
	Node *temp;
	temp = root->Rn;
	root->Rn = temp->Ln;
	temp->Ln = root;
	return temp;
	}

	Node* ll(Node* root) {
	Node *temp;
	temp = root->Ln;
	root->Ln = temp->Rn;
	temp->Rn = root;
	return temp;
	}

	Node* lr(Node* root) {
	Node *temp;
	temp = root->Ln;
	root->Ln = rr(temp);
	return ll(root);
	}

	Node* rl(Node* root) {
	Node *temp;
	temp = root->Ln;
	root->Rn = ll(temp);
	return rr(root);
	}

	Node* balance(Node* root) {
	int bal_factor = balFac(root);
	if (bal_factor > 1) {
	if (balFac(root->Ln) > 0)
	root = ll(root);
	else
	root = lr(root);
	} else if (bal_factor < -1) {
	if (balFac(root->Rn) > 0)
	root = rl(root);
	else
	root = rr(root);
	}
	return root;
	}

	void inorder(Node *root) {
	if (root == NULL)
	return;
	inorder(root->Ln);
	cout << root->key << "  " << root->val<<endl;
	inorder(root->Rn);
	}

	void postorder(Node *root) {
	if (root == NULL)
	return;
	postorder(root->Ln);
	postorder(root->Rn);
	cout << root->key << "  " << root->val<<endl;
	}

	void modify(Node* root, string modKey) {
	string NewMeaning;
	if (modKey.compare(root->key) < 0)
	modify(root->Ln, modKey);
	else if (modKey.compare(root->key) > 0)
	modify(root->Rn, modKey);
	else if (modKey.compare(root->key) == 0) {
	cout << "\nWord Found!\nWord: " << root->key << "\t" << root->val;
	cout << "\nEnter new Meaning : ";
	cin >> NewMeaning;
	root->val = NewMeaning;
	cout << "\nDictionary Modified!";
	}
	}

	void delet(Node* root, string delKey) {
	Node* current = root;
	Node* temp;
	bool isleft = 0;
	while (current != NULL && current->key.compare(delKey) != 0) {
	if (current->key.compare(delKey) > 0) {
	temp = current;
	isleft = 1;
	current = current->Ln;
	} else if (current->key.compare(delKey) < 0) {
	temp = current;
	isleft = 0;
	current = current->Rn;
	}
	}
	if (current->key.compare(delKey) == 0) {
	if (current->Ln == NULL && current->Rn == NULL) {
	if (isleft == 1) {
	temp->Ln = NULL;
	} else
	temp->Rn = NULL;
	} else {
	if (isleft == 1) {
	if (current->Ln == NULL) {
	temp->Ln = current->Rn;
	}

	else if (current->Rn == NULL) {
	temp->Ln = current->Ln;

	}

	else {
	string k = current->Ln->key;
	string v = current->Ln->val;
	temp->Ln = current->Rn;
	insert(root, k, v);
	}
	} else {
	if (current->Ln == NULL) {
	temp->Rn = current->Rn;
	}

	else if (current->Rn == NULL) {
	temp->Rn = current->Ln;
	}

	else {
	string k = current->Ln->key;
	string v = current->Ln->val;
	temp->Rn = current->Rn;
	insert(root, k, v);
	}
	}
	}
	cout << "\nDeleted!";
	} else {
	cout << "\nWord. not found!";
	}
	return;
	}
};
int main() {
    cout<<"USER NAME : NARESH ASHOK MALI ROLL NO : SCOD16\n";
	int choice, dchoice;
	string key, val, modKey, delKey;
	Node *root = new Node();
	Avl avlObj;
	do {
	cout
	<< "\n1. Add word\n2. Delete word\n3. Update word\n4. Display\n5. Exit";
	cin >> choice;
	switch (choice) {
	case 1:
	cout << "\nEnter the word and meaning";
	cin >> key >> val;
	root = avlObj.insert(root, key, val);
	break;
	case 2:
	cout << "\nEnter the word you want to delete : ";
	cin >> delKey;
	avlObj.delet(root, delKey);
	break;
	case 3:
	cout << "\nEnter the word you want to modify : ";
	cin >> modKey;
	avlObj.modify(root, modKey);
	break;
	case 4:
	cout
	<< "\n1.Display in ascending order\n2.Display in descending order";
	cin >> dchoice;
	if (dchoice == 1)
	avlObj.inorder(root);
	else if (dchoice == 2)
	avlObj.postorder(root);
	break;
	case 5:
	break;
	default:
	cout << "\nWrong option. Try again";
	}
	} while (choice != 5);
	return 0;
}

