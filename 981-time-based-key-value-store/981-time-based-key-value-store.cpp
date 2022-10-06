class TimeMap {
public:
    unordered_map<string, map<int, string>> *m;
    TimeMap() {
        m = new unordered_map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        (*m)[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(((*m).find(key) == (*m).end()) || ((*m)[key].begin() -> first > timestamp))
            return  "";
        return (--(*m)[key].upper_bound(timestamp)) -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */