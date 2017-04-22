#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int t,i,j,k,ans,fac,num_zeros;
	string s;

	cin>>t;

	for(i=0;i<t;i++)
	{
		cin>>s;
		ans=0;
		fac=1;

		for(j=0;j<s.length();)
		{
			if(s[j]=='1')
			{
				j=j+1;
				num_zeros=0;
				while(j<s.length() && s[j]=='0')
				{
					num_zeros++;
					j++;
				}

				if(num_zeros!=0)
					ans=ans  + fac*(num_zeros+1);

				fac++;

			}

			else
				j++;
			
				
		}

		cout<<ans<<endl;
	}


	return 0;
}