/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void bfs(Node* node){
        unordered_set<Node*> st;
        queue<Node*> q;
        q.push(node);
        st.insert(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            cout<<curr->val<<endl;
            for(Node* it:curr->neighbors){
                if(st.count(it)>0) continue;
                else{
                    st.insert(it);
                    q.push(it);
                }
            }
        }

        return;
    }
    Node* solve(Node* node, unordered_map<int,Node*> &mp){
        queue<Node*> q;
        q.push(node);
        Node* newRoot=NULL;
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            int v=curr->val;
            if(mp.find(v)==mp.end()){
                Node* temp=new Node(v);
                mp[v]=temp;
                if(newRoot==NULL) newRoot=temp;
            }
            Node* newCurr=mp[v];
            //check all its neighbours
            for(Node* it:curr->neighbors){
                int itVal=it->val;
                if(mp.find(itVal)==mp.end()){
                    Node* newNode=new Node(itVal);
                    mp[itVal]=newNode;
                    q.push(it); //as not visited
                }
                Node* newNode=mp[itVal];
                (newCurr->neighbors).push_back(newNode);
            }
        }
        cout<<node<<" "<<newRoot<<endl;
        return newRoot;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            Node* temp=NULL;
            return temp;
        }
        unordered_map<int,Node*> mp;
        
        Node* newRoot= solve(node,mp);
        // cout<<"***"<<endl;
        // bfs(node);
        // cout<<"***"<<endl;
        // bfs(newRoot);

        return newRoot;
    }
};