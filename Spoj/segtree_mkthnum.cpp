#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int x = (int)(ceil(log2(100010))); 
int max_size = 2*(int)pow(2, x) - 1; 
vector<vector<int> > segtree(max_size);

vector<int> v(100010);

void buildTree(int st,int en,int index)
{
	if(st==en)
	{
		segtree[index].push_back(v[st]);
		return;
	}

	int mid = st + (en-st)/2;
	int l = 2*index+1;
	int r = 2*index+2;

	buildTree(st,mid,l);
	buildTree(mid+1,en,r);

	int i=0,j=0;

	while(true)
	{
		if(i<segtree[l].size() && j<segtree[r])
		{
			if(segtree[l][i] <= segtree[r][j])
				segtree[index].push_back(segtree[l][i++]);

			else
				segtree[index].push_back(segtree[r][j++]);
		}

		else if(i<segtree[l].size())
				segtree[index].push_back(segtree[l][i++]);

		else if(j<segtree[r].size())
				segtree[index].push_back(segtree[r][j++]);

		else
			break;
	}

}

int main()
{
	int n,m,i,j,k,p;

	cin>>n>>m;

	rep(i,n)
		cin>>v[i];

	buildTree(0,n-1,0);
	
	
	return 0;
}