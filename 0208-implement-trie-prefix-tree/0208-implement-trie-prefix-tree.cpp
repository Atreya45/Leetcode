class Trie {
public:
    class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        set<string> words;

        TrieNode(char ch) {
            data = ch;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
            isTerminal = false;
        }
    };
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }

    void insertWordHelper(TrieNode* root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        int index = word[0] - 'a';
        if (root->children[index]) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWordHelper(child, word.substr(1));
    }
    void insert(string word) { insertWordHelper(root, word); }
    bool searchWordHelper(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchWordHelper(child, word.substr(1));
    }
    bool search(string word) { return searchWordHelper(root, word); }
    bool startsWithHelper(TrieNode* root, string prefix) {
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!root->children[index])
                return false;
            root = root->children[index];
        }
        return true;
    }
    bool startsWith(string prefix) { return startsWithHelper(root, prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */