class LFUCache {
public:
    map<int,list<vector<int>>> freq;
    unordered_map<int , list<vector<int>>:: iterator> mp;
    int cap;
    int size = 0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    void addFirst(int key){
        auto &vec = *(mp[key]);
        int val = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);
        if(freq[f].empty()){
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key , val , f});
        mp[key] = freq[f].begin();

    }
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        auto &vec = *(mp[key]);
        int val = vec[1];
        addFirst(key);
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mp.count(key)){
            auto &vec = *(mp[key]);
            vec[1] = value;
            addFirst(key);
            return;
        }
        else if(size < cap){
            freq[1].push_front(vector<int>({key , value , 1}));
            mp[key] = freq[1].begin();
            size++;
        }else{
            auto &vec = freq.begin()->second;
            int k = vec.back()[0];
            vec.pop_back();
            if(vec.empty()){
                freq.erase(freq.begin()->first);
            }
            mp.erase(k);
            freq[1].push_front(vector<int>({key , value , 1}));
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */