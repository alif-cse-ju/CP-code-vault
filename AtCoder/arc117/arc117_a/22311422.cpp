#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    FAST();
    int a,b,i,sum=0;
    vector<int>A,B;
    cin >> a >> b;
    if(a == b)
    {
        for(i=1;i<=a;i++)cout << i << ' ' << -i << ' ';
        return 0;
    }
    if(a < b)
    {
        for(i=1;i<=b;i++)B.emplace_back(-i);
        for(i=1;i<a;i++)A.emplace_back(i);
        --i;
        while(i < b)sum+=B[i++];
        A.emplace_back(-sum);
    }
    else
    {
        for(i=1;i<=a;i++)A.emplace_back(i);
        for(i=1;i<b;i++)B.emplace_back(-i);
        --i;
        while(i < a)sum+=A[i++];
        B.emplace_back(-sum);
    }
    for(int it : A)cout << it << ' ';
    for(int it : B)cout << it << ' ';
    return 0;
}
