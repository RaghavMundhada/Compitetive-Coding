#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long int
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pii pair<int,int>

void genPrimes(vector<int>& primes,int k)
{
	/*
		Generates all the primes numbers less than equal to k
		complexity:O(n)
		pass empty vector<int> primes
	*/
	
	int i,j;
	bool isprime;
	primes.push_back(2);
	for(i=3;i<=k;i=i+2)
	{
		int cap = sqrt(i)+1;
		isprime=true;
		for(j=0;j<primes.size();j++)
		{
			if(primes[j]>=cap)break;

			if(i%primes[j]==0)
			{
				isprime=false;
				break;
			}
		}

		if(isprime	)
			primes.pb(i);
	}
}

void getPrimeFactors(ll a,ll b,vector<int>& primes,vector<vector<int> >& primeFactors)
{
	ll i,j,k;
	ll st;
	vector<vector<int> > t(b-a+1);

	for(i=0;i<primes.size();i++)
	{
		st = (a/primes[i])*primes[i];

		if(st<a)
			st=st+primes[i];

		while(st<=b)
		{
			t[st-a].pb(primes[i]);
			st=st+primes[i];
		}
	}

	for(i=a;i<=b;i++)
	{
		k=i;

		for(j=0;j<t[i-a].size();j++)
		{
			while(k%t[i-a][j]==0)
			{
				primeFactors[i-a].pb(t[i-a][j]);
				k=k/t[i-a][j];
			}
		}
		if(k!=1)
			primeFactors[i-a].pb(k);
	}


}

int main()
{	
	vector<int> primes;
	multiset<int,greater<int> > s;

	genPrimes(primes,1000000);

	ll i,j,k;
	ll a,b;

	cin>>a>>b;
	vector<vector<int> > primeFactors(b-a+1);

	ll ans=0;
	ll prod=1;

	getPrimeFactors(a,b,primes,primeFactors);

	for(i=a;i<=b;i++)
	{
		k=1;

		for(j=0;j<primeFactors[i-a].size();j++)
		{
			if(j+1<primeFactors[i-a].size() && primeFactors[i-a][j]==primeFactors[i-a][j+1])
				k++;

			else
			{
				s.insert(k);
				prod=prod*(k+1);
				k=1;
			}
		}
		ans = ans + prod - 1;

		while(!s.empty())
		{
			k=*(s.begin());
			prod = (prod/(k+1))*(k);
			s.erase(s.begin());

			if(k>1)
				s.insert(k-1);

			ans = ans + prod;

		}
		s.clear();
	}
	cout<<ans<<endl;
	return 0;
}