class Solution {
public:
    int maxDistance(string s, int k) {
        int lat = 0, lon = 0, maxDist = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char dir = s[i];

            if (dir == 'N') lat++;
            else if (dir == 'S') lat--;
            else if (dir == 'E') lon++;
            else if (dir == 'W') lon--;

            int manhattan = abs(lat) + abs(lon);
            int stepsWithChanges = manhattan + k * 2;

            maxDist = max(maxDist, min(stepsWithChanges, i + 1));
        }

        return maxDist;

    }
};