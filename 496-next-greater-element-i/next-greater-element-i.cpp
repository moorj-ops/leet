class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
    
    unordered_map<int,int> mp;
    stack<int> st;

    for(int num :nums2) {
        // remove smaller elements
        while(!st.empty() && st.top() < num) {
            mp[st.top()]=num;
            st.pop();
        }
        // if agar greater element nahi hai toh bhi push kardo 
        st.push(num);

    }
    //agar stack empty nahi hai but large element bhi nahi mila hai toh baad meh stack empty karne ke liye -1 dalo 
    while (!st.empty()){
        mp[st.top()]=-1;
        st.pop();
    }

    vector<int> ans;
    for(int num : nums1) {
        ans.push_back(mp[num]);
    }

    return ans;

    }
};