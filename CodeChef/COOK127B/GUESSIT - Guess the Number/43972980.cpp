#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int cnt[N];
vector<int>v;
void PreCal()
{
    int i,j;
    for(i=1;i<N;i++)
    {
        for(j=i;j<N;j+=i)++cnt[j];
        if(cnt[i] & 1)v.emplace_back(i);
    }
}
int main()
{
    FAST();
    PreCal();
    int t,x;
    cin >> t;
    while(t--)
    {
        for(int it : v)
        {
            cout << it << endl;
            cin >> x;
            if(x)break;
        }
    }
    return 0;
}