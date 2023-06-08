#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define N 100005
using namespace std;
int a[N];
int main()
 int i,n,m;
 scanf("%d %d",&n,&m);
 for(i=1;i<=n;++i)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 for(i=n;i;--i)
  if(m>a[i])m-=a[i];
  else{printf("%d\n",n-i+1);return 0;}
 return 0;