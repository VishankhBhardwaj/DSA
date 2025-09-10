#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int i){
            int lowest=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<n && arr[lowest]>arr[left]){
                lowest=left;
            }
            if(right<n && arr[lowest]>arr[right]){
                lowest=right;
            }
            if(lowest!=i){
                swap(arr[i],arr[lowest]);
                heapify(arr,n,lowest);
            }
        }
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
