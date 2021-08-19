#include<bits/stdc++.h>
using namespace std;
class tries{
	private:
	    struct trie{
	    struct trie* child[26];
	    bool isend;
	    trie()
	    {
	     	memset(child,0,sizeof(child));
		    isend=false;
	    }
    };
    
    struct trie* root;
    
    public:
    tries()
    {
    	root = new trie;
	}
    	
    void insert(string str)
   { 
	struct trie* curr=root;
	for(char ch:str)
	{
		int index=ch-'a';
		if(curr->child[index]==NULL)
		{
			curr->child[index] = new trie;
		}
		curr= curr->child[index];
	}
	curr->isend=true;
   }

   bool search(string str)
   {
	struct trie*curr =root;
	for(char ch:str)
	{
		int index=ch-'a';
		if(curr->child[index]==NULL)
		return false;
		curr= curr->child[index];
	}
	return curr->isend;
   }

    bool prefix(string str)
   {
	struct trie*curr =root;
	for(char ch:str)
	{
		int index=ch-'a';
		if(curr->child[index]==NULL)
		return false;
		curr= curr->child[index];
	}
	return true;
   }
}trieob;

int main()
{
	int n;
	cin>>n;
	//root = new trie();
	while(n--)
	{
		string str;
		cin>>str;
		trieob.insert(str);
	}
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(trieob.prefix(str)) cout<<"Present\n";
		else cout<<"Not Present\n";
	}
}
