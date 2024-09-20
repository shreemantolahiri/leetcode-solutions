class Solution {
private:
    void buildAdj(TreeNode* &root, unordered_map<int, vector<int>>& adj) {
        if (root == NULL)
            return;

        // curr node
        int curr = root->val;
        if (root->left != NULL) {
            adj[curr].push_back(root->left->val);
            adj[root->left->val].push_back(curr);
        }
        if (root->right != NULL) {
            adj[curr].push_back(root->right->val);
            adj[root->right->val].push_back(curr);
        }
        // traverse the tree
        buildAdj(root->left, adj);
        buildAdj(root->right, adj);
    };

    int maximumHeight(int parent,int node, unordered_map<int, vector<int>>& adj) {
        
        int height=1;

        for(auto it:adj[node]){
            if(it!=parent){
                height=max(height,1+maximumHeight(node,it,adj));
            }
        }

        return height;
        
    };

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;

        // build the adj list
        buildAdj(root, adj);

        // perform BFS and find out number of levels
        return maximumHeight(-1,start, adj)-1;
    }
};