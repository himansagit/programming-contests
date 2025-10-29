#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
vector<i64> primes;

void solve(){
      int n; cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      i64 ans = 1000;
      rep(i,n){
            for( i64 &x:primes){
                  if( a[i]%x != 0){
                        ans = min(ans,x);
                        break;
                  }
            }
      }
      cout << ans << '\n';
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      i64 p = 2;
      while( primes.size() < 70){
            bool ok = true;
            for( i64 i = 2; i*i <= p; i++){
                  if( p%i == 0){
                        ok = false;
                        break;
                  }
            }
            if(ok) primes.push_back(p);
            p++;
      }
      //for( i64 &x:primes) cout << x << endl;
      int tc; cin >> tc;
      while(tc--) solve();
}

