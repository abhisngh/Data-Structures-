// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components.
// And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space).
// Order of different components doesn't matter.
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> bfs_check(int** edges,int V,int start,bool* visited,vector<int> temp)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int first=q.front();
        temp.push_back(first);
        q.pop();
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
    return temp;
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
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    vector<int> vec;
	for(int i=0;i<V;i++)
    {
        vector<int> temp;
        if(!visited[i])
        {
            vec=(bfs_check(edges,V,i,visited,temp));
        }
        sort(vec.begin(),vec.end());
    	for(int i=0;i<vec.size();i++)
    	{
        cout<<vec[i]<<" ";
    	}
        vec.clear();
        cout<<endl;
    }

    delete [] visited;
    for(int i=0;i<V;i++)
    {
      delete [] edges[i];
    }
    delete [] edges;
  return 0;
}
