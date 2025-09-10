class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char, int> mpp;

        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            mpp[s[j]]++;
            maxFreq = max(maxFreq, mpp[s[j]]);
            if ((j - i + 1) - maxFreq > k) {
                mpp[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};