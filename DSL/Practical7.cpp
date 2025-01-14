// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
//  of second, third and final year of department can be granted membership on request.
//  Similarly one may cancel the membership of club. First node is reserved for president of
//  club and last node is reserved for secretary of club. Write C++ program to maintain club
//  member‘s information using singly linked list. Store student PRN and Name. Write
//  functions to:
// Addanddeletethemembersaswellaspresidentorevensecretary.
//  Computetotalnumberofmembersofclub
//  Displaymembers
//  Two linkedlists exists for two divisions.Concatenate two lists
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int prn;
    Node* next;

    Node(string name, int prn) : name(name), prn(prn), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() : head(nullptr) {}

    // Add a member (general member, president, or secretary)
    void addMember(string name, int prn, string position = "member") {
        Node* newNode = new Node(name, prn);

        if (position == "president") {
            newNode->next = head;
            head = newNode;
            cout << "President added: " << name << endl;
        } else if (position == "secretary") {
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Secretary added: " << name << endl;
        } else {
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Member added: " << name << endl;
        }
    }

    // Delete a member (general member, president, or secretary)
    void deleteMember(string position = "member") {
        if (!head) {
            cout << "The club is empty!" << endl;
            return;
        }

        if (position == "president") {
            Node* temp = head;
            head = head->next;
            cout << "President removed: " << temp->name << endl;
            delete temp;
        } else if (position == "secretary") {
            if (!head->next) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next && temp->next->next) {
                    temp = temp->next;
                }
                Node* toDelete = temp->next;
                temp->next = nullptr;
                cout << "Secretary removed: " << toDelete->name << endl;
                delete toDelete;
            }
        } else {
            cout << "Enter PRN of member to remove: ";
            int prn;
            cin >> prn;

            Node* temp = head;
            Node* prev = nullptr;
            while (temp && temp->prn != prn) {
                prev = temp;
                temp = temp->next;
            }

            if (!temp) {
                cout << "Member not found!" << endl;
                return;
            }

            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }

            cout << "Member removed: " << temp->name << endl;
            delete temp;
        }
    }

    // Compute the total number of members
    int countMembers() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display all members
    void displayMembers() const {
        if (!head) {
            cout << "The club is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Club Members:" << endl;
        while (temp) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        other.head = nullptr; // Clear the other list
        cout << "Lists concatenated!" << endl;
    }
};

int main() {
    PinnacleClub divisionA, divisionB;

    // Add members to Division A
    divisionA.addMember("Alice", 101, "president");
    divisionA.addMember("Bob", 102);
    divisionA.addMember("Charlie", 103);
    divisionA.addMember("Daisy", 104, "secretary");

    // Add members to Division B
    divisionB.addMember("Eve", 201, "president");
    divisionB.addMember("Frank", 202);
    divisionB.addMember("Grace", 203, "secretary");

    // Display members of both divisions
    cout << "\nDivision A Members:" << endl;
    divisionA.displayMembers();
    cout << "\nDivision B Members:" << endl;
    divisionB.displayMembers();

    // Concatenate Division B into Division A
    divisionA.concatenate(divisionB);

    // Display members after concatenation
    cout << "\nAfter concatenation:" << endl;
    divisionA.displayMembers();

    // Count members
    cout << "\nTotal members in the club: " << divisionA.countMembers() << endl;

    // Delete president
    divisionA.deleteMember("president");

    // Delete secretary
    divisionA.deleteMember("secretary");

    // Display members after deletions
    cout << "\nAfter deletions:" << endl;
    divisionA.displayMembers();

    return 0;
}
