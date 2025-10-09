class CustomStack {
public:
    vector<int> stack;
    int maxi;
    int currSize;
    CustomStack(int maxSize) {
        maxi = maxSize;
        currSize = 0;
    }

    void push(int x) {
        if(currSize==maxi) return;
        else{
            stack.push_back(x);
            currSize++;
        }
    }

    int pop() {
        if(currSize==0) return -1;
        else{
            int x = stack[currSize-1];
            stack.pop_back();
            currSize--;
            return x;
        }
    }

    void increment(int k, int val) {
        int limit=min(k,currSize);
        for(int i=0;i<limit;i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */