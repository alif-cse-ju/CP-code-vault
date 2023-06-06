#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=4e5+5;
const int mod=1e9+7;

char s[N];

int main()
{
    FAST();
    bool tgl=0;
    int i,n,q,t,x,y;
    cin >> n >> s+1 >> q;
    while(q--)
    {
        cin >> t >> x >> y;
        if(t == 1)
        {
            if(!tgl)swap(s[x],s[y]);
            else
            {
                if(x <= n)x+=n;
                else x-=n;
                if(y <= n)y+=n;
                else y-=n;
                swap(s[x],s[y]);
            }
        }
        else tgl=1-tgl;
    }
    if(tgl)
    {
        for(i=n+1;i<=2*n;i++)cout << s[i];
        for(i=1;i<=n;i++)cout << s[i];
    }
    else
    {
        for(i=1;i<=n;i++)cout << s[i];
        for(i=n+1;i<=2*n;i++)cout << s[i];
    }
    return 0;
}
