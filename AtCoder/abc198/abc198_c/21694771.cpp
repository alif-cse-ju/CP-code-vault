#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long r,x,y,z,rt;
    cin >> r >> x >> y;
    z=x*x+y*y;
    rt=sqrt(z);
    if(rt*rt == z  &&  rt%r == 0)cout << rt/r;
    else cout << (rt-r)/r+2;
    return 0;
}