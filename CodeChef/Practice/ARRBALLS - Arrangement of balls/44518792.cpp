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
    int n,t,x,cnt0,cnt1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt0=cnt1=0;
        while(n--)
        {
            cin >> x;
            cnt1+=x;
            cnt0+=(1-x);
        }
        while(cnt0--)cout << '0';
        while(cnt1--)cout << '1';
        cout << '\n';
    }
    return 0;
}
//