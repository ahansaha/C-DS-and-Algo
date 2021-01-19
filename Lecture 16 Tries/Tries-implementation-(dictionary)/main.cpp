#include <iostream>
#include <vector>
using namespace std;


//Creating the data type of type Trie Node. So every time you create a node it will have these below properties.
class TrieNode {
public:
	char data;
	TrieNode ** children;
	bool isTerminal;
	
	TrieNode (char data) {
		this->data = data;
		children = new TrieNode * [26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
public:
	
	TrieNode * root;
	
	Trie () {
		root = new TrieNode('\0');
	}
	
	//INSERT WORD.
	void insert (TrieNode * root, string word) {
		//base case, if word lengh is zero i.e if no word is provided then root is the termial itself.
		if (word.size() == 0) {
			root -> isTerminal = true;
			return;
		}
		
		int idex = word[0] - 'a';
		if (root -> children[idex] != NULL) {
			insert (root -> children[idex], word.substr(1));
		} 
		else {
			TrieNode * child = new TrieNode(word[0]);
			root -> children[idex] = child;
			insert (root -> children[idex], word.substr(1));
		}
	}
	
	//SEARCH WORD.
	bool search(TrieNode * root, string word) {
        //Base Case, if word length is zero and the terminal is true then return true.
		if (word.size() == 0) {
			if (root -> isTerminal == true)  return true;
			else return false;
		}
		
		//check if the root's children array contains the first letter of the word.
		int idex = word[0] - 'a';
		if (root -> children[idex] != NULL) { //which means the first letter exists, and we need to call recursion for the rest of the letters. 
			return search(root -> children[idex], word.substr(1)); //call recursion and pass the rest of the word.
		} else {
			return false;
		}
    }
	
	//REMOVE WORD.
	void remove (TrieNode * root, string word) {
		//Base case. 
		if (word.size() == 0) {
			root -> isTerminal = false;
			return;
		}
		
		int idex = word[0] - 'a';
		if (root -> children[idex] != NULL) { 
			//We found the first letter, so we will first tell recursion to delete the rest of the word.
			remove (root -> children[idex], word.substr(1));
			
			//After recursion deletes the rest of the word, we need to delete the node if its not terminal and no other node is dependant on it.
			//Only its parent can delete the node.
			if (root -> children[idex] -> isTerminal == false) {
				for (int i = 0; i < 26; i++) {
					if (root -> children[idex] -> children[i] != NULL) {
						return;
					}
				}
				delete root -> children[idex];
				root -> children[idex] = NULL;
			}
		} else { //if we don't find the first letter also that means the word that has to be deleted doesn't exist only so we simply return.
			return;
		}
	}
	
	
public:
	void insert (string word) {
		insert (this -> root, word);
	}
	
	bool search (string word) {
		return search(this -> root, word);
	}
	
	void remove (string word) {
		remove (this -> root, word);
	}
};

int main () {
	Trie t;
	t.insert("and");
	t.insert("are");
	t.insert("dot");

	cout << t.search("and") << endl;

	t.remove("and");
	cout << t.search("and") << endl;
}