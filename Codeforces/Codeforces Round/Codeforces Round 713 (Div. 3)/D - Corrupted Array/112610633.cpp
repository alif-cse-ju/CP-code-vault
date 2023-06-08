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
bool mark[N];
long long b[N];
int main()
    FAST();
    int i,n,t;
    long long sum,temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        n+=2,sum=0;
        map<long long,int>mp;
        for(i=1;i<=n;i++)cin >> b[i];
        sort(b+1,b+n+1);
        for(i=1;i<=n;i++)
        {
            sum+=b[i];
            mark[i]=1;
            mp[b[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            temp=sum-b[i];
            if(temp%2ll == 0ll)
            {
                temp/=2ll;
                if(mp.find(temp) != mp.end()  &&  mp[temp] != i)
                {
                    mark[i]=mark[mp[temp]]=0;
                    break;
                }
            }
        }
        if(i > n)cout << "-1\n";
        else
        {
            for(i=1;i<=n;i++)
            {
                if(mark[i])cout << b[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}