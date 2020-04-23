// You are given a magrid S ( a magic grid ) having R rows and C columns.
// Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat,
// or a flask of magic potion that his teacher Snape has left for him.
// A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j].
// If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
// Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j),
// Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid.
// Harry has used magic before starting his journey to determine which cell contains what,
// but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone.
// Please help him once again.

#include<iostream>
using namespace std;
int magic_grid(int** arr,int n,int m)
{
  int** dp=new int*[n];
  for(int i=0;i<n;i++)
  {
    dp[i]=new int[m];
  }
  if(arr[n-1][m-1]<0)
  {
      dp[n-1][m-1]=abs(arr[n-1][m-1])+1;
  }
  else
  {
  dp[n-1][m-1]=1;
  }

  for(int i=n-2;i>=0;--i)
  {
    dp[i][m-1]=max(dp[i+1][m-1]-arr[i][m-1],1);
  }
  for(int j=m-2;j>=0;--j)
  {
    dp[n-1][j]=max(dp[n-1][j+1]-arr[n-1][j],1);
  }
  for(int i=n-2;i>=0;--i)
  {
    for(int j=m-2;j>=0;--j)
    {
    int m1=min(dp[i+1][j],dp[i][j+1]);
      dp[i][j]=max(m1-arr[i][j],1);

    }
  }
  int ans=dp[0][0];
  return ans;
}
int main()
{
  int t;//test case
  cin>>t;
  while(t-->0)
  {
    int n,m;
    cin>>n>>m;
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
      arr[i]=new int[m];
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        cin>>arr[i][j];
      }
    }
    int ans=magic_grid(arr,n,m);
    cout<<ans<<endl;

  }

}
