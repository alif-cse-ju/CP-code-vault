#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    FAST();
    int t;
    long long a,x,y;
    cin >> t;
    while(t--)
    {
        cin >> a >> y >> x;
        if(y <= a)cout << x*y << '\n';
        else cout << a*x+1 << '\n';
    }
    return 0;
}