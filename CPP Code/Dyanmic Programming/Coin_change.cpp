// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
// You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.
// Line 1 : Integer n i.e. total number of denominations
// Line 2 : N integers i.e. n denomination values
// Line 3 : Value V
#include<iostream>
using namespace std;
int coin_change(int numd,int* arr,int n,int** output)
{
  if(n==0)
  {
    return 1;
  }
  if(n<0)
  {
    return 0;
  }
  if(numd==0)
  {
    return 0;
  }
  if(output[numd][n]>-1)
  {
    return output[numd][n];
  }
  int first=coin_change(numd,arr,n-arr[0],output);
  int second=coin_change(numd-1,arr+1,n,output);
  output[numd][n]=first+second;
  return output[numd][n];
}
int main()
{
  int numd;
  cin>>numd;
  int* arr=new int[numd];

  for(int i=0;i<numd;i++)
  {
    cin>>arr[i];
  }
  int n;
  cin>>n;
  int** output=new int*[numd+1];
  for(int i=0;i<numd+1;i++)
  {
    output[i]=new int[n+1];
  }
  for(int i=0;i<numd+1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      output[i][j]=-1;
    }
  }
  int ans=coin_change(numd,arr,n,output);
  cout<<ans;
  delete [] arr;
  return 0;
}
