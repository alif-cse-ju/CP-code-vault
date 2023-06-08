#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=3e5+5;
const int mod=1e9+9;
const int blockSize = 3500;
int n,numOfBlocks;
vector<int>updates[M/blockSize+2];
ll a[M],fib[M],fibSum[M],block[M/blockSize+2];
void FibPreCal()
    fib[0]=fib[1]=1;
    fibSum[0]=1,fibSum[1]=2;
    for(int i=2;i<n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i] >= mod)fib[i] -= mod;
        fibSum[i]=fibSum[i-1]+fib[i];
        if(fibSum[i] >= mod)fibSum[i] -= mod;
    }
ll FibQuery(int l,int r)
    ll ans=fibSum[r];
    if(l)ans -= fibSum[l-1];
    if(ans < 0)ans += mod;
    return ans;
void PreProcess()
    int i,blockIndex=-1;
    for(i=0;i<n;i++)
    {
        if(i%blockSize == 0)++blockIndex;
        block[blockIndex]+=a[i];
        if(block[blockIndex] >= mod)block[blockIndex] -= mod;
    }
    numOfBlocks=blockIndex;
}
 void Update(const int l,const int r)
{
    int i,_ll,_rr,blockL=l/blockSize,blockR=r/blockSize;
    if(blockL == blockR)
    {
        for(i=l;i<=r;i++)
        {
            a[i] = a[i]+fib[i-l];
            if(a[i] >= mod)a[i] -= mod;
            block[blockL] = block[blockL]+fib[i-l];
            if(block[blockL] >= mod)block[blockL] -= mod;
        }
    }
    else
    {
        for(i=l;i<(blockL+1)*blockSize;i++)
        {
            a[i] = a[i]+fib[i-l];
            if(a[i] >= mod)a[i] -= mod;
            block[blockL] = block[blockL]+fib[i-l];
            if(block[blockL] >= mod)block[blockL] -= mod;
        }
        for(i=blockL+1;i<blockR;i++)
        {
            updates[i].emplace_back(l);
            _ll=i*blockSize,_rr=_ll+blockSize-1;
            block[i] = block[i]+FibQuery(_ll-l,_rr-l);
            if(block[i] >= mod)block[i] -= mod;
         }
        for(i=blockR*blockSize;i<=r;i++)
        {
            a[i] = a[i]+fib[i-l];
            if(a[i] >= mod)a[i] -= mod;
            block[blockR] = block[blockR]+fib[i-l];
            if(block[blockR] >= mod)block[blockR] -= mod;
        }
    }
}
 ll Query(const int l,const int r)
{
    ll sum=0;
    int i,m,blockL=l/blockSize,blockR=r/blockSize;
    if(blockL == blockR)
    {
        for(i=l;i<=r;i++)
        {
            sum = sum+a[i];
            if(sum >= mod)sum -= mod;
            for(int it : updates[blockL])
            {
                sum = sum+fib[i-it];
                if(sum >= mod)sum -= mod;
            }
        }
    }
    else
    {
        m=min(n,(blockL+1)*blockSize);
        for(i=blockL*blockSize;i<m;i++)
        {
            for(int it : updates[blockL])
            {
                a[i] = a[i]+fib[i-it];
                if(a[i] >= mod)a[i] -= mod;
            }
            if(i < l)continue;
            sum = sum+a[i];
            if(sum >= mod)sum -= mod;
        }
        updates[blockL].clear();
        for(i=blockL+1;i<blockR;i++)
        {
            sum = sum+block[i];
            if(sum >= mod)sum -= mod;
        }
        if(r >= blockR*blockSize)
        {
            m=min(n,(blockR+1)*blockSize);
            for(i=blockR*blockSize;i<m;i++)
            {
                for(int it : updates[blockR])
                {
                    a[i] = a[i]+fib[i-it];
                    if(a[i] >= mod)a[i] -= mod;
                }
                if(i > r)continue;
                sum = sum+a[i];
                if(sum >= mod)sum -= mod;
            }
            updates[blockR].clear();
        }
    }
    return sum;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,q,op,r;
    cin >> n >> q;
    for(i=0;i<n;i++)cin >> a[i];
    FibPreCal();
    PreProcess();
    while(q--)
    {
        cin >> op >> l >> r;
        --l,--r;
        if(op == 1)Update(l,r);
        else cout << Query(l,r) << '\n';
    }
    return 0;
}