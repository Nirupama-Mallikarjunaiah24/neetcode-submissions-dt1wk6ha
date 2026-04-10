class MyHashMap {
    const int size = 1000;
    vector<list<pair<int,int>>> myhash;
    int hash (int key) {
        return key%size;
    }
public:
    MyHashMap() {
       myhash.resize(size); 
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        for ( auto &i : myhash[idx]) {
            if (i.first == key) {
                i.second = value;  // update value
                return;
            }
        }
        myhash[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx = hash(key);

        for ( auto &i : myhash[idx]) {
            if (i.first == key)
                return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for (auto it = myhash[idx].begin(); it != myhash[idx].end(); ++it) {
        if (it->first == key) {
            myhash[idx].erase(it);
            return;
        }
    }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */