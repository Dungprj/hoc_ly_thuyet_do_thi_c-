#include <bits/stdc++.h>


using namespace std;



int n;
int m;
int x1,y1,x2,y2;
char a[100][100];

int dx[8] ={-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int d[100][100];

bool visited[100][100];

void dfs(int i,int j)
{
	cout<<i<<" "<<j<<endl;
	visited[i][j] = true;
	for (int k = 0;k<4;k++)
	{
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]=='x'&&!visited[i1][j1])
		{
			dfs(i1,j1);
		}
	}	
}

bool dfs2(int i,int j)
{
	cout<<i<<" "<<j<<endl;
	if (a[i][j] == 'B')
	{
		cout<<"da thay"<<endl;
		return true;
	}
	visited[i][j] = true;
	for (int k =0;k<8;k++)
	{
		int i1 = i+ dx[k];
		int j1 = j + dy[k];
		
		if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1] != 'x'&&!visited[i1][j1])
		{
			
			if (dfs2(i1,j1)) return true;
		}
		
	}
	return false;
}

void bfs(int i ,int j)
{
	queue<pair<int ,int>>q;
	q.push({i,j});
	visited[i][j] = true;
	cout<<i<<" "<<j<<endl;
	while (!q.empty())
	{
		pair<int,int> top = q.front();q.pop();
		for (int k = 0;k<4;k++)
		{
			int i1 = top.first+dx[k];
			int j1 = top.second+dy[k];
			if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1] == 'x'&&!visited[i1][j1])
			{
				cout<<i1<<" "<<j1<<endl;
				q.push({i1,j1});
				visited[i1][j1] = true;
			}
		}
	}
}

void bfs2(int i ,int j)
{
	queue<pair<int,int>> q;
	q.push({i,j});
	visited[i][j] = true;
	cout<<i<<" "<<j<<endl;
	d[i][j] = 0;
	while (!q.empty())
	{
		pair <int,int> v = q.front();q.pop();
		for (int k = 0;k<8;k++)
		{
			int i1 = v.first+ dx[k];
			int j1 = v.second +dy[k];
			if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1] != 'x'&&!visited[i1][j1])
			{
				cout<<"queue dang co "<<"x = "<<v.first<<"y = "<<v.second<<endl;
				
				cout<<"i = "<<i1<<" "<<"j = "<<j1<<endl;
				d[i1][j1] = d[v.first][v.second]+1;
				cout<<"d["<<i1<<"]["<<j1<<"] = "<<d[i1][j1]<<endl;
				if (a[i1][j1] =='B')return ;
					
				q.push({i1,j1});
				visited[i1][j1] = true;
				
			}
		}
	}
}

int input()
{
	cin>>n>>m;
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=m;j++)
		{
			cin>>a[i][j];
			
		}
	}
	memset(visited,false,sizeof(visited));
	
	int cnt = 0;
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=m;j++)
		{
			if (a[i][j] =='x'&& !visited[i][j])
			{
				cout<<"thanh phan lien thong thu "<<cnt+1<<":"<<endl;
				bfs(i,j);
				++cnt;
				
				
			}
		}
	}
	cout<<cnt<<endl;
}

void input2()
{
	cin>>n>>m;
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j<=m;j++)
		{
			cin>>a[i][j];
			if (a[i][j] =='A')
			{
				x1 = i;
				y1 = j;
			}else if (a[i][j] == 'B')
			{
				x2 = i;
				y2 = j;
			}
		}
	}
	memset(visited,false,sizeof(visited));
	if (dfs2(x1,y1))
	{
		cout<<"co duong di "<<endl;
	}else 
	{
		cout<<"no";
	}
	

}
int main()
{
	input2();

	return 0;
}
