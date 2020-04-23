//In this code, we are going to build the Segment Tree, Update the array and get the query answer
#include<bits/stdc++.h>
using namespace std;
int querySegment(int* tree,int start,int end,int treeNode,int left,int right)
{
  if(start>right || end<left)
  {
    return 0;
  }
  if(start>=left && end<=right)
  {
    return tree[treeNode];
  }
  int mid=(start+end)/2;
  int ans1=querySegment(tree,start,mid,2*treeNode,left,right);
  int ans2=querySegment(tree,mid+1,end,2*treeNode+1,left,right);
  return ans1+ans2;
}
void updateSegment(int* arr,int* tree,int start,int end,int index,int value)
{
  if(start==end)
  {
    arr[index]=value;
    tree[treeNode]=value;
    return;
  }
  int mid=(start+end)/2;
  if(index>mid)
  {
    updateSegment(arr,tree,mid+1,end,index,value);
  }
  else
  {
    updateSegment(arr,tree,start,mid,index,value);
  }
  tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
void buildSegment(int* arr,int* tree,int start,int end,int treeNode)
{
  if(start==end)
  {
    tree[treeNode]=arr[start];
    return;
  }
  int mid=(start+end)/2;
  buildSegment(arr,tree,start,mid,2*treeNode);
  buildSegment(arr,tree,mid+1,end,2*treeNode+1);
  tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  int start=0;
  int end=n-1;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int tree[2*n];
  buildSegment(arr,tree,start,end,2*n);
  int index;
  cin>>index;
  int value;
  cin>>value;
  updateSegment(arr,tree,start,end,index,value);
  int start_index;
  int end_index;
  cin>>start_index;
  cin>>end_index;
  int ans=querySegment(tree,start,end,2*n,start_index,end_index);
  cout<<ans;
}
