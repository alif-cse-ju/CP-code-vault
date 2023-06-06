#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool visited[200005];
int a[200005],visitedTime[200005],timeVisited[200005];

int main()
{
    FAST();
    long long k;
    int i,n,x=1,y,cnt=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    while(k > 0)
    {
        if(visited[x])
        {
            y=cnt-timeVisited[x]+1;
            ++k;
            if(k%y == 0)cout << visitedTime[cnt];
            else cout << visitedTime[timeVisited[x]+(k%y)-1];
            return 0;
        }
        --k;
        visited[x]=true;
        timeVisited[x]=++cnt,visitedTime[cnt]=x,x=a[x];
    }
    cout << x;
    return 0;
}
