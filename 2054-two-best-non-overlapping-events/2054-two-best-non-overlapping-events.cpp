class Solution {
public:

    static bool customS(vector<int> &a, vector<int> &b) {
        // if(a[1]!=b[1]) return a[1]<b[1];

        // else if(a[0]!=b[0]) return a[0]<b[0];

        // else return a[2]<b[2];
        return a[0]<b[0];
    }
    
    bool checkOverlap(vector<int> &a, vector<int> &b) {
        return a[1] >= b[0]; // Two intervals overlap if the end of one is >= start of the other.
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort the events by the ending time.
        sort(events.begin(), events.end(), customS);

        int n = events.size();
        vector<int> maxSuffix(n, 0);
        
        // Build the suffix array storing the maximum cost from the current position to the end.
        maxSuffix[n-1] = events[n-1][2]; // The last event's value is the suffix max for itself.
        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(maxSuffix[i + 1], events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // Assume the current interval is picked.
            int cost = events[i][2];
            ans=max(ans,cost);
            // cout<<events[i][0]<<" "<<events[i][1]<<" "<<cost<<endl;
            // Find the first non-overlapping interval using binary search.
            int left = i + 1, right = n - 1, bestIdx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) { // Non-overlapping
                    bestIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            // Add the maximum cost from the suffix array if a valid non-overlapping interval exists.
            if (bestIdx != -1) {
                cost += maxSuffix[bestIdx];
            }
            
            // Update the answer.
            ans = max(ans, cost);
        }

        return ans;
    }
};
