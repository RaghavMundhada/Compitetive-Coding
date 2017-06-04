#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int main()
{
	int t,i,j,k,n,q;
	int l,h,m,st,av;
	ll re;
	cin>>t;
	bool sat;

	while(t--)
	{
		cin>>n>>q;

		vector<int> v(n);
		vector<ll> f(n);

		rep(i,n)
			cin>>v[i];

		sort(v.begin(),v.end());
		f[0] = v[0];

		for(i=1;i<n;i++)
			f[i] = v[i] + f[i-1];

		while(q--)
		{
			cin>>k;

			if(v[0]>=k)
			{
				cout<<n<<endl;
				continue;
			}

			st = h = lower_bound(v.begin(),v.end(),k)-v.begin()-1;
			l=0;
			sat = false;

			while(l<=h)
			{
				m = l + (h-l)/2;
				av = m;

				if(m!=0)
					re = ((ll)k)*(st-m+1) - (f[st]-f[m-1]);
				else
					re = ((ll)k)*(st-m+1) - f[st];

				if(av==re)
				{

					sat = true;
					break;
				}

				else if(av>re)
				{
					sat = true;

					if(h==m)
						break;
					h=m;
				}

				else
				{
					l=m+1;
					
				}
			}
			if(sat)
				cout<<n-m<<endl;
			else
				cout<<n-m-1<<endl;

		}		
	}

	return 0;
}