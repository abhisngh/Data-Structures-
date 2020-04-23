// Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
// A subsequence of a string S whose length is n, is a string containing characters in same relative order as they
// are present in S,
// but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n.
// E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
#include<bits/stdc++.h>
using namespace std;
int lcshelper(char* a,char* b,int m,int n,int** dp)
{
  if(m==0||n==0)
  {
    return 0;
  }
  if(dp[m][n]>-1)
  {
    return dp[m][n];
  }
  int ans;
  if(s1[0]==s2[0])
  {
    ans=1+lcshelper(a+1,b+1,m-1,n-1,dp);
  }
  else
  {
    int option1=lcshelper(a+1,b,m-1,n,dp);
    int option2=lcshelper(a,b+1,m,n-1,dp);
    ans=max(option1,option2);
  }
  dp[m][n]=ans;
  return ans;
}
int lcs(string s1,string s2)
{
  int m=s1.length();
  int n=s2.length();
  char a[m];
  char b[n];
  for(int i=0;i<m;i++)
  {
    a[i]=s1[i];
  }
  for(int i=0;i<n;i++)
  {
    b[i]=s2[i];
  }
  int** dp=new int*[m+1];
  for(int i=0;i<m+1;i++)
  {
    dp[i]=new int[n+1];
    for(int j=0;j<n+1;j++)
    {
      dp[i][j]=-1;
    }
  }
  int ans=lcshelper(a,b,m,n,dp);
  for(int i=0;i<m+1;i++)
  {
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}
int main()
{
  string s1;
  string s2;
  cin>>s1>>s2;
  int ans=lcs(s1,s2);
  return 0;
}
