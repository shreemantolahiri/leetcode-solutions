/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<TreeNode*> leaves;
    int bfs(TreeNode* &node, int dist,
    unordered_map<TreeNode*, unordered_set<TreeNode*>>& mp) {
        queue<pair<TreeNode*, TreeNode*>> q;
        // cout<<"BFS: "<<node->val<<endl;
        q.push({NULL, node});
        int lvl = 0;
        int count = 0;
        while (!q.empty()) {
            int siz = q.size();
            if (lvl > dist)
                break;
            for (int i = 0; i < siz; i++) {
                TreeNode* curr = q.front().second;
                TreeNode* par = q.front().first;
                // cout<<curr->val<<endl;
                q.pop();
                if (curr != node && leaves.count(curr) > 0)
                    count++;

                for (auto it : mp[curr]) {
                    if (it != par) {
                        q.push({curr, it});
                    }
                }
            }
            lvl++;
        }

        return count;
    }
    void buildGraph(TreeNode* &par, TreeNode* &child,
                    unordered_map<TreeNode*, unordered_set<TreeNode*>>& mp) {
        if (child == NULL)
            return;
        if (child->left == NULL && child->right == NULL)
            leaves.insert(child);
        if (par != NULL) {
            mp[child].insert(par);
        }

        if (child->left) {
            mp[child].insert(child->left);
        }
        if (child->right) {
            mp[child].insert(child->right);
        }

        buildGraph(child, child->left, mp);
        buildGraph(child, child->right, mp);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, unordered_set<TreeNode*>> mp;
        // add all nodes along with parent
        TreeNode* par = NULL;
        TreeNode* child = root;
        buildGraph(par,child,mp);

        // perform dfs from 3
        int count = 0;
        for (TreeNode* it : leaves) {
            count += bfs(it, distance,mp);
        }

        return count / 2;
    }
};