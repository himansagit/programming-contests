#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      int n,k;
      cin >> n >> k;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      auto check = [&](int m)->pair<int,int>{
            pair<int,int> mn = {0,-1};
            int z = 0;
            vector<pair<int,int>> ids(n);
            rep(i,k-1){
                  if( a[i] >= m) z++;
                  else z--;
                  ids[i] = {z,i};
            }
            for( int i = k-1; i < n; i++){
                  if( a[i] >= m) z++;
                  else z--;
                  if( i - mn.second >= k and z-mn.first >= 0 ){
                        return {mn.second,i};
                  }
                  ids[i] = {z,i};
                  if( mn.first > ids[i-k+1].first)
                        mn = ids[i-k+1];
            }
            return {-1,-1};
      };
      int ans = 0;
      pair<int,int> nt = {-1,-1};
      for(int  z = n; z > 0 ; z/=2){
            while(ans +z <= n and check(ans+z) != nt)
                  ans += z;
      }
      pair<int,int> seg = check(ans);
      cout << ans << " " << seg.first +2 <<" " << seg.second+1 << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

