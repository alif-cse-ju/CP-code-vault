#include<bits/stdc++.h>

using namespace std;

long long MAX=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,n,x,y;
    map<long long,int>mp3,mp5;
    x=1,y=0;
    while(x*3LL <= MAX)
    {
        x*=3LL;
        mp3[x]=++y;
    }
    x=1,y=0;
    while(x*5LL <= MAX)
    {
        x*=5LL;
        mp5[x]=++y;
    }
    cin >> n;
    for(auto it : mp3)
    {
        x=it.first;
        y=it.second;
        if(x > n)break;
        if(mp5.find(n-x) != mp5.end())
        {
            cout << y << ' ' << mp5[n-x];
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
