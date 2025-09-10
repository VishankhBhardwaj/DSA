class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto i : s) {
            freq[i]++;
        }
        vector<pair<char, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second; // Compare frequencies
             });
        string result = "";
        for (auto& p : vec) {
            char ch = p.first;
            int count = p.second;

            // Add character 'count' times to result
            for (int i = 0; i < count; i++) {
                result += ch;
            }
        }
        return result;
    }
};