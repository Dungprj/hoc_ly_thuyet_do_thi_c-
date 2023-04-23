#include <bits/stdc++.h>

using namespace std;


struct edge
{
	int u,v;
	int w;
};

const int maxn = 100;
int n,m;
int parent[maxn],sz[maxn];
vector <edge> canh;
void make_set()
{
	for (int i = 1;i<=n;i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}


int find(int v)
{
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a,int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
	{
		return false;//khong the gop 
	}
	if (sz[a] < sz[b]) swap(a,b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

void inp()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		int x,y,w;cin>>x>>y>>w;
		edge e;
		e.u = x;
		e.v = y;
		e.w = w;
		canh.push_back(e);
	}
}
bool  cmp(edge a, edge b)
{
	return a.w < b.w;//sx tang dan
}
void kruskal()
{
	vector <edge> mst;
	int d = 0;
	//sort danh sach canh theo chieu dai tang dan
	sort(canh.begin(),canh.end(),cmp);
	for (int i = 0;i<m;i++)
	{
		if(mst.size() == n-1) break;
		edge e = canh[i];
		if (Union(e.u,e.v))
		{
			mst.push_back(e);
			d+=e.w;
		}
	}
	
	if (mst.size()!= n-1)
	{
		cout<<"Do thi khong lien thong "<<endl;
	}else
	{
		cout<<"mst : "<<d<<endl;
		for (auto it:mst)
		{
			cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
			
		}
	}
}
int main()
{
	
	inp();
	make_set();
	kruskal();
	return 0;
}
