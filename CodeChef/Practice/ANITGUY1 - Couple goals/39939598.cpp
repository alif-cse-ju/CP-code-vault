#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--){
    int k,n;
    cin>>k>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(binary_search(arr,arr+n,k-arr[i]))ans++;
    }
    cout << ans/2 << endl;
}
return 0; 
}