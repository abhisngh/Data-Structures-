// Given two strings s and t of lengths m and n respectively,
// find the Edit Distance between the strings. Edit Distance of two strings is minimum number of
// steps required to make one string equal to other.
// In order to do so you can perform following three operations only :
// 1. Delete a character
//
// 2. Replace a character with another one
//
// 3. Insert a character
#include<bits/stdc++.h>
using namespace std;
int editDistancehelper(char* a,char* b,int m,int n,int** dp)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    if(dp[m][n]>-1)
    {
        return dp[m][n];
    }
    int ans;
    if(a[0]==b[0])
    {
        ans=editDistancehelper(a+1,b+1,m-1,n-1,dp);
    }
    else
    {
        int option1=1+editDistancehelper(a+1,b+1,m-1,n-1,dp);
        int option2=1+editDistancehelper(a+1,b,m-1,n,dp);
        int option3=1+editDistancehelper(a,b+1,m,n-1,dp);
        ans=min(option1,min(option2,option3));
    }
    dp[m][n]=ans;
    return ans;
}
int editDistance(string s1, string s2){

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
    int ans=editDistancehelper(a,b,m,n,dp);
    for(int i=0;i<m+1;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int ans=editDistance(s1,s2);
  return ans;
  return 0;
}
