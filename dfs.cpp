#include <stdio.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class dfs{
    public:

    vector<int> dfs(TreeNode* root){
        if(root == nullptr) return nullptr;
        vector<vector<int>> ans;

        stack<TreeNode*> st;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();q.pop();
                st.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }

        return ans;

    }
}

void printVector(vector<int>& level){
    for(int i:level){
        cout<<i<<" ";
        endl;
    }
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    dfs solution; 

    vector<int> result = solution.dfs(root); 

    cout << "dfs Traversal of Tree: "<< endl;

    for (const vector<int>& level : result) {
        printVector(level);
    }

    return 0;
}