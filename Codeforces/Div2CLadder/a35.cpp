#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int s=0;
	int n,i,a,m=0;

	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>a;
		m=max(m,a);
		s = s + a; 
	}

	cout<<max((long long int)ceil((double)s/(n-1)),(long long int)m)<<endl;
		 
	return 0;
}
