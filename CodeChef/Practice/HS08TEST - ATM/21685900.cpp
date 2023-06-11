#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y;
    scanf("%lf %lf",&x,&y);
    int check=x;
    if(check%5 == 0 && x+.50<=y)
    {
        printf("%.2lf",y-x-.50);
    }
    else
    {
        printf("%.2lf",y);
    }
    return 0;
}