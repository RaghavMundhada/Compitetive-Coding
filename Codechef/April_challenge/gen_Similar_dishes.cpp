#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,i,j;
	string a,b,c,d,e;

	cin>>t;

	for(i=0;i<t;i++)
	{
		cin>>a>>b>>c>>d;
		int k=0;
		for(j=0;j<4;j++)
		{
			cin>>e;

			if(e==a||e==b||e==c||e==d)
				k++;

		}

		if(k>=2)
			cout<<"similar"<<endl;

		else
			cout<<"dissimilar"<<endl;

	}
	return 0;
}