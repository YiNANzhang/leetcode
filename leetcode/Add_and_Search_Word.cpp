class WordDictionary {
    struct trieTree {
        struct trieTree *child[26];
        bool isEnd;
//        int n;
//        trieTree(x) : n(0);
        trieTree() {
            fill_n(child, 26, nullptr);
            isEnd = false;
        }
    };
    struct trieTree *root;
public:
    WordDictionary() {
        root = new trieTree;
    }
    ~WordDictionary() {
        delete root;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        struct trieTree *cur, *newnode;
        int len = word.size();
        if(len == 0) return;
        //int len = word.size();
        cur = root;
        for(int i = 0; i < len; ++i) {
            if(cur->child[word[i]-'a'] != NULL) {
                cur = cur->child[word[i] - 'a'];
            } else {
                newnode = new trieTree();
                cur->child[word[i]-'a'] = newnode;
                cur = cur->child[word[i]-'a'];
            }
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return search(word, root);
    }


    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word, trieTree *cur) {
        //struct trieTree *cur = root;
        int len = word.size();
        for(int i = 0; i < len; ++i) {
            if(word[i] == '.') {
                for(int j = 0; j < 26; ++j)
                    if(cur->child[j] && search(word.substr(i+1), cur->child[j]))
                        return true;
                return false;
            }
            else {
                if(cur->child[word[i]-'a'] != NULL) {
                    cur = cur->child[word[i]-'a'];
                } else 
                    return false;
            }
        }
        return cur->isEnd;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
