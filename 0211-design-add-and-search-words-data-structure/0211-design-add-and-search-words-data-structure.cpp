class TrieNode{
    //a-z and "."
    public:
    TrieNode* dict[26];
    int wordEnd=0;
    TrieNode(){
        for(int i=0;i<26;i++) dict[i]=NULL;
    }
    bool doesContain(char ch){
            int index=ch-'a';
            return dict[index]!=NULL;
        
    }
    TrieNode* get(char ch){
            int index=ch-'a';
            return dict[index];
        
    }

    TrieNode* insertNode(char ch){
        int index=ch-'a';

        TrieNode* temp=new TrieNode();
        dict[index]=temp;
        return temp;
    }

};
class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp=root;
        for(char ch:word){
            if(temp->doesContain(ch)){
                temp=temp->get(ch);
            }
            else{
                temp=temp->insertNode(ch);
            }
        }

        temp->wordEnd++;
    }
    bool searchString(int ind,string &word,TrieNode *temp){
        if(ind==word.length()){
            return temp->wordEnd;
        }

        //if dot
        if(word[ind]=='.'){
            bool ans=false;
            // TrieNode* curr=temp;
            for(char ch='a';ch<='z';ch++){
                if(temp->doesContain(ch)){
                    ans=ans || searchString(ind+1,word,temp->get(ch));
                }
            }

            return ans;
        }
        else{
            //single character
            char ch=word[ind];
            if(!temp->doesContain(ch)) return false;
            return searchString(ind+1,word,temp->get(ch));
        }
    }
    bool search(string word) {
        return searchString(0,word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */