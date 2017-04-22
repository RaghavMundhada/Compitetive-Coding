#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
vector<vector<int> > v(1001,vector<int>(2,0));
vector<vector<int> > dp(1001,vector<int>(2,-1));
int f(int index,int c)
{
	if(index>=m)
		return 0;

	if(dp[index][c]!=-1)
		return dp[index][c];

	int i,ans=INT_MAX/2;

	for(i=x-1;i<y;i++)
	{
		if(i+index < m)
			ans = min(ans,v[i+index][c] - (index!=0?(v[index-1][c]):0) + f(i+index+1,(c+1)%2));
		else
			break;
	}

	return dp[index][c] = ans;
}
int main()
{
	int i,j;
	char k;
	cin>>n>>m>>x>>y;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>k;
			if(k=='.')
				v[j][0]++;
			else
				v[j][1]++;
		}
	}

	for(i=1;i<m;i++)
	{
		v[i][0] = v[i-1][0]+v[i][0];
		v[i][1] = v[i-1][1]+v[i][1];
	}

	cout<<min(f(0,0),f(0,1))<<endl;
	return 0;
}