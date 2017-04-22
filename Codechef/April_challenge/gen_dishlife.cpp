#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,k,i,j,p,l,x;
	cin>>t;

	for(i=0;i<t;i++)
	{
		cin>>n>>k;

		vector<int> v(k+1,0);
		vector<vector<int> > v1(n);

		for(j=0;j<n;j++)
		{
			cin>>p;

			for(l=0;l<p;l++)
			{
				cin>>x;
				v1[j].push_back(x);
				v[v1[j][l]]++;
			}

		}

		for(j=0;j<k;j++)
			if(v[j+1]==0)
				break;

		if(j!=k)
		{
			cout<<"sad"<<endl;
			continue;
		}

		for(j=0;j<n;j++)
		{
			for(l=0;l<v1[j].size();l++)
				if(v[v1[j][l]] == 1)
					break;

			if(l==v1[j].size())
				break;
		}

		if(j==n)
			cout<<"all"<<endl;

		else
			cout<<"some"<<endl;
	}
	return 0;
}