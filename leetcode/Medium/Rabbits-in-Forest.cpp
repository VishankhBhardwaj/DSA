class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int>mpp;
            for(int i=0;i<answers.size();i++){
                mpp[answers[i]]++;
            }
            int sum=0;
            for(auto pair:mpp){
                int x = pair.first;    // the number of *other* rabbits same color
                int count = pair.second;
    
                int groupSize = x + 1;
                int groupsNeeded = (count + x) / groupSize; // ceil(count / groupSize)
    
                sum += groupsNeeded * groupSize;
            }
            return sum;
        }
    };