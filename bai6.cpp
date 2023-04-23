#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100];
int parent[100];
bool visited[100]; 
int t,s,m,n;

void dfs(int u)
{
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[x])
		{
			parent[x] = u; 
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
		int v = q.front();
		q.pop();
		
		for (int x:adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] =true;
				parent[x] = v;
			}
		}
	}
}


void path(int s,int t)
{
	memset(visited,false,sizeof(visited));
	memset(parent,0,sizeof(parent));
	bfs(s);
	if (!visited[t])
	{
		cout<<"khong co duong di"<<endl;
	}else
	{
		vector <int> path;
		while (t!=s)
		{
			path.push_back(t);
			t=parent[t];
		}
		path.push_back(t);
		reverse(path.begin(),path.end());
		
		for (int x:path)
		{
			cout<<x<<"->";
		}
	}
}
int main()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
//		adj[y].push_back(x);	
	}
	cin>>s>>t;
	path(s,t);
	return 0;
}
