#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void compress( vector<i64> &a){
      int n = a.size();
      vector<i64> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}
void solve(){
      i64 n; cin >> n;
      vector<i64> freq(n+1);
      vector<i64> a(n);
      rep(i,n){
            cin >> a[i];
            freq[a[i]]++;
      }
      rep(i,n+1){
            if( freq[i] != 0 and freq[i]%i != 0) {
                  cout << -1 << "\n";
                  return ;
            }
      }
      vector<i64> ans(n);
      vector<i64> f(n+1);
      rep(i,n){
            ans[i] = (n+1)*a[i] + f[a[i]]/a[i];
            f[a[i]]++;
      }
      compress(ans);
      rep(i,n) cout << ans[i] + 1 << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

