#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

int main()
{
	string s;
	int i,j,t;
	cin>>t;

	for(i=0;i<t;i++)
	{
		cin>>s;
		string tmp;
		tmp.push_back(s[0]);

		for(j=1;j<s.length();j++)
		{
			if(s[j]!=s[j-1])
				tmp.push_back(s[j]);
		}

		if(tmp.length()>3 || !(tmp=="E" || tmp=="C" || tmp=="S" || tmp=="CE" || tmp=="CS" || tmp=="ES" || tmp=="CES"))
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;

	} 
	return 0;
}