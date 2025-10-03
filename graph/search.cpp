#include<iostream>
using namespace std;
#include<queue>
#include<stack>

void BFS(int g[][7],int s,int key) {
    int i = key;
    queue<int> q ;
    int visited[7] = {0};
    cout<<"BFS : "<<i<<" ";
    visited[i] = 1;
    q.push(i);

    while(!q.empty()) {
        i = q.front();
        q.pop();
        for(int j=0; j<s; j++) {
            if(g[i][j] == 1 && visited[j] == 0) {
                cout<<j<<" ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    cout<<endl;
}


void DFS(int g[][7],int s,int key) {
    static int visited[7] = {0};

    if(visited[key] == 0) {
        cout<<key<<" ";
        visited[key] = 1;
        for(int i=0; i<s; i++) {
            if(g[key][i] == 1 && visited[i] == 0) {
                DFS(g,s,i);
            }
        }
    }

}

int main() {
    int graph[7][7] = {
        //0  1  2  3  4  5  6
        {0, 1, 1, 0, 0, 0, 0}, // 0
        {1, 0, 0, 1, 0, 0, 0}, // 1
        {1, 0, 0, 1, 1, 0, 0}, // 2
        {0, 1, 1, 0, 0, 1, 0}, // 3
        {0, 0, 1, 0, 0, 1, 1}, // 4
        {0, 0, 0, 1, 1, 0, 1}, // 5
        {0, 0, 0, 0, 1, 1, 0}  // 6
    };

    DFS(graph,7,1);
    return 0;
}