class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // store indices

    for(int i = 2*n - 1; i >= 0; i--) {
        int idx = i % n;
        //stack me jab tak chota element hai pop 
        while(!st.empty() && nums[st.top()] <= nums[idx]) {
            st.pop();
        }

        if(i < n) {
            if(!st.empty()) {
                res[idx] = nums[st.top()];
            }
        }
        //we are putting the index in stack
        st.push(idx);
    }

    return res;
    }
};