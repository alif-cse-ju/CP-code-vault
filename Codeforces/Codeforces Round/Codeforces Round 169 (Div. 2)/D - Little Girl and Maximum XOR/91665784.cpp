#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    long long i,l,r,ans=0,pos=-1;
    cin >> l >> r;
    for(i=62;i>=0;i--)
    {
        if(((l >> i) & 1LL)  &&  ((r >> i) & 1LL))continue;
        if((r >> i) & 1)
        {
            pos=i;
            break;
        }
    }
    for(i=pos;i>=0;i--)ans|=(1LL << i);
    cout << ans;
    return 0;