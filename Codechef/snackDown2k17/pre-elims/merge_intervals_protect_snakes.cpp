#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int n,k,a;

bool comp(pii a , pii b)
{
	if(a.first != b.first)
		return a.first < b.first;

	return a.second > b.second;
}

int getNumIntervals(vector<pii>& a)
{
	sort(a.begin(),a.end(),comp);

	int i=0,me=0,e=(n-k)/2,cnt=0,j;
	while(i<a.size() && e<k+(n-k)/2)
	{	
		cnt++;
		
		while(i<a.size() && a[i].first<=e+1)
		{
			me = max(me,a[i].second);
			i++;
		}
		if(e==me)
			break;
		e=me;
	}

	if(e < k+(n-k)/2)
		return -1;

	return cnt;

}

int main()
{
	int t,m,i,j,x1,y1,x2,y2;
	cin>>t;

	while(t--)
	{
		cin>>n>>k>>m;

		vector< pii > a13;
		vector< pii > a24; 
		
		rep(i,m)
		{
			cin>>x1>>y1>>x2>>y2;

			if(x1==x2)
			{
				a24.pb(mp(min(y1,y2),max(y1,y2)));
				if(max(y1,y2) <= (n-k)/2 || min(y1,y2)>(n-k)/2+k)
					a13.pb(mp(x1,x2));
			}

			if(y1==y2)
			{
				a13.pb(mp(min(x1,x2),max(x1,x2)));
				if(max(x1,x2) <= (n-k)/2 || min(x1,x2)>(n-k)/2+k)
					a24.pb(mp(y1,y2));
			}
			

		}
		
		if(a13.size()==0 || a24.size()==0)
		{
			cout<<"-1"<<endl;
			continue;
		}

		i=getNumIntervals(a13);

		if(i!=-1)
		{
			j=getNumIntervals(a24);

			if(j!=-1)
				cout<<i+j<<endl;
			else
				cout<<"-1"<<endl;
		}

		else
			cout<<"-1"<<endl;

	}
	return 0;
}