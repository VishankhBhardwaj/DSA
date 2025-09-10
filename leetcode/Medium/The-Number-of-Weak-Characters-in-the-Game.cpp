class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](auto&a,auto&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });
        int maxDefense=0;
        int count=0;
         for (auto &p : properties) {
            if (p[1] < maxDefense) count++;
            else maxDefense = p[1];
        }

        return count;
    }
};