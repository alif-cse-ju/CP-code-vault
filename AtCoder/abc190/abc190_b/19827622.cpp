#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool flag=0;
    int d,i,n,s,x,y;
    cin >> n >> s >> d;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        if(x < s  &&  y > d)flag=1;
    }
    if(flag)cout << "Yes";
    else cout << "No";
    return 0;
}