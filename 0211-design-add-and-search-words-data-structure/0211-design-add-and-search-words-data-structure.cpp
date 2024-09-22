class TrieNode {
public:
    TrieNode* dict[26];  // Stores pointers to child TrieNodes for 'a' to 'z'
    int wordEnd = 0;     // Indicates how many words end at this node

    TrieNode() {
        // Initialize all children to NULL
        for (int i = 0; i < 26; i++)
            dict[i] = NULL;
    }

    // Check if the character exists in the current TrieNode
    bool doesContain(char ch) {
        int index = ch - 'a';
        return dict[index] != NULL;
    }

    // Get the TrieNode for the given character
    TrieNode* get(char ch) {
        int index = ch - 'a';
        return dict[index];
    }

    // Insert a new TrieNode for the given character
    TrieNode* insertNode(char ch) {
        int index = ch - 'a';
        TrieNode* temp = new TrieNode();
        dict[index] = temp;
        return temp;
    }
};

class WordDictionary {
public:
    TrieNode* root;  // Root of the Trie

    WordDictionary() {
        root = new TrieNode();  // Initialize root
    }

    // Add a word to the Trie
    void addWord(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            if (temp->doesContain(ch)) {
                // Move to the next TrieNode
                temp = temp->get(ch);
            } else {
                // Insert a new TrieNode
                temp = temp->insertNode(ch);
            }
        }
        temp->wordEnd++;  // Mark the end of a word
    }

    // Helper function to search the word recursively
    bool searchString(int ind, string& word, TrieNode* temp) {
        // Base case: If at the end of the word, check if it's valid
        if (ind == word.length()) {
            return temp->wordEnd > 0;
        }

        // Handle the '.' character (wildcard)
        if (word[ind] == '.') {
            bool ans = false;
            // Try all possible characters from 'a' to 'z'
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (temp->doesContain(ch)) {
                    // Recursively search for the next character
                    ans = ans || searchString(ind + 1, word, temp->get(ch));
                }
            }
            return ans;
        } else {
            // Handle normal character search
            char ch = word[ind];
            if (!temp->doesContain(ch))
                return false;  // Character not found in Trie
            return searchString(ind + 1, word, temp->get(ch));
        }
    }

    // Public function to search a word (supports '.' wildcard)
    bool search(string word) {
        return searchString(0, word, root);  // Start search from root
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
