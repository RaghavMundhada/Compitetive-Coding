#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int main()
{
	int t,i,j,n;
	cin>>t;

	rep(i,t)
	{
		cin>>n;
		vector<int> v(2*n);

		rep(j,2*n)
			cin>>v[j];

		sort(v.begin(),v.end());
		//cout<<2*n-n/2-1<<endl;
		cout<<v[2*n-n/2-1]<<endl;

		for(j=0;j<n;j++)
		{
			cout<<v[j]<<" ";
			cout<<v[j+n]<<" ";
		}
		cout<<endl;		
	}

	return 0;
}