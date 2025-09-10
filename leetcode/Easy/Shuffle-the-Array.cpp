#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> shuffle(vector<int>& nums, int n) {
             vector<pair<int, int>> pairs;
            for (int i = 0; i < n; ++i) {
                pairs.push_back({nums[i], nums[i + n]});
            }
    
            vector<int> result;
            for (auto& p : pairs) {
                result.push_back(p.first);
                result.push_back(p.second);
            }
    
            return result;
        
        }
    };