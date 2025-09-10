class Solution {
public:
    int maxDiff(int num) {
        string number = to_string(num);
        char maxDigit = ' ';
        for (auto i : number) {
            if (i != '9') {
                maxDigit = i;
                break;
            }
        }
        string maxi ="";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == maxDigit) {
                maxi += '9';
            } else {
                maxi += number[i];
            }
        }
        char minDigit = ' ';
        int f = 0;
        for (int i = 0; i < number.size(); i++) {
            if (i == 0 && number[i] != '1') {
                minDigit = number[i];
                f = 1;
                break;
            } else if (i > 0 && number[i] != '0' && number[i] != number[0]) {
                minDigit = number[i];
                break;
            }
        }
        string mini ="";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == minDigit && f == 1) {
                mini += '1';
            } else if (number[i] == minDigit && f == 0) {
                mini += '0';
            } else {
                mini += number[i];
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};