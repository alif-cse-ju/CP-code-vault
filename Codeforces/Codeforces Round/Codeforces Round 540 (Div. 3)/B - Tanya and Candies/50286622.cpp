#include<bits/stdc++.h>
using namespace std;
int odd[200001],even[200001];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    odd[0]=even[0]=0;
    int i,n,x;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        odd[i]=odd[i-1];
        even[i]=even[i-1];
        if(i%2 == 0)
        {
            even[i]+=x;
        }
        else
        {
            odd[i]+=x;
        }
    }
    int cnt=0;
    for(i=1; i<=n; i++)
    {
        if(even[i-1]+odd[n]-odd[i] == odd[i-1]+even[n]-even[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;