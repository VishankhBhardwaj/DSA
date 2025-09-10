class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int count = 0;
        vector<string> v;
        string str = "";
        for (auto i : s) {
            if (count < k) {
                str += i;
                count++;
            }

            else {
                v.push_back(str);
                str.clear();
                str += i;
                count = 1;
            }
        }
        int diff = abs((int)str.size() - k);
        for (int i = 0; i < diff; i++) {
            str += fill;
        }
        v.push_back(str);
        return v;
    }
};