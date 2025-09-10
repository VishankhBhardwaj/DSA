class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> tMap;
        for (char c : t)
            tMap[c]++;

        int required = t.size();
        int count = 0;
        int i = 0, minLen = INT_MAX, startIndex = 0;

        for (int j = 0; j < s.size(); j++) {
            if (tMap[s[j]] > 0)
                count++;
            tMap[s[j]]--;
            while (count == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIndex = i;
                }

                tMap[s[i]]++;
                if (tMap[s[i]] > 0)
                    count--;
                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};