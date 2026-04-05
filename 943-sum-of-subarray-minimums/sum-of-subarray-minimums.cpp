class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int MOD = 1e9 + 7;
        
        // Arrays to store indices of previous and next smaller elements
        vector<int> pse(n, -1); 
        vector<int> nse(n, n);
        stack<int> st;

        // Find Previous Smaller Element (PSE) indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        // Clear stack for next use
        while(!st.empty()) st.pop();

        // Find Next Smaller Element (NSE) indices
        // Note: Using >= here to handle duplicate elements correctly
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            long long left_dist = i - pse[i];
            long long right_dist = nse[i] - i;
            
            // Total subarrays where arr[i] is minimum = left_dist * right_dist
            long long contribution = (left_dist * right_dist) % MOD;
            contribution = (contribution * arr[i]) % MOD;
            
            sum = (sum + contribution) % MOD;
        }

        return (int)sum;
    }
};