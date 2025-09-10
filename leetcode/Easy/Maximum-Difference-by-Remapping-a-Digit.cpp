class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string max="";
        string min="";
        int n=str.size();
        char element=' ';
        char zeroele=' ';
        for(int i=0;i<n;i++){
            if(str[i]!='9'){
                element=str[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(str[i]==element){
                max+='9';
            }
            else{
                max+=str[i];
            }
        }
        for(int i=0;i<n;i++){
            if(str[i]!='0'){
                zeroele=str[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(str[i]==zeroele){
                min+='0';
            }
            else{
                min+=str[i];
            }
        }
        return stoi(max) - stoi(min);
    }
};