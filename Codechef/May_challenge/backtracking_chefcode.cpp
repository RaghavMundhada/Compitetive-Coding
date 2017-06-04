#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int n;
float k;
vector<float> v(40);
ll ans;

void countValid(int level,float sum)
{
	if(level==n)
	{
		if(sum<=k)
			ans++;

		return;
	}

	if(sum>k)
		return;
	
	countValid(level+1,sum+v[level]);
	countValid(level+1,sum);
}

int main()
{
	int i,j;
	float p,s=0;
	cin>>n>>k;
	k = log(k);

	rep(i,n)
	{
		cin>>p;
		v[i] = log(p);
		s=s+v[i];
	}

	sort(v.begin(),v.begin()+n);

	ans=0;

	countValid(0,0);

	cout<<ans-1<<endl;
	return 0;
}