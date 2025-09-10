class Solution {
  public:
    void deleteElement(stack<int>&s,int curr,int mid){
        if(s.empty()) return;
        int top=s.top();
        s.pop();
        if(curr==mid){
            return;
        }
        
        deleteElement(s,curr+1,mid);
        s.push(top);
        
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int index = s.size() / 2;
        deleteElement(s,0,index);
        }
};