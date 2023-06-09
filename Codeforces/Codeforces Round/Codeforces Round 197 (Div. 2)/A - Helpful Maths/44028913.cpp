#include <bits/stdc++.h>
using namespace std;
int main() {
 int a[100],i,j=0,l;
 char c[110];
 scanf("%s",&c);
 l=strlen(c);
 for(i=0;i<l;i+=2)
 {
  a[j]=c[i]-'0';
  j++;
 }
 sort(a,a+j);
 printf("%d",a[0]);
 for(i=1;i<j;i++)
 {
  printf("+%d",a[i]);
 }
 return 0;