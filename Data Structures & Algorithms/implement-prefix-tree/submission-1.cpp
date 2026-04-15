class PrefixTree {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool isValidWord;
    };

    Node* root;

    PrefixTree() {
        this->root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c : word) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new Node();
            curr = curr->children[c];
        }
        curr->isValidWord = true;
    }
    
    bool search(string word) {
        // if (word == "")
        //     return true;
        Node* curr = root;
        for(auto c : word) {
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        } 
        return curr->isValidWord;
    }
    
    bool startsWith(string prefix) {
        // return search(prefix);
        Node* curr = root;
        for(auto c : prefix) {
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        } 
        return true;
    }
};
