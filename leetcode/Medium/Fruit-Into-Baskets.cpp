class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0;
        int fruit1 = -1;
        int fruit2 = -1;
        int cnt = 0;
        int maxi = 0;
        while (j < fruits.size()) {
            if (fruit1 == -1)
                fruit1 = fruits[j];
            else if (fruit2 == -1)
                fruit2 = fruits[j];
            else if(fruits[j]!=fruit1 && fruits[j]!=fruit2) {
                i = j - 1;
                if (fruits[i] == fruit1) {
                    while (i >= 0 && fruits[i] == fruit1)
                        i--;
                    fruit2 = fruits[j];
                } else if (fruits[i] == fruit2) {
                    while (i >= 0 && fruits[i] == fruit2)
                        i--;
                    fruit1 = fruits[j];
                }
                i = i + 1;
            }
            cnt = j - i + 1;
            maxi = max(maxi, cnt);
            j++;
        }
        return maxi;
    }
};

//Another approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int i = 0, maxFruits = 0;

        for (int j = 0; j < fruits.size(); ++j) {
            count[fruits[j]]++;

            while (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0)
                    count.erase(fruits[i]);
                i++;
            }

            maxFruits = max(maxFruits, j - i + 1);
        }

        return maxFruits;
    }
};
