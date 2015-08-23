class LRUCache{
private:
    struct CacheNode {
      int key;
      int value;
      CacheNode(int k, int v) : key(k), value(v) {}
    };
    int Capacity;
    list<CacheNode> cacheList;
//    list<int> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
public:
    LRUCache(int capacity) {
       Capacity = capacity; 
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) {
            if (cacheList.size() == Capacity) {
                CacheNode deleteNode = cacheList.back();
                cacheList.pop_back();
                cacheMap.erase(deleteNode.key);
            } 
            cacheList.insert(cacheList.begin(), CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        } else {
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
};
