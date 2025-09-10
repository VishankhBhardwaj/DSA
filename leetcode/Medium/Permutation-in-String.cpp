class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int>s1Map(26,0),s2Map(26,0);
        for(auto c:s1){
            s1Map[c-'a']++;
        }
        int window = s1.length();
        for(int i=0;i<s2.length();i++){
            s2Map[s2[i] - 'a']++;
            if(i>=window){
                s2Map[s2[i-window]-'a']--;
            }
            if(s1Map==s2Map) return true;
        }
        return false;
    }
};