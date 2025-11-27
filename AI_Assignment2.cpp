#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node,int n,bool graph[101][101],int color[],int c){
    for(int k=0;k<n;k++){
        if(graph[k][node] == 1 && color[k] == c){
            return false;
        }
    }
    
    return true;
}

bool dfs(int node,int n,int m,bool graph[101][101],int color[]){
    if (node == n) return true;
    
    for(int i=1;i<=m;i++){
        if(isSafe(node,n,graph,color,i)){
            color[node] = i;
           if(dfs(node+1,n,m,graph,color)) return true;
           color[node] = 0; // backtrack
        }
        
    }
    
    return false;
}

bool solve(bool graph[101][101],int n,int m,int color[]){
    if(dfs(0,n,m,graph,color)) return true;
    
    return false;
}

int main(){
    int n=4;
    int m=3;
    
    bool graph[101][101] = {0};
    
    graph[0][1] = graph[1][0] =1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;
    
    int color[n] = {0};
    
    if (solve(graph, n, m, color)) {
        cout << "true\n";
        cout << "Coloring: ";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << " -> Color " << color[i] << "\n";
        }
    } else {
        cout << "false\n";
    }

    
    return 0;
}