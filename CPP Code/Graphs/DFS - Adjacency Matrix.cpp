//DFS Implementation through Adjacency Matrix
#include<iostream>
using namespace std;
void print_dfs(int** edges,int n,int si,bool* visited)
{
  cout<<si<<endl;
  visited[si]=true;
  for(int i=0;i<n;i++)
  {
    if(i==si)
    {
      continue;
    }
    if(edges[siUpdate ][i]==1)
    {
      if(visited[i]==1)
      {
        continue;
      }
      print(edges,n,i,visited);
    }
  }
}
int main()
{
  int n; //no of vertices
  cin>>n;
  int** edges=new int*[n];
  for(int i=0;i<n;i++)
  {
    edges[i]=new int[n];
    for(int j=0;j<n;j++)
    {
      edges[i][j]=0;
    }
  }
  int e; //edges
  for(int i=0;i<e;i++)
  {
    int first_v, second_v;
    cin>>first_v>>second_v;
    edges[first_v][second_v]=edges[second_v][first_v]=1;
  }
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=false;
  }
  int startindex=0;
  print_dfs(edges,n,startindex,visited);
  // For Disconnected components
  for(int i=0;i<V;i++)
  {
    if(!visited[i])
    {
      print_dfs(edges,V,i,visited);
    }
  }
  delete [] visited;
  for(int i=0;i<n;i++)
  {
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
