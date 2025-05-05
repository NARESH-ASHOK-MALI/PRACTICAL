#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


int dfs(vector<vector<int>> graph,int start) {
    int n=graph.size();
    vector<int> visited(n,0);

    stack<int> s;
    s.push(start);
    cout<<"DFS of graph is: ";
    while(!s.empty()) {
        int current=s.top();
        s.pop();

        if(visited[current]==0) {
            cout<<current<<" ";
            visited[current] = 1;
        }
        for(int i=0;i<n;i++) {
            if (graph[current][i] == 1 && visited[i] == 0){
                s.push(i);
            }
        }
    }
}

int bfs(vector<vector<int>> graph,int start) {
    int n=graph.size();
    vector<int> visited(n,0);

    queue<int> q;
    q.push(start);
    cout << "BFS of graph is: ";
    while(!q.empty()) {
        int current=q.front();
        q.pop();

        if(visited[current]==0) {
            cout<<current<<" ";
            visited[current] = 1;
        }
        for(auto i:graph[current]) {
            if (visited[i] == 0){
                q.push(i);
            }
        }
    }
}




int main(){

    vector<vector<int>> matrixGraph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
    };

    vector<vector<int>> listGraph={
        {1,2},
        {0,2,3},
        {0,1,3},
        {1,2,4},
        {3}
    };

    bfs(listGraph,0);

    return 0;
}