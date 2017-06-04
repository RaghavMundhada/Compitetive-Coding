#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int main()
{
	int i,j,t,n,m,k;

	cin>>t;

	rep(i,t)
	{
		cin>>n;
		m=0;
		rep(j,n)
		{
			cin>>k;
			m=max(k,m);
		}

		cout<<n-m<<endl;
	}

	return 0;
}