class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    vector<list<int>> hashset;
    
    MyHashSet() {
        hashset = vector<list<int>>(128);
    }
    
    int setHash(int key){
        int h = hash<int>{}(key);
        int hash_mod = h % hashset.size();
        
        return hash_mod;
    }
    
    void add(int key) {
        int hash = setHash(key);
        
        if(contains(key, hash))
            return ;
        auto &l = hashset[hash];
        l.push_back(key);
        return ;
        
    }
    void remove(int key, int hash){
        auto &l = hashset[hash];
        auto it = l.begin();
        while(it != l.end()){
            if(*it !=key){
                ++it;
                continue;
            }
            l.erase(it);
            return ;
        }
        return ;
    }
    
    void remove(int key) {
     remove(key, setHash(key));
        return ;   
    }
    
    bool contains(int key, int hash){
        const auto &l = hashset[hash];
        for(int n : l){
            if(n == key)
                return true;
        }
        return false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        return contains(key, setHash(key));
        
    }
};

/**
 *  * Your MyHashSet object will be instantiated and called as such:
 *   * MyHashSet* obj = new MyHashSet();
 *    * obj->add(key);
 *     * obj->remove(key);
 *      * bool param_3 = obj->contains(key);
 *       */
