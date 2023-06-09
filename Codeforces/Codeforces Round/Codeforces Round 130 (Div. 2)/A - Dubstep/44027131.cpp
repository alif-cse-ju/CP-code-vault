#include <bits/stdc++.h>
using namespace std;
int main() {
 int i,l,flag=0;
 char c[205];
 scanf("%s",&c);
 l=strlen(c);
 for(i=0;i<l;i++)
 {
  if(c[i]=='W' && c[i+1]=='U' && c[i+2]=='B')
  {
   i=i+2;
   if(flag==5)
   {
    printf(" ");
   }
  }
  else
  {
   printf("%c",c[i]);
   flag=5;
  }
 }
 return 0;