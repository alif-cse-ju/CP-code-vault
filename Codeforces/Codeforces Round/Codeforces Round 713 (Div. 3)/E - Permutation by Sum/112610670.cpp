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
int a[505],b[505];
int main()
    FAST();
    int i,j,l,n,r,s,t,cnt,temp,dhon;
    cin >> t;
    while(t--)
    {
        set<int>st;
        cin >> n >> l >> r >> s;
        for(i=1;i<=n;i++)a[i]=n-i+1,st.insert(i),b[i]=0;
        cnt=r-l+1;
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            dhon=s,temp=cnt;
            for(j=i;j<=n;j++)
            {
                if(dhon-a[j] >= (temp*(temp-1))/2)
                {
                    v.emplace_back(a[j]);
                    --temp,dhon-=a[j];
                }
            }
            if(dhon == 0  &&  (int)v.size() == cnt)break;
            v.clear();
        }
        if(v.empty())
        {
            cout << "-1\n";
            continue;
        }
        for(i=l;i<=r;i++)
        {
            b[i]=v.back();
            st.erase(v.back());
            v.pop_back();
        }
        i=1;
        while(!st.empty())
        {
            temp=*(st.begin());
            st.erase(temp);
            while(b[i])i++;
            b[i]=temp;
        }
        for(i=1;i<=n;i++)cout << b[i] << ' ';
        cout << '\n';
    }
    return 0;
}