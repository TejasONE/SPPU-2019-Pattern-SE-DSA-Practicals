/*
There  are  flight  paths  between  cities.  If  there  is  a  flight  between  
city  A  and  city  B  then there is an edge between the cities. 
The cost of the edge can be the time that flight take to 
reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. 
The  node  can  be  represented  by  airport  name  or  name  of  the  city.  Use  adjacency  list 
representation  of  the  graph  or  use  adjacency  matrix  representation  of  the  graph.  Check 
whether the graph is connected or not. Justify the storage representation used. 
*/

#include <iostream>
using namespace std;

class graph
{
    public:
	int n;
	char ch;
    string nodes[20];
    int adj_mat[20][20];

    void getdata();
    void display();
};


void graph :: getdata()
{
    cout<<"Number of nodes : \n";
	cin>>n;
	
	for(int i=0;i<n;i++) 
	{
		cout<<"Enter nodes : ";
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
				int dist;
				cout<<"\nEnter the distance : ";
				cin>>dist;
				adj_mat[i][j] = dist;
			} 			
			else 
			{
				adj_mat[i][j]=0;
			}
		}
	}
}	

void graph :: display()
{
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
int main()
{
    graph g;

    g.getdata();
    g.display();

    return 0;
}