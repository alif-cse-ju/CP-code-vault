#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,cnt;
    long long d,k,x,y;
    cin >> t;
    while(t--)
    {
        cin >> d >> k;
        x=y=cnt=0;
        while(true)
        {
            cnt=1-cnt;
            if(cnt & 1)x+=k;
            else y+=k;
            if(x*x + y*y > d*d)break;
        }
        if(cnt & 1)cout << "Utkarsh\n";
        else cout << "Ashish\n";
    }
    return 0;