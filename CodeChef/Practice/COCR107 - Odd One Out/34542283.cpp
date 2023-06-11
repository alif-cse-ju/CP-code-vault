#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int n,a[100002];
bitset<2001>temp,em,cnt[100002];
void Update(int i,int idx)
{
    while(i <= n)
    {
        cnt[i][idx]=cnt[i][idx]^1;
        i+=i & (-i);
    }
}
bitset<2001>Query(int i)
{
    bitset<2001>sum=em;
    while(i > 0)
    {
        sum^=cnt[i];
        i-=i & (-i);
    }
    return sum;
}
int main()
{
    FAST();
    int i,l,r,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i]=em;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            Update(i,a[i]);
        }
        cin >> q;
        while(q--)
        {
            cin >>  x >> l >> r;
            ++l,++r;
            if(!x)
            {
                Update(l,a[l]);Update(r,a[l]);
                Update(l,a[r]);Update(r,a[r]);
                swap(a[l],a[r]);
            }
            else
            {
                if(l <= r)
                {
                    temp=Query(r);
                    temp^=Query(l-1);
                }
                else
                {
                    temp=Query(n);
                    temp^=Query(l-1);
                    temp^=Query(r);
                }
                cout << temp.count() << '\n';
            }
        }
    }
    return 0;
}