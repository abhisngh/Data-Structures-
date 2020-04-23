// Samantha and Sam are playing a numbers game. Given a number as a string, no leading zeros, determine the sum of
// all integer values of substrings of the string.
// For example, if the string is 42 , the substrings are 4,2 and 42.
// Their sum is 48.
// Given an integer as a string, sum all of its substrings cast as integers.
// As the number may become large, return the value modulo .
#include<bits/stdc++.h>
using namespace std;
#define 1000000007
int sum_subtring(string n)
{
  long long int sum=n[0]-'0';
  long long int last=n[0]-'0';
  for(int i=1;i<n.length();i++)
  {
    last=last*10+(n[i]-'0')*(i+1);
    last=last%mod;
    sum=(sum+last)%mod;
  }
  return sum;
}
int main()
{
  string n;
  cin>>n;
  int ans=sum_subtring(n);
  cout<<ans;
  return 0;
}
