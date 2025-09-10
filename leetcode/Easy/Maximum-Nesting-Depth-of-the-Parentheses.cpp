class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;        
        int maxcnt = 0;     
        
        for(auto i : s) {
            if(i == '(') {
                cnt++;
                if(cnt > maxcnt) maxcnt = cnt;
            } else if(i == ')') {
                cnt--;
            }
        }
        return maxcnt;
    }
};