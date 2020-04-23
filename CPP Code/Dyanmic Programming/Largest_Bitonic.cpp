#include<iostream>
using namespace std;
int lbs(int* arr,int size)
{
  //First find LIS
  int* lis=new int[size];
  lis[0]=1;
  for(int i=1;i<size;i++)
  {
    lis[i]=1;
    for(int j=i-1;j>=0;j--)
    {
      if(arr[j]>=arr[i])
      {
        continue;
      }
      int possible_ans=lis[j]+1;
      if(possible_ans>lis[i])
      {
        lis[i]=possible_ans;
      }
    }
  }
  //Now Longest Increasing from back i.e longest decreasing
  int* lds=new int[size];
  lds[size-1]=1;
  for(int i=size-2;i>=0;i--)
  {
    lds[i]=1;
    for(int j=i+1;j<size;j++)
    {
      if(arr[j]>=arr[i])
      {
        continue;
      }
      int possible_ans=lds[j]+1;
      if(possible_ans>lds[i])
      {
        lds[i]=possible_ans;
      }
    }
    }
    int best=lis[0]+lds[0]-1;
    for(int i=1;i<size;i++)
    {
      if(best<lis[i]+lds[i]-1)
      {
        best=lis[i]+lds[i]-1;
      }
    }
    delete [] lis;
    delete [] lds;
    return best;
}
int main()
{
  int n;
  cin>>n;
  int* arr=new int[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int ans=lbs(arr,n);
  cout<<ans;
  delete [] arr;
}
