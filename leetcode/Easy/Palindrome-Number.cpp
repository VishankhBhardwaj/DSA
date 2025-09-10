class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string number=to_string(x);
        int i=0;
        int j=number.size()-1;
        while(i<j){
            if(number[i]!=number[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};