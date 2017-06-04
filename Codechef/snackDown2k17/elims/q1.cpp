#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>
int n,m,k;
vector<vector<int> > dp(110,vector<int>(110,-1));

bool inout(vector<vector<int> >& adj,int i)
{
	int j;

	for(j=0;j<n;j++)
	{
		if(adj[i][j]==1 || adj[j][i]==1)
			return false;
	}

	return true;
}

bool in(vector<vector<int> >& adj,int i)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(adj[j][i]==1)
			return false;
	}

	return true;
}

void rem(vector<vector<int> >& adj,int i)
{
	int j;
	for(j=0;j<n;j++)
	{
		adj[i][j]=0;	
	}
}

int getmax(vector<vector<int> >& e,vector<vector<int> >& adj1,int level,int level1,int st,int mi,int h)
{
	if(level>=h)
	{
		return 0;
	}

	if(dp[adj1[level][level1]][st]!=-1)
		return dp[adj1[level][level1]][st];

	int i,ma=0;
	for(i=st;i<m;i++)
	{
		if(e[adj1[level][level1]][i]!=-1)
		{
			if(level1+1 < adj1[level].size())
				ma = max(ma,e[adj1[level][level1]][i] + getmax(e,adj1,level,level1+1,st,max(mi,i),h));

			else
				ma = max(ma,e[adj1[level][level1]][i] + getmax(e,adj1,level+1,0,max(i,mi)+1,max(i,mi)+1,h));
		}
	}

	return dp[adj1[level][level1]][st]=ma;
}

int main()
{
	int i,j,a,b;
	double ans = 0;

	cin>>n>>m;

	vector<vector<int> > e(n,vector<int>(m));
	vector<vector<int> > adj(n,vector<int>(n,0));
	vector<vector<int> > adj1(n);
	vector<bool> b1(n,false);

	rep(i,n)
	{
		rep(j,m)
		{
			cin>>e[i][j];
		}
	}

	cin>>k;

	rep(i,k)
	{
		cin>>a>>b;
		a--;
		b--;
		adj[a][b]=1;
	}

	
	int cnt=0,h=0;

	rep(i,n)
	{
		if(inout(adj,i))
		{
			ans = ans + *max_element(e[i].begin(),e[i].end());
			b1[i]=true;
			cnt++;
		}
	}


	while(cnt<n)
	{
		rep(i,n)
		{
			if(!b1[i] && in(adj,i))
			{
				adj1[h].pb(i);
				cnt++;
				b1[i]=true;
			}
		}

		rep(i,adj1[h].size())
			rem(adj,adj1[h][i]);
		h++;
	}

	
	ans = ans + getmax(e,adj1,0,0,0,0,h);
	cout <<fixed <<setprecision(2) << ans/n <<endl;
	return 0;
}