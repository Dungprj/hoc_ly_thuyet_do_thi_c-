#include <bits/stdc++.h>

using namespace std;


int n,m;

map <string,int> size; 

map <string,string> parent;



struct point
{
	string ten;
	double x,y;
	
	point()
	{
		
	}
	void input()
	{
		cout<<"Nhap ten cho diem :"<<endl;
		getline(cin,this->ten);
		cout<<"Nhap x : "<<endl;
		cin>>this->x;
		cin.ignore();
		cout<<"Nhap y : "<<endl;
		cin>>this->y;
		cin.ignore();
	}
	void out()
	{
		cout<<"ten : "<<this->ten<<endl;
		cout<<"x : "<<this->x<<endl;
		cout<<"y : "<<this->y<<endl;
	}
	double getdodai(point a)
	{
		return abs(sqrt(pow(a.x-this->x,2)+pow(a.y-this->y,2)));
	}
	
};
vector <point> pnt;
struct edge
{
	point u,v;
	
	double w;
	
};
vector <edge> canh;
void make_set()
{
	
	for (int i = 1;i<=n;i++)
	{
		parent[pnt[i].ten] = pnt[i].ten;
		size[pnt[i].ten] = 1;
	}
}
string find(string v)
{
	if (v == parent[v])return v;
	return parent[v] = find(parent[v]);
}

bool Union(string a,string b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (size[a] < size[b]) swap(a,b);
	parent[b] = a;
	size[a] +=size[b];
	return true;
}


void input()
{
	cin>>n;
	cin.ignore();
	cin>>m;
	cin.ignore();
	
	for (int i = 0;i<m;i++)
	{
		point u,v;
		double w;
		u.input();
		v.input();
		pnt.push_back(u);
		pnt.push_back(v);
		w = u.getdodai(v);
		edge tmp;
		tmp.u = u;tmp.v = v;tmp.w = w;
		canh.push_back(tmp);	
	}
	
	
}

bool cmp(edge a ,edge b)
{
	return a.w < b.w;
}


void kruskal()
{
	//tao cay khung rong
	vector <edge> mst;
	int d = 0;//bien do trong so cua cay khung cuc tieu
	//sap xep danh sach canh theo trong so tang dan
	sort(canh.begin(),canh.end(),cmp);
	for (int i = 0;i<m;i++)
	{
		if (mst.size() == n-1)break;
		edge tmp;
		tmp = canh[i];
		if (Union(tmp.u.ten,tmp.v.ten))
		{
			mst.push_back(tmp);
			d+=tmp.w;
		}
	}
	if (mst.size()!= n-1)
	{
		cout<<"do thi khong lien thong"<<endl;
	}else
	{
		cout<<"MST co do dai la : "<<d<<endl;
		for (auto it:mst)
		{
			cout<<"("<<it.u.x<<","<<it.u.y<<")"<<" "<<"("<<it.v.x<<","<<it.v.y<<")"<<"do dai la : "<<it.w<<endl;
		}
	}
	
	
}



int main()
{
	input();
	make_set();
	kruskal();
}
