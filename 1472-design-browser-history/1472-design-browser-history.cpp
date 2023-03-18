class BrowserHistory {
public:
    
    vector<string> history ; 
    int temp ; 
    
    BrowserHistory(string homepage) {
        history.push_back(homepage) ; 
        temp = history.size() - 1 ; 
    }
    
    void visit(string url) {
        history.insert(history.begin() + temp + 1 , url ) ; 
        temp++ ; 
        history.resize(temp + 1 );
        
        // history.push_back(url) ; 
        // temp = history.size() - 1 ; 
        
    }
    
    string back(int steps) {
        string res = "" ; 
        while (temp > 0 && steps > 0)
        {
            steps-- ; temp-- ; 
        }
        
        res = history[temp] ; 
        return res ; 
    }
    
    string forward(int steps) {
        string res = "" ; 
        while (temp < history.size() - 1 && steps > 0)
        {
            steps-- ; temp++ ; 
        }
        
        res = history[temp] ; 
        return res ; 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */