#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    if(n >= 3 && n%2 == 1)
    {
        printf("7");
        n-=3;
    }
    while(n > 0)
    {
        printf("1");
        n-=2;
    }
    return 0;