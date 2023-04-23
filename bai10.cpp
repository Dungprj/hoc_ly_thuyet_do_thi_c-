#include <bits/stdc++.h>

using namespace std;


int n,m,st;
int cuoi;
vector <int> adj[100];
int color[100];
int degree[100];




int inp()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		++degree[y];
//		adj[y].push_back(x);
		
	}

	
}

bool kahn()
{
	int cnt = 0;
	queue <int> q;
	for (int i = 1;i<=n;i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int v = q.front();q.pop();
		++cnt;
		for (int x:adj[v])
		{
			--degree[x];
			if (degree[x] ==0 )
			{
				q.push(x);
			}
			
		}
	}
	return cnt == n;
}

//bool BFS(int u)
//{
//
//	queue <int> q;
//	q.push(u);
//	
//	while (!q.empty())
//	{
//		int v = q.front();q.pop();
//		for (int x:adj[v])
//		{
//			if (!visited[x])
//			{
//				par[x] = v;
//				q.push(x);
//				visited[x] = true;
//				
//			}else if (x != par[v])
//			{
//				st = x;
//				cuoi = v;
//				return true;
//			}
//		}
//		return false;
//	}
//}
int main()
{
	inp();
	
	
	
	
		if (kahn() ) 
		{
			cout<<"no"<<endl;
			
		}else
		{
			cout<<"yes"<<endl;
		}
	

	return 0;
}
