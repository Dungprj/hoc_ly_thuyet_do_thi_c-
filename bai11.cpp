#include <bits/stdc++.h>

using namespace std;

bool visited[100];
vector <int> adj[100],r_adj[100];
stack<int> st;
int n,m;
void input()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
	
}
void dfs(int u)
{
	visited[u] = true;
	for (int x:adj[u])
	{
		if (!visited[x])
		{
			dfs(x);
		}
	}
	st.push(u);
}

void dfs2(int u)
{
	visited[u] = true;
	cout<<u<<" ";
	for (int x:r_adj[u])
	{
		if (!visited[x])
		{
			dfs2(x);
		}
	}
}

void SCC()
{
	int cnt = 0;
	vector <int> t;
	memset(visited,false,sizeof(visited));
	for (int i =1;i<=n;i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
	cout<<endl;
	memset(visited,false,sizeof(visited));
	while (!st.empty())
	{
		int u = st.top();st.pop();
		if (!visited[u])
		{
			t.push_back(u);
			++cnt;
			
			dfs2(u);
			cout<<endl;
		}
	}
	
	if (cnt == 1)
	{
		cout<<"yes"<<endl;
	}else
	{
		cout<<"no"<<endl;
		for (int x:t)cout<<x<<" ";
	}
}



int main()
{
	input();
	SCC();
	return 0;
}
