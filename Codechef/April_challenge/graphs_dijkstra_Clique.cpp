#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f

class Graph
{
public:
    int V;    
    list< pair<long long int, long long int> > *adj;
    vector<long long int> dist;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
 
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<long long int, long long int> >[V];
    dist.resize(V, INF);
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::shortestPath(int src)
{
    set< pair<long long int, long long int> > setds;
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    while (!setds.empty())
    {
        pair<long long int, long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        long long int u = tmp.second;
 
        list< pair<long long int, long long int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            long long int v = (*i).first;
            long long int weight = (*i).second;
 
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
}

int main()
{
	int t,n,k,x,m,s,a,b,c,i,p,q;
	cin>>t;

	while(t--)
	{
		cin>>n>>k>>x>>m>>s;
		Graph g(n);

		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			g.addEdge(a-1,b-1,c);
		}

		g.shortestPath(s-1);
		long long int mi=g.dist[0];

		for(i=1;i<k;i++)
			mi = min(mi,g.dist[i]);
		mi=mi+x;
		for(i=0;i<k;i++)
		{
			g.dist[i] = min(g.dist[i],mi);
			if(s-1!=i)
				g.addEdge(s-1,i,g.dist[i]);
		}
		
		for(i=0;i<n;i++)
			g.dist[i]=INF;

		g.shortestPath(s-1);
		for(i=0;i<n;i++)
			cout<<g.dist[i]<<" ";

		cout<<endl;

	}
	return 0;
}

