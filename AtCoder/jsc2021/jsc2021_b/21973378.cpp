#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;

int a[M],b[M];
bool mark[2][M];

int main()
{
    FAST();
    int i,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        mark[0][a[i]]=1;
    }
    for(i=1;i<=m;i++)
    {
        cin >> b[i];
        mark[1][b[i]]=1;
    }
    vector<int>ans;
    for(i=1;i<=n;i++)
    {
        if(!mark[1][a[i]])ans.emplace_back(a[i]);
    }
    for(i=1;i<=m;i++)
    {
        if(!mark[0][b[i]])ans.emplace_back(b[i]);
    }
    sort(ans.begin(),ans.end());
    for(int it : ans)cout << it << ' ';
    return 0;
}
