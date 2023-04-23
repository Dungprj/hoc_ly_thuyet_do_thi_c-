#include <bits/stdc++.h>


using namespace std;

int main()
{
	int m;
	cout<<"M :"<<endl;cin>>m;
	vector <int> adj[100];
	cin.ignore();
	for (int i = 1;i<=m;i++)
	{
		string s;
		getline(cin,s);
		stringstream ss(s);
		string word;
		while (ss>>word)
		{
			if (i<stoi(word))
			{
				adj[i].push_back(stoi(word));
			}
			
		}
	}
	
	
	for (int i = 1;i<=m;i++)
	{
		for (int x:adj[i])
		{
			cout<<i <<" "<<x<<endl;
		}
	}
	
	
}
