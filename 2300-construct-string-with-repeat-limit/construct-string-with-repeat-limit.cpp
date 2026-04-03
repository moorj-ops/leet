class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";

        int i = 25; // start from 'z'

        while (i >= 0) {
            if (freq[i] == 0) {
                i--;
                continue;
            }

            int use = min(freq[i], repeatLimit);

            // add current char
            for (int k = 0; k < use; k++) {
                result += (char)(i + 'a');
            }

            freq[i] -= use;

            // if still remaining, need breaker
            if (freq[i] > 0) {
                int j = i - 1;

                // find next smaller character
                while (j >= 0 && freq[j] == 0) j--;

                if (j < 0) break; // no smaller char available

                result += (char)(j + 'a');
                freq[j]--;
            }
        }

        return result;
    }
};