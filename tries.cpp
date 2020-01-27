// C++ implementation of search and insert 
// operations on Trie 

using namespace std; 

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode { 
	struct TrieNode *children[ALPHABET_SIZE] {nullptr}; 

	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void) { 
	struct TrieNode* pNode = new TrieNode; 
	pNode->isEndOfWord = false; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) { 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) { 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) { 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 
  
// Recursive function to delete a key from given Trie 
TrieNode* remove(TrieNode* node, string key, int depth = 0) { 
    // If tree is empty 
    if (!node) 
        return NULL; 
  
    // If last character of key is being processed 
    if (depth == key.size()) { 
  
        // If key is found but prefixes other keys
		// remove node's designation as leaf node
        if (node->isEndOfWord) 
            node->isEndOfWord = false; 
  
        // If key is found is not prefix of any other key,
		// remove node entirely 
        if (isEmpty(node)) { 
            delete (node);
            node = NULL; 
        } 
  
        return node; 
    } 
  
    // If not last character, recur for the child 
    // obtained using ASCII value
	// Depth is essentially the index of the key they're checking. The key is not modified
    int index = key[depth] - 'a'; 
    root->children[index] =  
        remove(root->children[index], key, depth + 1); 
  
    // After deleting child node. If root does not have any child (its only child got  
    // deleted), and it is not end of another word. 
    if (isEmpty(node) && node->isEndOfWord == false) { 
        delete (node); 
        node = NULL; 
    } 
  
    return node; 
} 

// Driver 
int main() { 
	// Input keys (use only 'a' through 'z' 
	// and lower case) 
	string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					"bye", "their" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	// Construct trie 
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	// Search for different keys 
	search(root, "the")? cout << "Yes\n" : 
						cout << "No\n"; 
	search(root, "these")? cout << "Yes\n" : 
						cout << "No\n"; 
	return 0; 
} 
