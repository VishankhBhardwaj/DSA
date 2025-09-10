class Solution {
public:
    string largestOddNumber(string num) {
        int i=0;
        int j=num.size()-1;
        string s;
        while(j>=i){
            if(int(num[j])%2==0){
                j--;
            }
            else{
                break;
            }
        }
        while(i<=j){
            s+=num[i];
            i++;
        }
        return s;
    }
};