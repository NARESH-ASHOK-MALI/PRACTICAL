/*
    NAME: NARESH ASHOK MALI ROLL NO: SCOD16

There are flight paths between cities. If there is a flight between
city A and city B then there is an edge between the cities. The cost
of the edge can be the time that flight take to reach city B from A,
or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of
the city. Use adjacency list representation of the graph or use
adjacency matrix representation of the graph. Check whether the
graph is connected or not. Justify the storage representation used.*/ 
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<" NAME : NARESH ASHOK MALI , ROLL NO: SCOD 16 "<<endl;
    int n;
    int avgspeed;
    string city[20];
    int time_matrix[50][50];
    int km_matrix[50][50];
    cout << "Enter the no. of cities : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            time_matrix[i][j] = 0;
            km_matrix[i][j]=0;
        }
    }

    for (int i = 0; i < n; i++){
        cout << "Enter the name of city " << i+1 << ":";
        cin >> city[i];
    }
    cout<<"Enter the average speed of vehicle you may travel with:"<<endl;
    cin>>avgspeed;
    for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
        cout << "Enter the distance from city " << city[i] << " to the " << city[j] << " " << endl;
        cin >> km_matrix[i][j];
        km_matrix[j][i] = km_matrix[i][j];
        time_matrix[i][j]= km_matrix[i][j]/avgspeed;
        time_matrix[j][i] = time_matrix[i][j];

        }
    }
    cout << "\nAdjacency Matrix: of Distances\n\n";
    cout << "\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << km_matrix[i][j] << "\t";
        }
    cout << "\n";
    }
     cout << "\nAdjacency Matrix: of time required :\n\n";
    cout << "\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << time_matrix[i][j] << "\t";
        }
    cout << "\n";
    }
    return 0;

}
