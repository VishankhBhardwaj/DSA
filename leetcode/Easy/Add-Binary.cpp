class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 1) {
                    res += '1';
                } else {
                    res += '0';
                }
                carry = 1;
            } else if ((a[i] == '1' && b[j] == '0') ||
                       (a[i] == '0' && b[j] == '1')) {
                if (carry == 1) {
                    res += '0';
                    carry = 1;
                } else {
                    res += '1';
                    carry = 0;
                }
            } else { 
                if (carry == 1) {
                    res += '1';
                    carry = 0;
                } else {
                    res += '0';
                }
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (a[i] == '1') {
                if (carry == 1) {
                    res += '0';
                    carry = 1;
                } else {
                    res += '1';
                }
            } else {
                if (carry == 1) {
                    res += '1';
                    carry = 0;
                } else {
                    res += '0';
                }
            }
            i--;
        }

        while (j >= 0) {
            if (b[j] == '1') {
                if (carry == 1) {
                    res += '0';
                    carry = 1;
                } else {
                    res += '1';
                }
            } else {
                if (carry == 1) {
                    res += '1';
                    carry = 0;
                } else {
                    res += '0';
                }
            }
            j--;
        }

        if (carry == 1) {
            res += '1';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};