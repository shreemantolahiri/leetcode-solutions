class Solution {
public:
    void populateMap(TreeNode* &root,unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL) return;

        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;

        populateMap(root->left,mp);
        populateMap(root->right,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_set<TreeNode*> vis;
        //now we have parent pointers
        populateMap(root,mp);

        vector<int> res;

        //we use BFS to go till k levels
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        int lvl=0;
        while(!q.empty()){
            if(lvl>k) break;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                if(lvl==k) res.push_back(curr->val);
                q.pop();
                //check left,right and parent
                if(curr->left && vis.find(curr->left)==vis.end()){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && vis.find(curr->right)==vis.end()){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(mp.find(curr)!=mp.end() && vis.find(mp[curr])==vis.end()){
                    q.push(mp[curr]);
                    vis.insert(mp[curr]);
                }
            }
            lvl++;
        }

        return res;
    }
};