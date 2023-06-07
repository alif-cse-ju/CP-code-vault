#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,a[N];
int main()
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  int pntl=0;
  for(int i=1;i<=n;i++) if(!a[i]) {pntl=i;break;}
  int pntr=n+1;
  for(int i=n;i;i--) if(!a[i]) {pntr=i;break;}
  if(!pntl) puts("0");
  else printf("%d\n",pntr-pntl+2);
 }