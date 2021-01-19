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
	
	void printAllWords(TrieNode * Last, string pattern, string str = "") {
		if (Last == NULL) {
			return;
		}
		
		if (Last -> isTerminal) {
			cout << pattern + str << endl;
		}
		
		for (int i = 0; i < 26; i++) {
			if (Last -> children[i] != NULL) {
                string s = "";
                s += Last -> children[i] -> data;
				printAllWords(Last -> children[i], pattern, str + s);
			}
		}
	}
	
	TrieNode * searchForExactPatternWord(TrieNode * root, string pattern) {
		if (pattern.size() == 0) return NULL;
		for (int i = 0; i < pattern.size(); i++) {
			int idex = pattern[i] - 'a';
			if (root -> children[idex] != NULL) {
				root = root -> children[idex];
			} else {
				return NULL;
			}
		}
		return root;
	}

    void autoComplete(vector<string> input, string pattern) {
		for (int i = 0; i < input.size(); i++) {
			insertWord(input.at(i));
		}
		TrieNode * addressOfTheLastLetterInThePattern = searchForExactPatternWord(this -> root, pattern);
		printAllWords(addressOfTheLastLetterInThePattern, pattern);
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}