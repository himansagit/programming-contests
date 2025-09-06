#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 mod = 998244353;
bool check(i64 n, i64 A, i64 B){
      return  n*A >= (n-1)*B;
}
i64 sumn(i64 n){
      return (n*(n+1))/2;
}
void addi(i64 &a, i64 b){
      a += b;
      a %= mod;
}
void solve(){
      int n; cin >> n;
      vector<int> a(n+1);
      rep(i,n) cin >> a[i+1];
      vector<pair<int,int>> loop;
      vector<int> mark(n+1);
      vector<int> cir(n+1);
      for( int i = 1; i <= n; i++){
            if( mark[a[i]] )
                  continue;
            int x = a[i];
            int cnt = 0;
            while( !mark[x]){
                  mark[x] =1 ;
                  x = a[x];
                  cnt++;
            }
            cir[cnt]++;
      }
      for( int i = 2; i <= n; i++){
            if( cir[i] > 0){
                  loop.push_back({i,cir[i]});
            }
      }
      i64 ans = 0;
      for( pair<int,int> p:loop){
            i64 k = p.first;
            i64 cost = 0;

            i64 A = 1, B= 1;
            for( ; A <= n; A++){
                  while(B <= n and check(k,A,B)){
                              B++;
                  }
                  addi(cost, (k-1)*sumn(B-1));
                  addi(cost, k*A*(n-B+1));
                  debug(A,B,cost);
            }
            addi(ans, cost*p.second);
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

