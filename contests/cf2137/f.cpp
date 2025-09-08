#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int find( vector<pair<int,int>> &st, int x){
      int i = st.size() -1;
      for( int z = st.size(); z > 0; z/= 2){
            while( i -z >= 0 and st[i-z].first < x){
                  i -= z;
            }
      }
      if( i == 0)
            return -1;
      else return st[i-1].second;
}
void solve(){
     i64 n; cin >> n;
     vector<i64> a(n), b(n);
     rep(i,n) cin >> a[i];
     rep(i,n) cin >> b[i];
     vector<pair<int,int>> st;
     i64 ans = 0;
     rep(i,n){
           i64 x = a[i];
           while( !st.empty() and st.back().first < x) st.pop_back();
           st.push_back({a[i],i});
            if( a[i] == b[i]){
                  ans += (i+1)*(n-i);
            }else if( a[i] < b[i]){
                  // need binary search
                  int j = find(st,b[i]);
                  if( j != -1){
                        ans += (j+1)*(n-i);
                  }
            }else{
                  if( st.size() > 1){
                        int j = st[ st.size()-2].second;
                        ans += (j+1)*(n-i);
                  }
            }
     }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

