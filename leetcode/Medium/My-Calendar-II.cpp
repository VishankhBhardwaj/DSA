class MyCalendarTwo {
public:
    vector<pair<int,int>>booking;
    vector<pair<int,int>>overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto & [start,end]:overlap){
            if(startTime<end && endTime>start){
                return false;
            }
        }
        for(auto&[start,end]:booking){
             if(startTime<end && endTime>start){
                overlap.push_back({max(start,startTime),min(end,endTime)});
            }
        }
        booking.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */