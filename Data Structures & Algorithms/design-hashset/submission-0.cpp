class MyHashSet {
    const int size = 1000;
    vector<list<int>> myhash;

    int hash (int val) {
        return val%size;
    }
 public:
    MyHashSet() {
        myhash.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        
        for ( int i: myhash[idx]) {
            if (i == key) return; // already exists- collision
        }

        myhash[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        myhash[idx].remove(key);

    }
    
    bool contains(int key) {
        int index = hash(key);
        
        for (int i : myhash[index]) {
            if (i == key) return true;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */