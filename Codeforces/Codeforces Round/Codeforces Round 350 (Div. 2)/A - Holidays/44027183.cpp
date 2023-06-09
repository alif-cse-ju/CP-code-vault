#include <bits/stdc++.h>
using namespace std;
int main() {
 long long int n,min,max;
 scanf("%lld",&n);
 min=(n/7)*2;
 max=min;
 if(n%7==6)
 {
  min++;
 }
 if(n%7>=2)
 {
  max=max+2;
 }
 else
 {
  max+=n%7;
 }
 printf("%lld %lld",min,max);
 return 0;