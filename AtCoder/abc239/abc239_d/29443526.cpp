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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

bool mark[202];

void Sieve()
{
    int i,j;
    mark[1]=1;
    for(i=4;i<201;i+=2)mark[i]=1;
    for(i=3;i<200;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<200;j+=2*i)mark[j]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,cnt,d,i,j;
    Sieve();
    cin >> a >> b >> c >> d;
    for(i=a;i<=b;i++)
    {
        cnt=0;
        for(j=c;j<=d;j++)cnt += (mark[i+j] == 0);
        if(!cnt)
        {
            cout << "Takahashi";
            return 0;
        }
    }
    cout << "Aoki";
    return 0;
}
