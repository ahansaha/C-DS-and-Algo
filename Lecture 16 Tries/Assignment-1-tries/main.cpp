#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
	
	bool search(TrieNode * root, string word) {
        //Base Case, if word length is zero and the terminal is true then return true.
		if (word.size() == 0) {
			return true;
		}
		
		//check if the root's children array contains the first letter of the word.
		int idex = word[0] - 'a';
		if (root -> children[idex] != NULL) { //which means the first letter exists, and we need to call recursion for the rest of the letters. 
			return search(root -> children[idex], word.substr(1)); //call recursion and pass the rest of the word.
		} else {
			return false;
		}
    }

    bool patternMatching(vector<string> vect, string pattern) {
        for (int i = 0; i < vect.size(); i++) {
			for (int j = 0; j < vect.at(i).size(); j++) {
				insertWord(vect.at(i).substr(j));
			}
		}
		return search(this -> root, pattern);
    }
};

//4
//abc def ghi cba
//de


int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}