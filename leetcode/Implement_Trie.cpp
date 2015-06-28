class TrieNode {
public:
    TrieNode *children[26];
    bool isEnd;
    // Initialize your data structure here.
    TrieNode() {
        fill_n(children, 26, nullptr);
        isEnd = false;
    }
    ~TrieNode() {
        delete children[26];
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *cur = root;
        for(int i = 0; i < s.size(); ++i) {
            if(cur->children[s[i]-'a'] != nullptr) {
                cur = cur->children[s[i]-'a'];
            } else {
                TrieNode *newNode = new TrieNode;
                cur->children[s[i]-'a'] = newNode;
                cur = cur->children[s[i]-'a'];
            }
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *cur = root;
        for(int i = 0; i < key.size(); ++i) {
            if(cur->children[key[i]-'a'] != nullptr) {
                cur = cur->children[key[i]-'a'];
            }else {
                return false;
            }
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i = 0; i < prefix.size(); ++i) {
            if(cur->children[prefix[i]-'a'] != nullptr) {
                cur = cur->children[prefix[i]-'a'];
            }else {
                return false;
            }
        }
        return true;  
//        return search(prefix);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
