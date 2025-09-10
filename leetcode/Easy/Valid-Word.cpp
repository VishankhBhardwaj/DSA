class Solution {
public:
    bool isValid(string word) {
        int vowels = 0, consonants = 0;
        if(word.size()<3) return false;
        for (char ch : word) {
            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' ||
                    lower == 'o' || lower == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (isdigit(ch)) {
                continue;
            } else {
                return false;
            }
        }

        if (vowels == 0 || consonants == 0)
            return false;
        return true;
    }
};