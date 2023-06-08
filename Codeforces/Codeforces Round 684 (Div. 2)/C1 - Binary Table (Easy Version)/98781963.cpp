#include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;
const int mod=1e9+7;
 struct Data
{
    int x1,x2,x3,y1,y2,y3;
};
 vector<Data>ans;
char s[102][102];
 void Solve(vector<pair<int,int>>&v0,vector<pair<int,int>>&v1)
{
    if((int)v0.size() == 4)return;
    Data temp;
    if((int)v1.size() == 4)
    {
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v1[1].first,temp.y2=v1[1].second;
        temp.x3=v1[2].first,temp.y3=v1[2].second;
        ans.emplace_back(temp);
        temp.x1=v1[1].first,temp.y1=v1[1].second;
        temp.x2=v1[2].first,temp.y2=v1[2].second;
        temp.x3=v1[3].first,temp.y3=v1[3].second;
        ans.emplace_back(temp);
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v1[1].first,temp.y2=v1[1].second;
        temp.x3=v1[3].first,temp.y3=v1[3].second;
        ans.emplace_back(temp);
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v1[2].first,temp.y2=v1[2].second;
        temp.x3=v1[3].first,temp.y3=v1[3].second;
        ans.emplace_back(temp);
    }
    else if((int)v1.size() == 3)
    {
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v1[1].first,temp.y2=v1[1].second;
        temp.x3=v1[2].first,temp.y3=v1[2].second;
        ans.emplace_back(temp);
    }
    else if((int)v1.size() == 2)
    {
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v0[0].first,temp.y2=v0[0].second;
        temp.x3=v0[1].first,temp.y3=v0[1].second;
        ans.emplace_back(temp);
        temp.x1=v1[1].first,temp.y1=v1[1].second;
        temp.x2=v0[0].first,temp.y2=v0[0].second;
        temp.x3=v0[1].first,temp.y3=v0[1].second;
        ans.emplace_back(temp);
    }
    else
    {
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v0[0].first,temp.y2=v0[0].second;
        temp.x3=v0[1].first,temp.y3=v0[1].second;
        ans.emplace_back(temp);
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v0[0].first,temp.y2=v0[0].second;
        temp.x3=v0[2].first,temp.y3=v0[2].second;
        ans.emplace_back(temp);
        temp.x1=v1[0].first,temp.y1=v1[0].second;
        temp.x2=v0[1].first,temp.y2=v0[1].second;
        temp.x3=v0[2].first,temp.y3=v0[2].second;
        ans.emplace_back(temp);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> s[i]+1;
        ans.clear();
        for(i=2;i<=n;i+=2)
        {
            for(j=2;j<=m;j+=2)
            {
                vector<pair<int,int>>v0,v1;
                if(s[i-1][j-1] == '0')v0.emplace_back(i-1,j-1);
                else v1.emplace_back(i-1,j-1);
                if(s[i-1][j] == '0')v0.emplace_back(i-1,j);
                else v1.emplace_back(i-1,j);
                if(s[i][j-1] == '0')v0.emplace_back(i,j-1);
                else v1.emplace_back(i,j-1);
                if(s[i][j] == '0')v0.emplace_back(i,j);
                else v1.emplace_back(i,j);
                Solve(v0,v1);
                s[i-1][j-1]=s[i-1][j]=s[i][j-1]=s[i][j]='0';
            }
        }
        if(m & 1)
        {
            for(i=2;i<=n;i+=2)
            {
                vector<pair<int,int>>v0,v1;
                if(s[i-1][m-1] == '0')v0.emplace_back(i-1,m-1);
                else v1.emplace_back(i-1,m-1);
                if(s[i-1][m] == '0')v0.emplace_back(i-1,m);
                else v1.emplace_back(i-1,m);
                if(s[i][m-1] == '0')v0.emplace_back(i,m-1);
                else v1.emplace_back(i,m-1);
                if(s[i][m] == '0')v0.emplace_back(i,m);
                else v1.emplace_back(i,m);
                Solve(v0,v1);
                s[i-1][m-1]=s[i-1][m]=s[i][m-1]=s[i][m]='0';
            }
        }
        if(n & 1)
        {
            for(j=2;j<=m;j+=2)
            {
                vector<pair<int,int>>v0,v1;
                if(s[n-1][j-1] == '0')v0.emplace_back(n-1,j-1);
                else v1.emplace_back(n-1,j-1);
                if(s[n-1][j] == '0')v0.emplace_back(n-1,j);
                else v1.emplace_back(n-1,j);
                if(s[n][j-1] == '0')v0.emplace_back(n,j-1);
                else v1.emplace_back(n,j-1);
                if(s[n][j] == '0')v0.emplace_back(n,j);
                else v1.emplace_back(n,j);
                Solve(v0,v1);
                s[n-1][j-1]=s[n-1][j]=s[n][j-1]=s[n][j]='0';
            }
        }
        if((n & 1)  &&  (m & 1))
        {
            vector<pair<int,int>>v0,v1;
            if(s[n-1][m-1] == '0')v0.emplace_back(n-1,m-1);
            else v1.emplace_back(n-1,m-1);
            if(s[n-1][m] == '0')v0.emplace_back(n-1,m);
            else v1.emplace_back(n-1,m);
            if(s[n][m-1] == '0')v0.emplace_back(n,m-1);
            else v1.emplace_back(n,m-1);
            if(s[n][m] == '0')v0.emplace_back(n,m);
            else v1.emplace_back(n,m);
            Solve(v0,v1);
        }
        cout << (int)ans.size() << '\n';
        for(Data it : ans)cout << it.x1 << ' ' << it.y1 << ' ' << it.x2 << ' ' << it.y2 << ' ' << it.x3 << ' ' << it.y3 << '\n';
    }
    return 0;
}