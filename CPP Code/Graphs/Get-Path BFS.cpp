// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers),
// find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

void get_path(int** edges,int V,int start,int end,bool* visited,vector<int>* output)
{
    if(start==end)
    {
        output->push_back(end);
        return;
    }
    queue<int> q;
    q.push(start);
    visited[start]=true;
    unordered_map<int,int> map;
    int first;
    while(!q.empty() )
    { first=q.front();
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(i==first)
            {
                continue;
            }
            if(!visited[i] && edges[first][i]==1)
            {
                visited[i]=true;
                map[i]=first;

                q.push(i);
            }
            int temp=q.front();
            if(temp==end)
            {
                break;
            }
        }
    }
    unordered_map<int,int>:: iterator it;
    it = map.find(end);
    if(it==map.end())
    {
        return; //not find
    }

    int i=end;
    output->push_back(i);
    while(i!=start)
    {
        i=map[i];
        output->push_back(i);
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
  for(int i=0;i<n;i++)
  {
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
