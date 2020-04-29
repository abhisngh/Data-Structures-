// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
#include <iostream>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int start;
    int end;
    int weight;

};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int findParent(int V,int* parent)
{
    if(parent[V]==V)
    {
        return V;
    }
    return findParent(parent[V],parent);
}
void kruskal(Edge* input,int V,int E)
{
    sort(input,input+E,compare);
    Edge* output=new Edge[V-1];
    int* parent=new int[V];
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!=V-1)
    {
        Edge currentedge=input[i];
        int source=findParent(currentedge.start,parent);
        int dest=findParent(currentedge.end,parent);
        if(source!=dest)
        {
         output[count]=currentedge;
            count++;
            parent[source]=dest;
        }
        i++;
    }
    for(int i=0;i<V-1;i++)
    {
        if(output[i].start<output[i].end)
        {
            cout<<output[i].start<<" "<<output[i].end<<" "<<output[i].weight;
        }
        else
        {
             cout<<output[i].end<<" "<<output[i].start<<" "<<output[i].weight;
        }
        cout<<endl;
    }
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  Edge* e=new Edge[E];
  for(int i=0;i<E;i++)
  {
      int start, dest, w;
      cin>>start>>dest>>w;

      e[i].start=start;
      e[i].end=dest;
      e[i].weight=w;
  }
 kruskal(e,V,E);

  return 0;
}
