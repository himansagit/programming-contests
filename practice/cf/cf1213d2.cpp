#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,k;
      cin >> n >> k;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      vector<int> f(N);
      vector<int> cnt(N);
      rep(i,n){
            int x = a[i];
            int cn = 0;
            while( x > 0){
                  if( f[x] < k){
                        f[x]++;
                        cnt[x] += cn;
                  }
                  x /= 2;
                  cn++;
            }
            if( f[0] < k){
                  f[0]++;
                  cnt[0] += cn;
            }
      }
      int ans = 1e8;
      rep(i,N){
            if( f[i] >= k){
                  ans = min(ans, cnt[i]);
            }
      }
      cout << ans << '\n';
}

