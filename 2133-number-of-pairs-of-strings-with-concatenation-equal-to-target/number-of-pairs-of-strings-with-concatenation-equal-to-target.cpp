class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;

        // frequency map
        for (auto &s : nums) {
            mp[s]++;
        }

        int count = 0;

        for (auto &s : nums) {
            int len = s.length();

            // check prefix
            if (target.substr(0, len) == s) {
                string suffix = target.substr(len);

                count += mp[suffix];

                // avoid i == j case
                if (suffix == s) {
                    count--;
                }
            }
        }

        return count;
    }
};