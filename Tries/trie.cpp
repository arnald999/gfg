#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
	public:
		TrieNode *children[ALPHABET_SIZE];
		bool endofword;
};

TrieNode *getNode(void)
{
	TrieNode *pNode = new TrieNode();
	pNode->endofword = false;
	
	for(int i=0; i<ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	
	return pNode;
}

void insert(TrieNode *root, string key)
{
	TrieNode *temp = root;
	
	for(int i=0; i<key.length(); i++)
	{
		int index = key[i]-'a';
		if(!temp->children[index])
			temp->children[index] = getNode();
		
		temp = temp->children[index];
	}
	
	temp->endofword = true;
}


bool search(TrieNode *root, string key)
{
	TrieNode *temp = root;
	
	for(int i=0; i<key.length(); i++)
	{
		int index = key[i]-'a';
		if(!temp->children[index])
			return false;
		
		temp = temp->children[index];
	}
	
	return (temp!=NULL && temp->endofword);
}

int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "there")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0; 
} 
