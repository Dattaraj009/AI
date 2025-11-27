#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> soln;
void solve(int col,int n,vector<int>& lastrow,vector<string>& board,vector<int>& lowerdiag,vector<int> upperdiag){
    if(col == n){
        soln.push_back(board);
        return;
    }
    
    for(int row=0;row<n;row++){
        
        if(lastrow[row]==0 && lowerdiag[row+col] == 0 && upperdiag[n-1 + col - row] == 0){
            lastrow[row] = 1;
            lowerdiag[row+col] = 1;
            upperdiag[n-1 + col- row] = 1;
            board[row][col] = 'Q';
            
            solve(col+1,n,lastrow,board,lowerdiag,upperdiag);
            lastrow[row] = 0;
            lowerdiag[row+col] = 0;
            upperdiag[n-1 + col- row] = 0;
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4;
    
    vector<int> lastrow(n,0);
    vector<string> board(n,string(n,'.'));
    vector<int> lowerdiag(2*n-1,0);
    vector<int> upperdiag(2*n-1,0);
    
    solve(0,n,lastrow,board,lowerdiag,upperdiag);
    
    for(int i=0;i<soln.size();i++){
        
        for(int j=0;j<soln[0].size();j++){
            cout<<soln[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    
}