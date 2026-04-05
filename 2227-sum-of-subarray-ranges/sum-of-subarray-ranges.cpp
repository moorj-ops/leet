class Solution {
public:

    //  Sum of Subarray Minimums
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        //prev ke lye default -1 
        //nse ke liy edefaukt le rah ehai n
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum += left * right * arr[i];
        }

        return sum;
    }

    // Sum of Subarray Maximums
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> pge(n, -1), nge(n, n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum += left * right * arr[i];
        }

        return sum;
    }

    // Final Answer
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};