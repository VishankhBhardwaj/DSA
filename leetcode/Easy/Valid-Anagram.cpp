class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int>v(26,0);
            //base condition
            if(s.length()!=t.length()){
                return false;
            }
            for(int i=0;i<s.length();i++){
                v[s[i]-'a']++;
            }
            for(int i=0;i<t.length();i++){
                v[t[i]-'a']--;
            }
             return all_of(v.begin(), v.end(), [](int x) { return x == 0; });
        }
    };