class Solution {
public:
    int romanToInt(string s) {
        int t=0;
        for(int i=0;s[i]!='\0';i++)
        {
            switch(s[i]){
                case 'V':t=t+5;
                        break;
                case 'X':
                if(s[i+1]=='L'){
                t=t+40;
                i++;}
                else if(s[i+1]=='C'){
                    t=t+90;
                    i++;
                }
                else{
                    t=t+10;
                }
                break;
                case 'L':t=t+50;
                break;
                case 'C':
                if(s[i+1]=='D'){
                t=t+400;
                i++;}
                else if(s[i+1]=='M'){
                    t=t+900;
                    i++;
                }
                else{
                    t=t+100;
                }
                break;
                case 'D':t=t+500;
                break;
                case 'M':t=t+1000;
                break;
                case 'I':
                if(s[i+1]=='V'){
                t=t+4;
                i++;}
                else if(s[i+1]=='X'){
                    t=t+9;
                    i++;
                }
                else{
                    t=t+1;
                }
                break;
            }
        }
        return t;
        
    }
};