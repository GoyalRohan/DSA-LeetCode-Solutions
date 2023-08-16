class TrieNode {
public:
    
    TrieNode *children[26];
    string word;

    TrieNode(){
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string &s) 
    {
        TrieNode *cur = root;
        for(int i = 0; i < s.size(); i++) 
        {
            char c = s[i] - 'a';
            if (cur->children[c] == NULL) 
            {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = s;
    }
};

class Solution {
public:

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &ans) 
    {
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()) return;
            
        char c = board[i][j];
        if(c == '#' or !p->children[c - 'a']) return;
        
        p = p->children[c - 'a'];
        if (p->word.size() > 0) 
        {
            ans.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        dfs(board, i - 1, j, p, ans);
        dfs(board, i, j - 1, p, ans);
        dfs(board, i + 1, j, p, ans);
        dfs(board, i, j + 1, p, ans);
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) 
    {
        // insert all words into the trie
        Trie *trie = new Trie();
        for(int i=0;i<words.size();i++){
            trie->insert(words[i]);
        }
        
        vector<string>ans;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                // start form every cell of board
                dfs(board, i, j, trie->root, ans);
            }
        }
        return ans;
    }
    
};