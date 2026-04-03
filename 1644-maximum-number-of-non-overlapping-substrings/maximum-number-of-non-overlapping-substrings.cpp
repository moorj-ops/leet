class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, n), end(26, -1);

        // Step 1: first & last occurrence
        for (int i = 0; i < n; i++) {
            start[s[i] - 'a'] = min(start[s[i] - 'a'], i);
            end[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        // Step 2: build valid intervals
        for (int i = 0; i < n; i++) {
            if (i != start[s[i] - 'a']) continue;

            int l = i, r = end[s[i] - 'a'];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                if (start[s[j] - 'a'] < l) {
                    valid = false;
                    break;
                }
                r = max(r, end[s[j] - 'a']);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Step 3: greedy selection
        vector<string> result;
        int prevEnd = -1;

        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                result.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            } else {
                // replace if smaller
                if (!result.empty() && r < prevEnd) {
                    result.back() = s.substr(l, r - l + 1);
                    prevEnd = r;
                }
            }
        }

        return result;
    }
};