

class Solution {
public:

    // Next Smaller Element (Right)
    vector<int> nextSmallestElement(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }

    // Previous Smaller Element (Left)
    vector<int> prevSmallestElement(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallestElement(heights);
        vector<int> prev = prevSmallestElement(heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int height = heights[i];

            // if no smaller on right
            if(next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};