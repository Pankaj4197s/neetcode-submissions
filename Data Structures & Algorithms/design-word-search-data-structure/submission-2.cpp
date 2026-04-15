class WordDictionary {
public:
    struct Trie {
        unordered_map<char, Trie*> children;
        bool isWord;
    };
    
    Trie* root;
    
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(auto c : word) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool searchWithWildCards(Trie* root, string word) {
        Trie* curr = root;
        int sz = word.length();
        for(int i = 0; i < sz; i++) {
            char c = word[i];
            if (c == '.') {
                string newWord = word.substr(i+1);
                cout<<word<<" "<<newWord<<endl;
                if (curr->children.empty())
                    return false;
                for (auto child : curr->children) {
                    if (searchWithWildCards(child.second, newWord)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (curr->children.find(c) == curr->children.end())
                    return false;
                curr = curr->children[c];
            }
        }
        return curr->isWord;
    }
    
    bool search(string word) {
        return searchWithWildCards(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */