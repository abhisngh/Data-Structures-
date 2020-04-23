// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers),
// find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
#include <iostream>
#include<vector>

using namespace std;

void get_path(int** edges,int V,int start,int end,bool* visited,vector<int>* output)
{
    if(start==end)
    {
        output->push_back(end);
        return;
    }
    visited[start]=true;
    for(int i=0;i<V;i++)
    {
        if(i==start)
        {
            continue;
        }
        if(visited[i]!=true && edges[i][start]==1)
        {
            visited[i]=true;
            get_path(edges,V,i,end,visited,output);
        if(output->size()!=0)
        {
            output->push_back(start);
            return;
        }

        }

    }
}

int main()
{
  int V, E;
  cin >> V >> E;
 int** edges=new int*[V];
 for(int i=0;i<V;i++)
 {
     edges[i]=new int[V];
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
    int start,end;
    cin>>start>>end;

    vector<int> output;
    get_path(edges,V,start,end,visited,&output);

    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }

    delete [] visited;
    for(int i=0;i<V;i++)
    {
      delete [] edges[i];
    }
    delete [] edges;

  return 0;
}
