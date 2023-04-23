#include <bits/stdc++.h>

using namespace std;



int m;
int n;


vector <int> adj[100];
bool visited[100];


void input()
{
	cout<<"M :"<<endl;
	cin>>m;
	cout<<"n : "<<endl;
	cin>>n;
	for (int i = 0;i<m;i++)
	{
		int x;
		int y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	memset(visited,false,sizeof(visited));
}

void dfs(int u)
	{
		cout<<"dang tham "<<u<<endl;
		visited[u] = true;
		for (int x:adj[u])
		{
			if (!visited[x])
			{
				dfs(x); 
			}
		}
	}


int main()
{
	
	input();
	dfs(1);
	return 0;
}
