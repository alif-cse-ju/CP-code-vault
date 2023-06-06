#include<bits/stdc++.h>

using namespace std;

const int N=3e5;
int col[N+2],row[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,n,q,x,y,mxC=0,mxR=0;
    map<pair<int,int>,bool>mp;
    cin >> n >> m >> q;
    while(q--)
    {
        cin >> x >> y;
        mp[{x,y}]=1;
        mxC=max(mxC,++col[y]);
        mxR=max(mxR,++row[x]);
    }
    vector<int>c,r;
    for(int i=1;i<=n;i++)
    {
        if(row[i] == mxR)r.emplace_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(col[i] == mxC)c.emplace_back(i);
    }
    for(int i : r)
    {
        for(int j : c)
        {
            if(mp.find({i,j}) == mp.end())
                {
                    cout << mxC+mxR;
                    return 0;
                }
        }
    }
    cout << mxC+mxR-1;
    return 0;
}