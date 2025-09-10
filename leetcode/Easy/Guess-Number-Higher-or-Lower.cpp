/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#include <bits/stdc++.h>
using namespace std;
 class Solution {
    public:
        int binarySearch(int s, int e) {
            int mid = s + (e - s) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid;
            } else if (res < 0) {
                return binarySearch(s, mid - 1);
            } else {
                return binarySearch(mid + 1, e);
            }
        }
        int guessNumber(int n) {
            return binarySearch(0,n);
        }
    };