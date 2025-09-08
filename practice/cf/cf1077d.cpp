#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,k; cin >> n >> k;
      vector<int> cnt(N);
      rep(i,n){
            int x; cin >> x;
            cnt[x]++;
      }
      vector<pair<int,int>> a(N);
      rep(i,N) a[i] = {cnt[i],i};
      sort( a.rbegin(), a.rend());
      int t = 0;
      auto find = [&](int f)->bool{
            int cnt = 0;
            rep(i,N){
                  cnt += a[i].first/f;
            }
            return cnt >= k;
      };
      for( int z = n; z > 0; z /= 2){
            while( t + z <= n and find(t+z)){
                  t += z;
            }
      }
      assert( t >= 1);
      vector<int> ans;
      rep(i,N){
            int f = a[i].first/t;
            int x = a[i].second;
            rep(j,f) ans.push_back(x);
      }
      assert( ans.size() >= k);
      rep(i,k) cout << ans[i] <<" \n"[i == k-1];
}

