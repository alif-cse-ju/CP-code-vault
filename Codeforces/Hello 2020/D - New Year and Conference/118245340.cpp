#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
set<int>pointsA,pointsB;
int aL[M],aR[M],bL[M],bR[M];
map<int,vector<int>>Ain,Aout,Bin,Bout;
bool Check1()
    multiset<int>mstL,mstR;
    for(int p : pointsA)
    {
        for(int it : Aout[p])
        {
            mstL.erase(mstL.find(bL[it]));
            mstR.erase(mstR.find(bR[it]));
        }
        for(int it : Ain[p])
        {
            mstL.insert(bL[it]);
            mstR.insert(bR[it]);
        }
        if(!mstL.empty())
        {
            if(*(mstR.begin()) < *(--mstL.end()))return 1;
        }
    }
    return 0;
}
 bool Check2()
{
    multiset<int>mstL,mstR;
    for(int p : pointsB)
    {
        for(int it : Bout[p])
        {
            mstL.erase(mstL.find(aL[it]));
            mstR.erase(mstR.find(aR[it]));
        }
        for(int it : Bin[p])
        {
            mstL.insert(aL[it]);
            mstR.insert(aR[it]);
        }
        if(!mstL.empty())
        {
            if(*(mstR.begin()) < *(--mstL.end()))return 1;
        }
    }
    return 0;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> aL[i] >> aR[i] >> bL[i] >> bR[i];
        pointsA.insert(aL[i]),pointsA.insert(aR[i]+1);
        pointsB.insert(bL[i]),pointsB.insert(bR[i]+1);
        Ain[aL[i]].emplace_back(i),Aout[aR[i]+1].emplace_back(i);
        Bin[bL[i]].emplace_back(i),Bout[bR[i]+1].emplace_back(i);
    }
    if(Check1())cout << "NO";
    else if(Check2())cout << "NO";
    else cout << "YES";
    return 0;
}