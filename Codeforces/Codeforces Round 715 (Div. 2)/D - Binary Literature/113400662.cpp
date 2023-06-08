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
char s[4][N];
int cnt[5][2];
void Calc(const int& l)
    int i;
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=l*2;i++)
    {
        if(s[1][i] == '0')++cnt[1][0];
        else ++cnt[1][1];
        if(s[2][i] == '0')++cnt[2][0];
        else ++cnt[2][1];
        if(s[3][i] == '0')++cnt[3][0];
        else ++cnt[3][1];
    }
void Solve(int x,int y,int val,const int& l)
    int i,j,len;
    string ans;
    vector<int>v1,v2;
    v1.emplace_back(0);
    v2.emplace_back(0);
    for(i=1;i<=l*2;i++)
    {
        if(s[x][i] == (char)('0'+val))v1.emplace_back(i);
        if(s[y][i] == (char)('0'+val))v2.emplace_back(i);
    }
    while((int)v1.size() < (int)v2.size())v1.emplace_back(l*2 + 1);
    while((int)v2.size() < (int)v1.size())v2.emplace_back(l*2 + 1);
    v1.emplace_back(l*2 + 1);
    v2.emplace_back(l*2 + 1);
    len=(int)v1.size();
    for(i=1;i<len;i++)
    {
        for(j=0;j<max(v1[i]-v1[i-1],v2[i]-v2[i-1])-1;j++)ans+=(char)('1'-val);
        ans+=(char)('0'+val);
    }
    ans.pop_back();
    cout << ans << '\n';
}
 bool Solve0(const int& l)
{
    if(cnt[1][0] >= l  &&  cnt[2][0] >= l)
    {
        Solve(1,2,0,l);
        return 1;
    }
    if(cnt[1][0] >= l  &&  cnt[3][0] >= l)
    {
        Solve(1,3,0,l);
        return 1;
    }
    if(cnt[2][0] >= l  &&  cnt[3][0] >= l)
    {
        Solve(2,3,0,l);
        return 1;
    }
    return 0;
}
 void Solve1(const int& l)
{
    if(cnt[1][1] >= l  &&  cnt[2][1] >= l)
    {
        Solve(1,2,1,l);
        return;
    }
    if(cnt[1][1] >= l  &&  cnt[3][1] >= l)
    {
        Solve(1,3,1,l);
        return;
    }
    Solve(2,3,1,l);
}
 int main()
{
    FAST();
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l;
        for(i=1;i<4;i++)cin >> s[i]+1;
        Calc(l);
        if(!Solve0(l))Solve1(l);
    }
    return 0;
}