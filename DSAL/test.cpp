
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string city[20];
    int adj_matrix[50][50];
    cout << "Enter the no. of cities : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        cout << "Enter the name of city " << i+1 << ":";
        cin >> city[i];
    }
    for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
        cout << "Enter the time required to travel from city " << city[i] << " to the " << city[j] << " " << endl;
        cin >> adj_matrix[i][j];
        adj_matrix[j][i] = adj_matrix[i][j];
        }
    }
    cout << "\nAdjacency Matrix:\n\n";
    cout << "   ";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << "\t";
        }
    cout << "\n";
    }
    return 0;

}
