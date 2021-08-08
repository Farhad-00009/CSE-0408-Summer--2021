#include <bits/stdc++.h>
using namespace std;
int V,E;
int parent[100];
int cost [1000][10000];
int find(int i)
{

	while (parent[i] != i)
        i = parent[i];
    return i;
}


void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}


void BFsMST()
{
	int mincost = 0;
	int edge_count = 0;
	while (edge_count < V - 1)
    {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
            {
				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
        cout<<"Edge "<<edge_count++<<":("<<a<<" "<<b<<") cost:"<<min<<endl;
		mincost += min;
	}
	cout<<endl<<"Minimum cost= "<<mincost;
}


int main()
{



    //freopen("input.txt","r",stdin);

    //cin>>V>>E;

	V=8;
	E=9;
    for(int i=0;i<V;i++)
    {
        for(int j=0; j<V; j++)
        {
            cost[i][j]= INT_MAX;
        }
    }

    /*for(int j = 0;j<E;j++)
    {
        int m,n;
        cin>>m>>n;
        cin>>cost[m][n];
        //cost[n][m];
    }*/
cost[0][1]=1;
cost[0][2]=2;
cost[2][3]=3;
cost[3][5]=5;
cost[3][4]=4;
cost[5][4]=100;
cost[5][6]=7;
cost[6][7]=101;
cost[4][7]=8;
    for (int i = 0; i < V; i++)
        parent[i] = i;

	/// Print the solution
	BFsMST();
	return 0;
}
