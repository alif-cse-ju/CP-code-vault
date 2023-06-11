#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int pos[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int>arr(n);
        vector<int>finArr(n);
        for(i=0;i<n;i++)finArr[i] = i+1, pos[i+1]=0;
        for(i=0;i<n;i++)cin >> arr[i], pos[arr[i]] = i;
        flag = 1;
        for(i=0;i<n;i++)
        {
            if(arr[i] != i+1)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout << '0' << '\n';
            continue;
        }
        int maxDis = 0, minDis = 0;
        int st = -1, ed = -1;
        for(int i=0;i<n;i++)
        {
            maxDis = max(maxDis,i - pos[i+1] + 1);
            minDis = min(minDis,i - pos[i+1] - 1);
            if(arr[i] != i+1)
            {
                if(st == -1)st = i;
                ed = i;
            }
        }
        if(ed-st+1 <= k)
        {
            cout << '1' << '\n';
            continue;
        }
        int first = 0, last = 0;
        for(int i=0;i<n;i++)
        {
            if (arr[i] != i + 1)
            {
                first = i;
                break;
            }
        }
        int i = n - 1;
        while(i >= 0)
        {
            if(arr[i] != i + 1)
            {
                last = i;
                break;
            }
            i--;
        }
        vector<int> x1(n), x2(n);
        for(int i=0;i<n;i++)
        {
            x1[i] = arr[i];
            x2[i] = arr[i];
        }
        int a1 = first + k, a2 = last - k + 1, a3 = last - k + 1;
        sort(x2.begin() + a3, x2.begin() + last + 1);
        sort(x2.begin() + first, x2.begin() + first + k);
        sort(x1.begin() + first, x1.begin() + a1);
        sort(x1.begin() + a2, x1.begin() + last + 1);
        if (x1 == finArr)cout << "2\n";
        else if(x2 == finArr)cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}