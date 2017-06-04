#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int main()
{
	int n,k,p,i,j,m;
	string s;
	cin>>n>>k>>p;
	k=min(k,n);
	vector<int> v(n);
	rep(i,n)
		cin>>v[n-i-1];

	cin>>s;

	vector<int> vv(2*n,0);

	m=0;
	rep(i,k)
		m=m+v[i];

	vv[0]=m;

	for(i=1;i<n;i++)
		vv[i]=vv[i-1] + v[(i+k-1)%n] - v[i-1];
	
	for(i=n;i<2*n;i++)
		vv[i] = vv[i-n];

	k=n-k+1;

	deque<int> dq(k);

	for(i=0;i<k;i++)
	{
		while((!dq.empty()) && vv[i]>=vv[dq.back()])
		{
			dq.pop_back();
			//cout<<"pop_back"<<endl;
		}
		//cout<<"push_back "<<vv[i]<<endl;
		dq.push_back(i);
	}

	for(;i<2*n;i++)
	{
		//cout<<vv[dq.front()]<<" ";
		vv[i-k]=vv[dq.front()];

		while((!dq.empty()) && dq.front() <= i-k)
		{
			dq.pop_front();
			//cout<<"pop_front"<<endl;
		}

		while((!dq.empty()) && vv[i]>=vv[dq.back()])
		{
			dq.pop_back();
			//cout<<"pop_back"<<endl;
		}
		//cout<<"push_back"<<vv[i]<<endl;
		dq.push_back(i);
	}
	m=0;

	for(i=0;i<p;i++)
	{
		if(s[i]=='!')
			m=(m+1)%n;
		else
			cout<<vv[m]<<endl;
	}

	return 0;
}