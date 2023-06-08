#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,int>mp;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(mp.find(x) == mp.end())mp[x]=i;
            else mp[x]=-1;
        }
        for(auto it : mp)
        {
            if(it.second > 0)
            {
                cout << it.second << '\n';
                break;
            }
        }
    }
    return 0;
}