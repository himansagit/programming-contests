#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
     i64 n,k; cin >> n >> k;
     vector<pair<i64,i64>> a(n);
     rep(i,n){
           cin >> a[i].second >> a[i].first;
     }
     sort( a.rbegin(), a.rend());
     priority_queue<i64> q;
     i64 ans = 0, sum = 0;
     rep(i,n){
           sum += a[i].second;
           q.push(-a[i].second);
           if( q.size() > k){
                 i64 del = q.top();
                 sum += del;
                 q.pop();
           }
           ans = max(ans, a[i].first *sum);
     }
     cout << ans << '\n';
}

