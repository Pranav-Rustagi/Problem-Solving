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
        if((*m).find(key) == (*m).end())
            return  "";
        if((*m)[key].begin() -> first > timestamp)
            return "";
        auto iter = (*m)[key].upper_bound(timestamp);
        return (*(--iter)).second;
    }
};

// ["TimeMap","set","set","get","set","get","get"]
// [[],["a","bar",1],["x","b",3],["b",3],["foo","bar2",4],["foo",4],["foo",5]]

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */