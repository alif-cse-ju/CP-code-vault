#include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;
const int mod=1e9+7;
 int a[102][102];
 struct Data
{
    int x1,x2,x3,y1,y2,y3;
};
 vector<Data>ans;
 void Change(int x1,int y1,int x2,int y2,int x3,int y3)
{
    Data temp;
    temp.x1=x1,temp.y1=y1;
    temp.x2=x2,temp.y2=y2;
    temp.x3=x3,temp.y3=y3;
    ans.emplace_back(temp);
    a[x1][y1] ^= 1;
    a[x2][y2] ^= 1;
    a[x3][y3] ^= 1;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    char c;
    int i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin >> c;
                a[i][j]=(c-'0');
            }
        }
       ans.clear();
       for(i=n;i>2;i--)
       {
           for(j=1;j<=m;j++)
           {
               if(a[i][j])
               {
                   if(j > 1)Change(i,j,i-1,j,i-1,j-1);
                   else Change(i,j,i-1,j,i-1,j+1);
               }
           }
       }
       for(i=m;i>2;i--)
       {
           if(a[1][i])Change(1,i,1,i-1,2,i-1);
           if(a[2][i])Change(2,i,2,i-1,1,i-1);
       }
       if(a[2][2])Change(1,2,2,1,2,2);
       if(a[1][1]+a[1][2]+a[2][1] == 3)Change(1,1,1,2,2,1);
       else if(a[1][1]+a[1][2] == 2)Change(1,1,2,1,2,2),Change(1,2,2,1,2,2);
       else if(a[1][1]+a[2][1] == 2)Change(1,1,1,2,2,2),Change(2,1,1,2,2,2);
       else if(a[2][1]+a[1][2] == 2)Change(2,1,1,1,2,2),Change(1,2,1,1,2,2);
       else if(a[1][1])
       {
           Change(1,1,1,2,2,1);
           Change(1,1,1,2,2,2);
           Change(1,1,2,2,2,1);
       }
       else if(a[1][2])
       {
           Change(1,2,1,1,2,2);
           Change(1,2,1,1,2,1);
           Change(1,2,2,1,2,2);
       }
       else if(a[2][1])
       {
           Change(2,1,2,2,1,1);
           Change(2,1,2,2,1,2);
           Change(2,1,1,2,1,1);
       }
       cout << (int)ans.size() << '\n';
       for(Data it : ans)cout << it.x1 << ' ' << it.y1 << ' ' << it.x2 << ' ' << it.y2 << ' ' << it.x3 << ' ' << it.y3 << '\n';
    }
    return 0;
}