#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
bool ans[N],mark[N];
int k,n,a[N],table[N][22],lg[N];
void Build()
   int i,j;
   lg[1]=0;
   k=log2(n)+1;
   for(i=0;i<n;i++)table[i][0]=a[i];
   for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;
   for(j=1;j<=k;j++)
   {
       for(i=0;i+(1 << j)<=n;i++)table[i][j]=min(table[i][j-1],table[i+(1 << (j-1))][j-1]);
   }
int Query(int l,int r)
    int j=lg[r-l+1];
    return min(table[l][j],table[r-(1 << j)+1][j]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,r,t,pos;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)mark[i]=ans[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            mark[a[i]]=1;
        }
        Build();
        l=2,r=n,pos=n+1;
        while(l <= r)
        {
            m=(l+r) >> 1;
            set<int>st;
            for(i=m;i<=n;i++)st.insert(Query(i-m,i-1));
            if((int)st.size() == n-m+1  &&  *(st.begin()) == 1  &&  *(--st.end()) == (int)st.size())pos=m,r=m-1;
            else l=m+1;
        }
        for(i=pos;i<=n;i++)ans[i]=1;
        for(i=1;i<=n;i++)
        {
            if(!mark[i])break;
        }
        if(i > n)ans[1]=1;
        for(i=1;i<=n;i++)cout << ans[i];
        cout << '\n';
    }
    return 0;
}