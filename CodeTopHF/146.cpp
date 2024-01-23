class LRUCache {
    int capacity;
    list<pair<int,int>> recent;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
public:
    LRUCache(int capacity) : capacity(capacity){

    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()){
            return -1;
        }
        recent.splice(recent.begin(),recent,it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()){
            // Key exists. Update key
            it->second->second = value;
            recent.splice(recent.begin(),recent,it->second);
            return ;
        }

        if(recent.size() == capacity){
            // cache is full. Remove LRU item
            auto last = recent.back();
            cache.erase(last.first);
            recent.pop_back();
        }

        recent.emplace_front(key,value);
        cache[key] = recent.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */