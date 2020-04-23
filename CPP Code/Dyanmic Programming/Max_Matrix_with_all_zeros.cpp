// Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s.
// You need to return the size of square with all 0s.
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){

int dp[row][col];
for(int i=0;i<row;i++)
{
    if(arr[i][0]==0)
    {
        dp[i][0]=1;
    }
    else
    {
        dp[i][0]=0;
    }
}
for(int j=0;j<col;j++)
{
    if(arr[0][j]==0)
    {
        dp[0][j]=1;
    }
    else
    {
        dp[0][j]=0;
    }
}
for(int i=1;i<row;i++)
{
    for(int j=1;j<col;j++)
    {

        if(arr[i][j]==1)
        {
            dp[i][j]=0;
        }
        else
        {
            dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;

        }
    }
}
int m=-1;
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
      if(m<dp[i][j])
      {
          m=dp[i][j];
      }
    }
}
return m;
}
int main()
{
  int row,col;
  cin>>row>>col;
  int arr[row][col];
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      cin>>arr[i][j];
    }
  }
  int ans=findMaxSquareWithAllZeros(arr,row,col);
  cout<<ans;
  return 0;
}
