class Solution {
public:
    int possibleStringCount(string word) {
         if (word.empty()) return 0;

        int groupCount = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] != word[i - 1]) {
                groupCount++;
            }
        }

        int sum = word.size();
        return (sum - groupCount + 1);
    }
};