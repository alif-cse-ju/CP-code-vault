#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    string s;
    int i,l,t;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        vector<int>pos;
        for(i=0;i<l;i++)
        {
            if(s[i] == '*')pos.emplace_back(i);
        }
        l=(int)pos.size();
        if(!l)cout << "0\n";
        else
        {
            ans=0;
            for(i=1;l/2-i>=0;i++)ans+=abs(pos[l/2-i]-(pos[l/2]-i));
            for(i=1;l/2+i<l;i++)ans+=abs(pos[l/2+i]-(pos[l/2]+i));
            cout << ans << '\n';
        }
    }
    return 0;
}