class TimeMap {
private:
    unordered_map<string, vector<pair<int, string> > > m;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        int l = 0, r = m[key].size() - 1;
        string later ="";
        while (l <= r) { 
            int mid = (l+r)/2;
            // if (tmp[mid].first == timestamp)
            //     return tmp[mid].second;
            if (m[key][mid].first <= timestamp) { 
                l = mid + 1;
                later = m[key][mid].second;
            }
            else 
                r = mid - 1;
        }
        return later;
    }
};


/*
->  array[ , set]
*/