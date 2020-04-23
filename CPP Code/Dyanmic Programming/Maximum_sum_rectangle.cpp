// Given a 2D array, find the maximum sum rectangle in it.
// In other words find maximum sum over all rectangles in the matrix.
#include<iostream>
using namespace std;
int maximum_sub(int* arr,int size)
{
  int curr_max=0;
  int pre_max=INT_MIN;
  for(int i=0;i<size;i++)
  {
    curr_max+=arr[i];
    if(curr_max>pre_max)
    {
      pre_max=curr_max;
    }
    if(curr_max<0)
    {
      curr_max=0;
    }
  }
  if(pre_max>0)
  {
    return pre_max;
  }
  return -1;
}
int main()
{
  int n,m;
  cin>>n>>m;
  int arr[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>arr[i][j];
    }
  }
  int maximum_sum=INT_MIN;
  int pre_max=0;
  int sum[n];
  for(int j=0;j<m;j++)
  {
    memset(sum,0,sizeof(sum));
    for(int i=j;i<m;i++)
    {
      for(int k=0;k<n;k++)
      {
        sum[k]+=arr[k][i];
      }
      pre_max=maximum_sub(sum,n);
      if(pre_max>maximum_sum)
      {
        maximum_sum=pre_max;
      }

    }
  }
  cout<<maximum_sum<<endl;
  return 0;
}
