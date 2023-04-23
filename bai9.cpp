#include <bits/stdc++.h>

using namespace std;


const int maxn = 100;
int n,m;
int in[maxn];
vector <int>adj[maxn];
bool visited[maxn];

vector <int>topo;



void kahm()
{
	queue <int> q;
	for (int i = 1;i<=n;i++)
	{
		if (in[i]==0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int v = q.front();q.pop();
		topo.push_back(v);
		for (int x: adj[v])
		{
			--in[x];
			if (in[x] == 0)
			{
				q.push(x);
			}
		}
	}
	
	for (int x:topo)
	{
		cout<<x<<" ";
	}
}
void dfs_topo(int u)
{
	visited[u] = true;
	for (int x:adj[u])
	{
		if (!visited[x])
		{
			dfs_topo(x);
		}
	}
	topo.push_back(u);
	
}

void inp()
{
	cin>>n>>m;
	for (int i =0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		++in[y];
		
	}
	memset(visited,false,sizeof(visited));
	
	
	
	
}
int main()
{
	inp();
	kahm();
	
	return 0;
}
