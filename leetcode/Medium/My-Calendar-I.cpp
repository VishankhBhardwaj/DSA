class MyCalendar {
public:
    map<int, int> bookings;
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        if (bookings.empty()) {
            bookings[startTime] = endTime;
        } else {
            for (auto& [start, end] : bookings) {
                if (startTime < end && start < endTime)
                    return false;
            }
            bookings[startTime] = endTime;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */