#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i;
	double s=0;

	cin>>n;

	vector<int> v(n+1);
	v[0] = 0;

	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		s=s+v[i];

		v[i] = v[i]+v[i-1];
	}
	int ans=0;
	for(i=1;i<n;i++)
		if(v[i]==s/2)
			ans++;

	cout<<ans<<endl;
	return 0;
}