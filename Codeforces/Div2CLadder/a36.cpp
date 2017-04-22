#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
	int n,s=1,i,j,k,x;
	long long int sum=0;
	cin>>n;

	vector<pair<int,int> > v(n+1,make_pair(0,0));

	for(i=0;i<n;i++)
	{
		cin>>j;

		if(j==1)
		{
			cin>>x>>k;
			v[x-1].second+=k;
			sum = sum+x*k;
		}

		else if(j==2)
		{
			cin>>k;
			v[s].first = k;
			s++;
			sum = sum+k;
		}

		else
		{
			if(s>=2)
			{
				v[s-2].second += v[s-1].second;
				sum = sum - v[s-1].second - v[s-1].first;
				v[s-1].first=0;
				v[s-1].second=0;
				s--;
			}
		}
		printf("%0.12lf\n",(double)sum/s);
		
	}
	return 0;
}