#include <iostream>
#include <string>
using namespace std;
class telephone
{
private:
    long long int key;
    int Hash_address;
    int x;
    long long int Telephone[10];
    string Name[10];
public:
    telephone(){
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
                while ((Hash_address + i) <= 10 ) {
                    i++;
                    if ((Hash_address+i-1)==10){
                    for ( int j = 0; j < Hash_address; j++){
                    if (Telephone[j]=-1){
                        Telephone[j] = key;
                        cout << "ENTER NAME OF CLIENT.1" << endl;
                        cin >> Name[j];
                        break;
                    }else {
                    cout << "NO SPACE AVAILABLE FOR THIS TELEPHONE NUMBER." << endl;
                    }
                   }
                }
                if ((Hash_address + i) < 10) {
                    Telephone[Hash_address + i] = key;
                    cout << "ENTER NAME OF CLIENT.2" << endl;
                    cin >> Name[Hash_address + i];
                } else {
                    cout << "NO SPACE AVAILABLE FOR THIS TELEPHONE NUMBER." << endl;
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
int main(){
    telephone t;
    t.insert_lp();
    cout<<"displaying the result"<<endl;
    t.Display();
}
