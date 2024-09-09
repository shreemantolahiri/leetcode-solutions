class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (head != NULL) {
            // move right
            for (int j = left; j <= right; j++) {
                if (head == NULL)
                    break;
                res[top][j] = head->val;

                head = head->next;
            }

            if (head == NULL)
                break;
            top++;

            //move down
            for (int i = top; i <= bottom; i++) {
                if (head == NULL)
                    break;
                res[i][right] = head->val;

                head = head->next;
            }
            if (head == NULL)
                break;
            right--;

            //move left
            for (int j = right; j >= left; j--) {
                if (head == NULL)
                    break;
                res[bottom][j] = head->val;

                head = head->next;
            }
            if (head == NULL)
                break;
            bottom--;

            //moving up
            for (int i = bottom; i >= top; i--) {
                if (head == NULL)
                    break;
                res[i][left] = head->val;

                head = head->next;
            }
            if (head == NULL)
                break;
            left++;
        }

        return res;
    }
};