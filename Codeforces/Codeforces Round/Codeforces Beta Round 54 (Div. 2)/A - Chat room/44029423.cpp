#include <bits/stdc++.h>
using namespace std;
int main() {
 int i,l,h=0,e=0,l1=0,l2=0,o=0;
 char c[110];
 scanf("%s",&c);
 l=strlen(c);
 for(i=0;i<l;i++)
 {
  if(c[i]=='h')
  {
   h=1;
  }
  else if(c[i]=='e' && h==1)
  {
   e=1;
  }
  else if(c[i]=='l' && h==1 && e==1 && l1==0)
  {
   l1=1;
  }
  else if(c[i]=='l' && h==1 && e==1 && l1==1)
  {
   l2=1;
  }
  else if(c[i]=='o' && h==1 && e==1 && l1==1 && l2==1)
  {
   o=1;
   break;
  }
 }
 if(h==1 && e==1 && l1==1 && l2==1 && o==1)
 {
  printf("YES");
 }
 else
 {
  printf("NO");
 }
 return 0;
}