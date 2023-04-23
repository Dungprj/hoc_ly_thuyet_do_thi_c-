#include <bits/stdc++.h>

using namespace std;


int st,en,n,m;
int par[100];
int visited[100];

vector <int> adj[100];



bool dfs(int u)
{
	visited[u] = true;
	
	for (int x:adj[u])
	{
		par[x] = u;
		if (!visited[x])
		{
			if (dfs(x))return true;
			
		}else
		{
			if (x != par[u])
			{
				st = x;
				en = u;
				return true;
			}
		}
	}
	return false;
}

void input()
{
	cin>>n>>m;
	
	for (int i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
}

int main()
{
	input();
	for (int i = 1;i<=n;i++)
	{
		if (!visited[i]) 
		{
			if (dfs(i))
			{
					cout<<"co vong lap "<<endl;
				vector <int> circle;
				while (en != st)
				{
					circle.push_back(en);
					en = par[en];
				}
				circle.push_back(st);
				cout<<"st = "<<st<<endl;
				cout<<"end = "<<en<<endl;		
				for (int x:circle)
				{
					cout<<x<<"->";
				}
			return 0;
			}
			
			
		}else
		{
			cout<<"no"<<endl;
		}	
	}
	
	return 0;
}
