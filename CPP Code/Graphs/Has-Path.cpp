// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not.
// Print true or false.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G
#include <iostream>
#include<queue>
using namespace std;
bool has_path(int** edges,int V,int start,int end,bool* visited)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        if(first==end)
        {
            return true;
        }
        for(int i=0;i<V;i++)
        {
            if(i==start)
            {
                continue;
            }
            if(edges[first][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;

            }
        }

    }
    return false;
}
int main() {
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
    int start, end;
    cin>>start>>end;
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
	bool ans=has_path(edges,V,start,end,visited);
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
