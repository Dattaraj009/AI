#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSafe(int node, int color, vector<int>& colors,
            vector<vector<int>>& adj, int n) {
    for (int neighbor : adj[node]) {
        if (colors[neighbor] == color) return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>>& adj,vector<int>& colors,int m,int n){

    if(node == n) return true;

    for (int c = 1;c <= m; c++){
        if(isSafe(node))
    }
    {
        /* code */
    }
    
}