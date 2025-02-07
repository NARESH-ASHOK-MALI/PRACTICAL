//Represent a given graph using Adjacency matrix to perform DFS 
//& BFS using adjacency list to perform BFS . Use the map of the 
//area around the college as graph. Identify the prominent land 
//marks as nodes and perform DFS & BFS on that
#include<iostream>
#include<string>
using namespace std;
void BFS( int arr[50][50] ,int n ){ 
    int front=0;
    int rear=0;
    int visited[n];
    int queue[2*n];
    for (int i = 0; i <= n; i++){
        visited[i]=0;
    }
    queue[rear]=0;
    visited[0]=1;
    rear++;
    while ( front != rear ){
        int node=queue[front];
        front++;
        cout<<node+1<<" ";
        for (int i = 0; i < n; i++){
            if ( arr[node][i] == 1 && visited[i] == 0 ){
                queue[rear]=i;
                rear++;
                visited[i]=1;
            }
        }
    }
}
void DFS(int arr[50][50], int n) {
    int visited[n] = {0}; 
    int stack[50];       
    int top = -1;

    stack[++top] = 0;      
    while (top != -1) {
        int node = stack[top--]; 

        if (!visited[node]) {
            visited[node] = 1;
            cout << node + 1 << " "; 
            for (int i = n - 1; i >= 0; i--) {
                if (arr[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
int main(){
    cout<<"Name : Naresh Ashok Mali Roll No: SCOD16 "<<endl;
    int n;
    int ch;
    string node[20];
    int adj_matrix[50][50];
    cout << "Enter the no. of nodes : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j]=0;
        }
    }

    for (int i = 0; i < n; i++){
        cout << "Enter the name of node " << i+1 << ":";
        cin >> node[i];
    }
    for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
        cout << "Enter 1 if there is edge  from " << node[i] << " to " << node[j] << " " << endl;
        cin >> adj_matrix[i][j];
        adj_matrix[j][i] = adj_matrix[i][j];
        }
    }
    do{
        cout << "\nAdjacency Matrix:\n\n";
        cout << "\t";
        for (int i = 0; i < n; i++) {
            cout << node[i] << "\t";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << node[i] << "\t";
            for (int j = 0; j < n; j++) {
                cout << adj_matrix[i][j] << "\t";
            }
            cout << "\n";
        }
        cout<<"--------------------------------------------"<<endl;
        cout<<"|MENU                                      |"<<endl;
        cout<<"|Press 1 For to perform BFS Operation      |"<<endl;    
        cout<<"|Press 2 For to perform DFS Operation      |"<<endl;      
        cout<<"|Press 3 to perform Exit                   |"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cin>>ch;      
        switch ( ch )
        {
        case  1  :
            cout<<"BFS Traversal: ";
            BFS(adj_matrix,n);
            break;
        case  2  :
            cout<<"DFS Traversal: ";
            DFS(adj_matrix,n);
            break;
        default:
            break;
        }
        } while ( ch !=3);
   
    return 0;

}
