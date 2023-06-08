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
    bool pos;
    string s;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        vector<int>M,T;
        for(i=0;i<l;i++)
        {
            if(s[i] == 'M')M.emplace_back(i);
            else T.emplace_back(i);
        }
        if((int)M.size()*2 != (int)T.size())pos=0;
        else pos=1;
        l=(int)M.size();
        for(i=0;i<l  &&  pos;i++)
        {
            if(M[i] < T[i])pos=0;
        }
        for(i=0;i<l  &&  pos;i++)
        {
            if(T[i+l] < M[i])pos=0;
        }
        if(pos)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}