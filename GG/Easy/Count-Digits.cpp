//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int count = 0;  // Initialize count
        int number = n; // Copy of n to extract digits
        int digit;

        while (number > 0) {  // Loop over the number's digits
            digit = number % 10;  // Extract last digit

            if (digit != 0 && n % digit == 0) {  // Check divisibility, avoid division by zero
                count++;
            }

            number = number / 10;  // Remove last digit
        }

        return count;
    }
};

//{ Driver Code Ends
