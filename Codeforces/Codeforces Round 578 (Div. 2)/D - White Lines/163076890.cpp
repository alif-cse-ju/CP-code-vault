#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz = 2e3+5;

char s[sz];
int k,n,LC[sz],LR[sz],RC[sz],RR[sz],col[sz][sz],row[sz][sz];

void Update(int l1,int r1,int l2,int r2,bool _row)
{
        if(_row)
        {
                for(int i=l1;i<=l2;i++)++row[i][r1], --row[i][r2+1];
        }
        else
        {
                for(int i=l1;i<=l2;i++)++col[i][r1], --col[i][r2+1];
        }
}

int Query(int i,int j,bool _row)
{
        int ans=0;
        if(_row)ans = row[i][j];
        else ans = col[i][j];
        return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
            cin >> s+1;
            for(int j=1;j<=n;j++)
            {
                    if(s[j] == 'B')
                    {
                            if(!LC[j])LC[j]=i;
                            RC[j]=i;

                            if(!LR[i])LR[i]=j;
                            RR[i]=j;
                    }
            }
    }

    for(int i=1;i<=n;i++)
    {
            if(!LR[i])Update(1,1,n,n,1);
            else if(RR[i]-LR[i] >= k)continue;
            else Update(max(1, i-k+1), max(1, RR[i]-k+1), min(i, n-k+1), min(LR[i], n-k+1), 1);
    }

    for(int i=1;i<=n;i++)
    {
            if(!LC[i])Update(1,1,n,n,0);
            else if(RC[i]-LC[i] >= k)continue;
            else Update(max(1, RC[i]-k+1), max(1, i-k+1), min(LC[i], n-k+1), min(i,n-k+1), 0);
    }

    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)row[i][j] += row[i][j-1], col[i][j] += col[i][j-1];
    }

    int ans=0;
    for(int i=1;i+k-1<=n;i++)
    {
            for(int j=1;j+k-1<=n;j++)ans=max(ans, Query(i,j,1)+Query(i,j,0));
    }
    cout << ans;
    return 0;
}
