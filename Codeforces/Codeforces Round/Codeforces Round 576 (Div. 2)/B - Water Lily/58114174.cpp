#include<bits/stdc++.h>
using namespace std;
int main()
    double h,l;
    scanf("%lf %lf",&h,&l);
    double ans=(l*l-h*h)/(2.0*h);
    printf("%.13lf",ans);
    return 0;