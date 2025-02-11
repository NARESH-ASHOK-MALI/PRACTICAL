/* 
NAME: Naresh Ashok Mali SCOD16
Problem Statement: Consider telephone book Database of n client make use of
hashtable implemetation to quickly lookup client telephone number make use
of 2 collision handling technique and compare them using number of
comparision require to find a set of telephone number.
*/ 
#include <iostream>
#include <string>
using namespace std;
class telephone {
private:
    unsigned long long int key;
    int Hash_address;
    int x;
    long long int Telephone[10];
    string Name[10];
public:
    telephone() {
        for (int i = 0; i < 10; i++) {
            Telephone[i] = -1;
            Name[i] = "NOT ASSIGNED";
        }
    }
    void insert_lp() {
        cout << "ENTER NUMBER OF CLIENTS YOU WANT IN TELEPHONE BOOK." << endl;
        cin >> x;
        for (int count = 0; count < x; count++) {
            cout << "ENTER TELEPHONE NUMBER." << endl;
            cin >> key;
            Hash_address = key % 10;
            if (Telephone[Hash_address] == -1) {
                Telephone[Hash_address] = key;
                cout << "ENTER NAME OF CLIENT." << endl;
                cin >> Name[Hash_address];
            } else { // Linear Probing
                int i = 1;
                bool flag = false;
                while ((Hash_address + i) < 10 && Telephone[Hash_address + i] != -1) {
                    i++;
                }
                if ((Hash_address + i) < 10) {
                    Telephone[Hash_address + i] = key;
                    cout << "ENTER NAME OF CLIENT." << endl;
                    cin >> Name[Hash_address + i];
                    flag = true;
                }else if (flag == false){
                        for (int i = 0; i < Hash_address; i++){
                            if (Telephone[i] == -1){
                                Telephone[i] = key;
                                cout << "ENTER NAME OF CLIENT." << endl;
                                cin >> Name[i];
                                break;
                            } else if (i == Hash_address - 1){
                                cout << "NO SPACE AVAILABLE FOR THIS TELEPHONE NUMBER." << endl;
                            }
                        }
                }
            }
        }
    }
    void insert_Qp() {
        cout << "ENTER NUMBER OF CLIENTS YOU WANT IN TELEPHONE BOOK." << endl;
        cin >> x;
        for (int count = 0; count < x; count++) {
            cout << "ENTER TELEPHONE NUMBER." << endl;
            cin >> key;
            Hash_address = key % 10;
            if (Telephone[Hash_address] == -1) {
                Telephone[Hash_address] = key;
                cout << "ENTER NAME OF CLIENT." << endl;
                cin >> Name[Hash_address];
            } else { // Quadratic Probing
                int i = 1;
                Hash_address =Hash_address + (i*i);
                while (Telephone[Hash_address]<10){
                    if (Telephone[Hash_address]==-1){
                        Telephone[Hash_address]=key;
                        cout<<"ENTER NAME OF CLIENT."<<endl;
                        cin>>Name[Hash_address];
                        break;
                    }else if(Telephone[Hash_address]!=-1){
                        i++;
                        Hash_address=Hash_address+(i*i);
                    }       
                }  
            }
        }
    }
    void Display() {
        for (int i = 0; i < 10; i++) {
            cout << i+1 << "  >>  " << Name[i] << "  >>  " << Telephone[i] << endl;
        }
    }
};
int main() {
    cout<<"Program Executor is: Naresh Ashok Mali Roll No:SCOD16"<<endl;
    telephone t;
    int choice;
    do {
        cout << "<------------Enter Choice----------->" << endl;
        cout << "|  1.Insert using Linear Probing    |" << endl;
        cout << "|  2.Insert using Quadratic Probing |" << endl;
        cout << "|  3.Display                        |" << endl;
        cout << "|  4.Exit                           |" << endl;
        cout << "<----------------------------------->" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            t.insert_lp();
            break;
        case 2:
            t.insert_Qp();
            break;
        case 3:
            t.Display();
            break;
        case 4:
            break;
        default:
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
        }
    } while (choice != 4);
    return 0;
}
