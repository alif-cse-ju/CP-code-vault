#include<bits/stdc++.h>
using namespace std;
int a[105];
vector<int>idx;
int Ask(int l,int r,int cur)
{
    int x;
    cout << "? " << r-l+2 << ' ';
    for(int i=l-1;i<r;i++)cout << idx[i] << ' ';
    cout << cur << endl;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,r,t,q,x;
    a[1]=1;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        idx.clear();
        idx.emplace_back(1);
        for(i=2;i<=n;i++)
        {
            l=1,r=(int)idx.size();
            x=Ask(l,r,i);
            if(x == 1)a[i]=++r,idx.emplace_back(i);
            else
            {
                while(l < r)
                {
                    m=(l+r) >> 1;
                    x=Ask(l,m,i);
                    if(x == 2)r=m;
                    else l=m+1;
                }
                a[i]=a[idx[l-1]];
            }
        }
        cout << "!";
        for(i=1;i<=n;i++)cout << ' ' << a[i];
        cout << endl;
        cin >> x;
        if(x == -1)return 0;
    }
    return 0;
}