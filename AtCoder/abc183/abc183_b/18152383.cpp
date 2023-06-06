#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    y2*=(-1.0);
    cout << fixed << setprecision(10) << x1+((-y1)*(x1-x2))/(y1-y2);
    return 0;
}
