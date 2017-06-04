#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int ori(ll a,ll b,ll c ,ll d)
{
	if(a==c)
		return 1;

	return 0;
}

bool same(ll a,ll b,ll c,ll d)
{
	if(a==c && b==d)
		return true;

	return false;
}

int main()
{
	ll x11,y11,x12,y12,x21,y21,x22,y22;
	int t,g1,g2;

	cin>>t;

	while(t--)
	{
		cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;

		g1 = ori(x11,y11,x12,y12);//g==0 means horizontal line else vertical
		g2 = ori(x21,y21,x22,y22);

		if(g1==g2)//if same orientation
		{
			if(g1==1)//if both vertical
			{
				if(x11==x21)
				{
					if((y11>=min(y21,y22) && y11<=max(y21,y22)) || (y12>=min(y21,y22) && y12<=max(y21,y22)) || (y21>=min(y11,y12) && y21<=max(y11,y12)) || (y22>=min(y11,y12) && y22<=max(y11,y12)))//check if lines overlap
						cout<<"yes"<<endl;

					else
						cout<<"no"<<endl;
				}

				else
					cout<<"no"<<endl;

			}

			else//if both horizontal
			{
				if(y11==y21)
				{
					if((x11>=min(x21,x22) && x11<=max(x21,x22)) || (x12>=min(x21,x22) && x12<=max(x21,x22)) || (x21>=min(x11,x12) && x21<=max(x11,x12)) || (x22>=min(x11,x12) && x22<=max(x11,x12)))//check if lines overlap
						cout<<"yes"<<endl;

					else
						cout<<"no"<<endl;
				}

				else
					cout<<"no"<<endl;
			}
		}

		else//diff. orientation
		{
			if(same(x11,y11,x21,y21) || same(x11,y11,x22,y22) || same(x12,y12,x21,y21) || same(x12,y12,x22,y22))//check if end points are same
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}

	}

	return 0;
}