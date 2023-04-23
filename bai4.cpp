#include <bits/stdc++.h>

using namespace std;


int n;
int m;
vector <int>adj[100];
bool visited[100];


void input()
{
	cin>>n;
	cin>>m;
	
	for (int i =0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);

	}
	memset(visited,false,sizeof(visited));
	 
}


void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout<<"da tham "<<v<<" ";
		
		for (int x:adj[v])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}
int main()
{
	input();
	bfs(1);
	return 0;
}
