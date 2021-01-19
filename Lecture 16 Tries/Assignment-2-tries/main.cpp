#include <bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
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

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
		
		//Insert all the words in the vector.
        for (int i = 0; i < words.size(); i++) {
			string reverse = "";
			for (int j = words.at(i).size() - 1; j >= 0; j--) {
				reverse +=  words.at(i)[j]; //words.ar(i) is a string so itslike saying str[j];
			}
			
			//If the string itslef is a pallindrome return true, else insert the word into the trie.
			if (reverse == words.at(i)) return true;
			else { 
				for (int j = 0; j < words.at(i).size(); j++) {
					add(words.at(i).substr(j)); 
				}
			}
		}
		for (int i = 0; i < words.size(); i++) {
			string reverse = "";
			for (int j = words.at(i).size() - 1; j >= 0; j--) {
				reverse +=  words.at(i)[j];
			}
			if (search(this -> root, reverse)) {
				return true;
			}
		}
		return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}