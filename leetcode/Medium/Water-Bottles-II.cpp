class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans =0;
        int emptyBottles = 0;
        while (numBottles > 0) {
            ans+=numBottles;
            emptyBottles+=numBottles;
            numBottles=0;
            while (numExchange <= emptyBottles) {
                int newFullBottles = 0;
                emptyBottles -= numExchange;
                numExchange++;
                newFullBottles++;
                numBottles += newFullBottles;
            }
        }
        return ans;
    }
};