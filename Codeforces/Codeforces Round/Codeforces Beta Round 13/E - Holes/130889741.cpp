#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int blockSize = 350;
int n,_next[M],power[M],step[M];
void PreProcess()
    int b1,b2,i,idx;
    for(i=n;i;i--)
    {
        idx=i+power[i];
        if(idx > n)
        {
            _next[i]=i,step[i]=0;
            continue;
        }
        b1=(i+blockSize-1)/blockSize;
        b2=(idx+blockSize-1)/blockSize;
        if(b1 < b2)_next[i]=idx,step[i]=1;
        else _next[i]=_next[idx],step[i]=step[idx]+1;
    }
void Update(const int& i,const int& v)
    power[i]=v;
    int idx=i+v;
    if(idx > n)_next[i]=i,step[i]=0;
    else
    {
        int b1=(i+blockSize-1)/blockSize;
        int b2=(idx+blockSize-1)/blockSize;
        if(b1 < b2)_next[i]=idx,step[i]=1;
        else _next[i]=_next[idx],step[i]=step[idx]+1;
    }
    int j=((i-1)/blockSize)*blockSize;
    for(int k=i-1;k>j;k--)
    {
        if(k+power[k] <= n  &&  (k+power[k]+blockSize-1)/blockSize == (k+blockSize-1)/blockSize)step[k]=step[k+power[k]]+1,_next[k]=_next[k+power[k]];
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,op,q,x,y;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> power[i];
    PreProcess();
    while(q--)
    {
        cin >> op;
        if(!op)
        {
            cin >> x >> y;
            Update(x,y);
        }
        else
        {
            ans=1;
            cin >> i;
            while(i != _next[i])ans += step[i],i=_next[i];
            cout << i << ' ' << ans << '\n';
        }
    }
    return 0;
}