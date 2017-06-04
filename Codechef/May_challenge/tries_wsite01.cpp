#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

struct trie
{
	struct trie* children[26];
};

void insert(trie* root,string s,int index)
{
	if(index==s.length())
		return;

	if(root->children[s[index]-'a']==NULL)
	{
		trie* t;
		t = new trie();

		int i;

		rep(i,26)
			t->children[i]=NULL;

		root->children[s[index]-'a'] = t;
	}

	insert(root->children[s[index]-'a'],s,index+1);
}

int getprefix(trie* root,string s,int index)
{
	if(index==s.length())
		return -1;

	if(root->children[s[index]-'a']==NULL)
		return index;

	return getprefix(root->children[s[index]-'a'],s,index+1);
}

int main()
{
	int n,i,j;
	cin>>n;
	vector<string> v;
	trie root;
	char type;
	string s;
	rep(i,26)
		root.children[i]=NULL;

	rep(i,n)
	{
		cin>>type;
		cin>>s;

		if(type=='+')
		{
			insert(&root,s,0);
		}

		else
		{
			v.pb(s);
		}
	}

	map<string,int> m;

	for(i=0;i<v.size();i++)
	{
		int a = getprefix(&root,v[i],0);
		if(a==-1)
			break;
		else
			m[v[i].substr(0,a+1)]=1;
	}

	if(i!=v.size())
		cout<<"-1"<<endl;

	else
	{
		map<string,int>::iterator it;
		cout<<m.size()<<endl;
		for(it=m.begin();it!=m.end();it++)
			cout<<it->first<<endl;
		
	}
	return 0;
}