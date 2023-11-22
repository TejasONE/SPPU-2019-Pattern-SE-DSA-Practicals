/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify the 
prominent land marks as nodes and perform DFS and BFS on that.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() 
{
	int n; 
	char ch;
	cout<<"No. of nodes: ";
	cin>>n;

	string nodes[n];

	int adj_mat[n][n];

	for(int i=0;i<n;i++) 
	{
		cout<<"Enter nodes: ";
		cin>>nodes[i];
	}
	
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n;j++) 
		{
			cout<<"\nwhether there is edge between "<<nodes[i]<<" and "<<nodes[j]<<" ?\n(y/n): ";
			cin>>ch;

			if(ch=='y') 
			{
				adj_mat[i][j] = 1;
			} 			
			else 
			{
				adj_mat[i][j] = 0;
			}
		}
	}
	
	cout<<"\n\nThe adjacent matrix is\n\t";
	
	for(int i=0;i<n;i++) 
	cout<<nodes[i]<<"\t";
	
	cout<<endl;
	for(int i=0;i<n;i++) 
	{
		cout<<nodes[i]<<"\t";
		for(int j=0;j<n;j++)
		{
			cout<<adj_mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	
/*	cout<<"\n\nThe adjacency list is\n";
	for(int i=0;i<n;i++) 
	{
		cout<<nodes[i];
		for(int j=0;j<n;j++) 
		{
			if(adj_mat[i][j]==1) 
			{
				cout<<" --> "<<nodes[j];
			}
		}
		cout<<endl;
	}
*/
while(1) 
	{	
		int ch;
		cout<<"* * * * Menu * * * *\n";
		cout<<"\n1. BFS\n2. DFS\n3. Exit\nEnter your choice: ";
		cin>>ch;

		switch(ch) 
		{
			case 1:
			{
				int v;
				bool visited[n+1] = {};   //array named visited
				queue<int> q;
				cout<<"Starting vertex for bfs traversal: ";
				cin>>v;
				cout<<"\nThe bfs traversal is ";
				q.push(v);
				visited[v] = 1;

				while(!q.empty()) 
				{
					v = q.front();
					cout<<v<<" -> ";
					q.pop();
					for(int k=1;k<=n;k++) 
					{
						if(adj_mat[v][k] && !visited[k]) 
						{
							q.push(k);
							visited[k] = 1;
						}
					}
				}
				cout<<"\n\n";
			}
			break;		

			case 2:		// dfs traversal - - - - - - - - - - - - - - - - -
			{
				int v;
				bool visited[n+1] = {};
				stack<int>s;
				cout<<"Starting vertex for dfs traversal: ";
				cin>>v;
				cout<<"\nThe dfs traversal is ";
				s.push(v);
				visited[v] = 1;

				while(!s.empty()) 
				{
					v=s.top();
					cout<<v<<" -> ";
					s.pop();
					for(int k=1;k<=n;k++) 
					{
						if(adj_mat[v][k] && !visited[k]) 
						{
							s.push(k);
							visited[k]=1;
						}
					}
				}
				cout<<"\n\n";
			}
			break;

			case 3:		//Exit - - - - - - - - - - - - - - - - -
			cout<<"\n\n";
			return 0;
		}
	}
}
