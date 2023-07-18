class LRUCache {
public:
    
    class node {
        
        public :
            int key ; 
            int val ;
            node *next ; 
            node *prev; 
        
            node (int key_, int val_)
            {
                key = key_ ; val = val_ ; 
                next = prev = NULL ; 
            }
    };
    
    node *head = new node(-1, -1) ; 
    node *tail = new node(-1, -1) ; 
    
    int cap ; 
    unordered_map<int, node*> mpp ; 
    
    LRUCache(int capacity) {
        
        cap = capacity ; 
        head->next = tail ; 
        tail->prev = head ; 
        
    }
    
    void addnode(node *newnode)
    {
        node *temp = head->next ; 
        newnode->next = temp ;
        newnode->prev = head ; 
        head->next = newnode ; 
        temp->prev= newnode ; 
    }
    
    void deletenode(node *delnode)
    {
        node *delnodeprev = delnode->prev ; 
        node *delnodenext = delnode->next ; 
        delnodeprev->next = delnodenext ; 
        delnodenext->prev = delnodeprev ; 
        // delete(delnode) ; 
    }
    
    int get(int key_) {
        if(mpp.find(key_) != mpp.end())
        {
            node *existingnode = mpp[key_] ; 
            int resvalue = existingnode->val ; 
            mpp.erase(key_) ; 
            deletenode(existingnode) ; 
            addnode(existingnode) ; 
            mpp[key_] = head->next ; 
            return resvalue ; 
        }
        return -1 ; 
    }
    
    void put(int key_, int value) {
        if(mpp.find(key_) != mpp.end())
        {
            node *existingnode = mpp[key_] ; 
            mpp.erase(key_) ; 
            deletenode(existingnode) ; 
        }
        
        if(mpp.size() == cap)
        {
            mpp.erase(tail->prev->key) ; 
            deletenode(tail->prev) ; 
        }
        
        addnode(new node(key_, value)) ; 
        mpp[key_] = head->next ; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */