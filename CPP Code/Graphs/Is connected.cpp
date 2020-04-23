// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
#include <iostream>
using namespace std;
void print_dfs(int** edges,int n,int si,bool* visited)
{
  visited[si]=true;
  for(int i=0;i<n;i++)
  {
    if(i==si)
    {
      continue;
    }
    if(edges[si][i]==1)
    {
      if(visited[i]==1)
      {
        continue;
      }
      print_dfs(edges,n,i,visited);
    }
  }
}
int main()
{
  int V,E; //no of vertices
  cin>>V>>E;
  int** edges=new int*[V];
  for(int i=0;i<V;i++)
  {
    edges[i]=new int[V];
    for(int j=0;j<V;j++)
    {
      edges[i][j]=0;
    }
  }
   //edges
  for(int i=0;i<E;i++)
  {
    int first_v, second_v;
    cin>>first_v>>second_v;
    edges[first_v][second_v]=edges[second_v][first_v]=1;
  }
  bool* visited=new bool[V];
  for(int i=0;i<V;i++)
  {
    visited[i]=false;
  }
  int startindex=0;
  print_dfs(edges,V,startindex,visited);
    bool ans=true;
     for(int i=0;i<V;i++)
  {
     if(!visited[i])
     {
         ans=false;
     }
  }
    if(ans)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    delete [] visited;
  for(int i=0;i<V;i++)
  {
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
