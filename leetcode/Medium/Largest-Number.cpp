class Solution {
public:
    bool isSmaller(int a, int b) {
        string A = to_string(a);
        string B = to_string(b);
        return A + B < B + A;
    }
    string largestNumber(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
        }
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            bool placed = false;
            for (int i = 0; i < ans.size(); i++) {
                if (isSmaller(ans[i], top)) {
                    int temp = ans[i];
                    ans[i] = top;
                    pq.push(temp);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                ans.push_back(top);
            }
        }
        if (ans.size() > 0 && ans[0] == 0)
            return "0";

        string res = "";
        for (int num : ans) {
            res += to_string(num);
        }
        return res;
    }
};