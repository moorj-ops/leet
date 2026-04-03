class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;

        // store reversed words
        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        vector<vector<int>> res;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            for (int j = 0; j <= word.size(); j++) {

                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                // Case 1: prefix palindrome
                if (isPalindrome(word, 0, j - 1)) {
                    if (mp.count(suffix) && mp[suffix] != i) {
                        res.push_back({mp[suffix], i});
                    }
                }

                // Case 2: suffix palindrome
                if (j != word.size() && isPalindrome(word, j, word.size() - 1)) {
                    if (mp.count(prefix) && mp[prefix] != i) {
                        res.push_back({i, mp[prefix]});
                    }
                }
            }
        }

        return res;
    }
};