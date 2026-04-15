class WordDictionary {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool isValidWord;
    };

    Node* root;

    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto c : word) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new Node();
            curr = curr->children[c];
        }
        curr->isValidWord = true;
    }
    
    bool searchWithWildCards(Node* root, string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++) {
            char c = word[i];
            if (c == '.') {
                string newWord = word.substr(i+1);
                for(auto child : curr->children) {
                    if (searchWithWildCards(child.second, newWord))
                        return true;
                }
                return false;
            } else {
                if (curr->children.find(c) == curr->children.end())
                    return false;
                curr = curr->children[c];
            }
        }
        return curr->isValidWord;
    }

    bool search(string word) {
        return searchWithWildCards(root, word);
    }
};
