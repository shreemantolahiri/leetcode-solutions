class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> mp;

        stack<pair<TreeNode*,int>> st;

        st.push({root,0});
        // int level=1;
        while(!st.empty()){
            TreeNode* curr=st.top().first;
            int level=st.top().second;
            st.pop();

            if(curr->left) {
                mp[level+1]+=curr->left->val;
                st.push({curr->left,level+1});
                }
            if(curr->right) {
                mp[level+1]+=curr->right->val;
                st.push({curr->right,level+1});
                }
            // level++;
        }
        //one dfs done

        for(auto it:mp){
            cout<< it.first<<" "<<it.second<<endl;
        }

        // level=1;
        root->val=0;
        st.push({root,0});
        while(!st.empty()){
            //we check if left and right both exist
            TreeNode* curr=st.top().first;
            int level=st.top().second;
            st.pop();

            if(curr->left && curr->right){
                int sum=curr->left->val+curr->right->val;
                int levelSum=mp[level+1];
                curr->left->val=levelSum-sum;
                curr->right->val=levelSum-sum;
            }
            //just one child
            else{
                int levelSum=mp[level+1];
                if(curr->left) curr->left->val=levelSum-curr->left->val;
                if(curr->right) curr->right->val=levelSum-curr->right->val;
            }
            if(curr->left) st.push({curr->left,level+1});
            if(curr->right) st.push({curr->right,level+1});
            // level++;
        }

        return root;
    }
};