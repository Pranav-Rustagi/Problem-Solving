class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto& e : v)
            if((start <= e[0] && end > e[0]) || (start < e[1] && end >= e[1]) || (start >= e[0] && end <= e[1]))
                return false;
        v.push_back({ start, end });
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */