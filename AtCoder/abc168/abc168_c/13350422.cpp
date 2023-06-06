#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    double a,b,c,h,m,angle;
    cin >> a >> b >> h >> m;
    h*=30,h+=m*0.5,m*=6;
    angle=min(abs(h-m),360-abs(h-m));
    c=a*a+b*b-2.0*a*b*cos((PI/180.0)*angle);
    cout << fixed << setprecision(15) << sqrt(c);
    return 0;
}
