#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLastWord(string s) {
            int k=0;
            int i=s.length()-1;
            while(i>=0 && s[i]==' '){
                i--;
            }
            while(i>=0 && s[i]!=' '){
                k++;
                i--;
            }
            return k;
        }
    };