class Solution {
public:
    bool matchSentence(vector<string>& words1, vector<string>& words2) {

        int n = words1.size();
        int m = words2.size();
        int left = 0, right = n - 1;
        int i = 0, j = m - 1;

        while (i <= j && left <= right) {
            if (words1[left] == words2[i]) {
                i++;
                left++;
            } else if (words1[right] == words2[j]) {
                right--;
                j--;
            } else
                return false;
        }
        return true;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1;
        vector<string> words2;
        stringstream ss(sentence1);
        string word;

        while (ss >> word) {
            words1.push_back(word);
        }
        stringstream ss2(sentence2);
        string word2;

        while (ss2 >> word2) {
            words2.push_back(word2);
        }

        return matchSentence(words1, words2);
    }
};