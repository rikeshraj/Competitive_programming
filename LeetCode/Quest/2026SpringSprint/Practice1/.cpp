/*
Q1. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        int value = it->second;
        cache.splice(cache.begin(), cache, it);
        return value;        
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
        if (cache.size() > capacity) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
    }
};


/*
Q2. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (result.empty() || start > result.back()[1]) {
                result.push_back({start, end});
            }
            else {
                result.back()[1] =
                    max(result.back()[1], end);
            }
        }
        return result;
    }


/*

*/
