class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int ans=n;
        while (ans != 1 && !s.count(ans)) {
            int temp=ans;
            s.insert(ans);
            int sum=0;
            while (temp > 0) {
                int digit = temp % 10;
                sum += digit * digit;
                temp /= 10;
            }
            
            ans = sum;
        }
        return ans==1;
    }
};