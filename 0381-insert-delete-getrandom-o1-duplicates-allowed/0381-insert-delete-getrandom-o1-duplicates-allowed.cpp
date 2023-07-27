class RandomizedCollection {
public:
    
    unordered_map<int, unordered_set<int>> indices;
    vector<int> store;
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        indices[val].insert(store.size());
        store.push_back(val);
        return indices[val].size() == 1 ? true : false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!indices[val].size()) {
            return false;
        }
        auto it = indices[val].begin();
        int targetind = *it, swapind = store.size() - 1, swapval = store.back();
        swap(store[swapind], store[targetind]);
        store.pop_back();
        indices[val].erase(targetind);
        if (swapind != targetind) {
            indices[swapval].erase(swapind);
            indices[swapval].insert(targetind); 
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return store[rand() % store.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */