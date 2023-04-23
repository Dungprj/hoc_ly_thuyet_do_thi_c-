#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector <int> adj[100];

bool visited[100];

void dfs(int u)
{
	visited[u] = true;
	cout<<u<<" ";
	for (int x:adj[u])
	{
		if (!visited[x])
		{
			dfs(x);
		}
	}
}

void bfs(int u)
{
	queue <int> q;
	q.push(u);
	
	visited[u] = true;
	while (!q.empty())
	{
		
		int v = q.front();q.pop();
		cout<<v<<" ";
		for (int x:adj[v])
		{
			if (!visited[x] )
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}


void connectedComponent()
{
	int ans = 0;
	memset(visited,false,sizeof(visited));
	for (int i = 1;i<=n;i++)
	{
		if (!visited[i])
		{
			++ans;
			cout<<"cac dinh thuoc thanh phan lien thong thu"<<ans<<endl;
			bfs(i);
		}
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		int x,y;cin>>x>>y; 
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	connectedComponent();
	return 0;
}
