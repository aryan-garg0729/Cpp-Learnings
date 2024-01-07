#include <vector>
#include <string>
#include<iostream>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode* *children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];

		for(int i = 0;i<26;i++){
			children[i] = NULL;    //setting the array as NULL
		}

		isTerminal = false;
	}

};

class Trie{
	TrieNode *root;

	public:
	Trie(){
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode*root , string word){
		if(word.size() == 0){			//base case
			root->isTerminal = true;   //setting isTer = true to show it is end letter of a word
			return;
		}

		int index = word[0]-'a'; //as we are storing 'a'->1,'b'->2,'c'->3....
		TrieNode *child;

		if(root->children[index]!=NULL){  //means the first letter of word exists
			child = root->children[index];		//small calc
		}
		else{
			child = new TrieNode(word[0]);  //the letter don't exists so create it
			root->children[index] = child; //putting the word in the children array of root
 		}

		insertWord(child,word.substr(1));  //rec call
	}
	void insertWord(string word) {   //for user
        insertWord(root, word); 
    }

	bool search(string word) {  //for user
        return search(root,word);
    }
    bool search(TrieNode*root,string word) {
        if(word.size() == 0){
            return root->isTerminal==true; //if size = 0 and it is 'terminal' then the word exist else it don't
        }
        
        int index = word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];  //if the first letter exists then search for rest 
			return search(child,word.substr(1));
            
        }
        else{  //else return false
            return false;
        }  
    }

	void removeWord(string word){  //for user
		removeWord(root,word);    
	}
	void removeWord(TrieNode*root,string word){
		if(word.size()==0){
			root->isTerminal = false;  //base case
			return;
		}

		int index = word[0]-'a';
		TrieNode *child;

		if(root->children[index]!=NULL){
			child = root->children[index];
			removeWord(child,word.substr(1));   //rec call
		}
		else{
			return;
		}
		/*removing useless nodes. A node is useless if:-
		1. it is not terminal node
		2. it has no children
		*/
		if(child->isTerminal == false){  //condition 1
			for(int i = 0;i<26;i++){
				if(child->children[i]!=NULL){//if it has any child so it's not useless so return
					return;
				}
			}
			delete child;  //else it is useless so delete it
			root->children[index] = NULL; //set that index to NULL as the node is deleted
		}

	}

	bool patternMatching(vector<string> vect, string pattern) {
        string inp;
        for(int i = 0;i<vect.size();i++){
            inp = vect[i];
            while(inp.size()!=0){       //inserting all suffixes to trie
                insertWord(inp);
                inp = inp.substr(1);
            }
        }
        return search(pattern);      
    }

	void autocomplete(TrieNode *root ,string s)
    {
        if(root->isTerminal==true)
            cout<<s<<endl;
        
        for(int i=0 ;i<26 ;i++)
        { if(root->children[i]!=NULL)
          { char c= i + 'a';
            autocomplete(root->children[i],s+c);
            }
        } 
        return;
    }
    void autoComplete(vector<string> input, string pattern) {
       //build a trie
        for(int i=0 ;i<input.size();i++)
            insertWord(input[i]);
        //search in a trie
        if(search(pattern)==false) return ;
        
        
        string s= pattern;
        
        while(pattern.size()!=0)
        {
            root=root->children[pattern[0]-'a'];
            pattern=pattern.substr(1);
        }
        
        autocomplete( root , s);
    }

};


