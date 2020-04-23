// Implementation of the BFS using Adjacency Matrix
#include <iostream>
#include<queue>
using namespace std;
void print_bfs(int** edges,int V,int si,bool* visited)
{
    queue<int> q;
    q.push(si);
    while(!q.empty())
    {
       int first=q.front();
        cout<<first<<" ";
        visited[first]=true;
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(i==first)
            {
                continue;
            }
            if(edges[first][i]==1)
            {
                if(visited[i]==false)
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;

 int** edges=new int*[V];
for(int i=0;i<V;i++)
{ edges[i]=new int[V];
    for(int j=0;j<V;j++)
    {
        edges[i][j]=0;
    }
}
    for(int i=0;i<E;i++)
    {
        int first,second;
        cin>>first>>second;
        edges[first][second]=edges[second][first]=1;
    }
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
print_bfs(edges,V,0,visited);
//For Disconnected components
for(int i=0;i<V;i++)
{
    if(!visited[i])
    {
        print_bfs(edges,V,i,visited);
    }
}
    delete [] visited;
	for(int i=0;i<V;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
  return 0;
}
