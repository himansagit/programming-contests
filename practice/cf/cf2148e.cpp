#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      if( n%k != 0){
            cout << "0\n";
            return;
      }
      vector<int> win(n+1), cnt(n+1);
      rep(i,n){
            cnt[a[i]]++;
      }
      rep(i,n+1){
            if( cnt[i]%k == 0) cnt[i] /= k;
            else{
                  // cannot divide in k equal parts
                  cout << "0\n";
                  return;
            }
      }

      i64 l = 0, r = 0, ans = 0;
      while( r < n){
            win[a[r]]++;
            while( l <= r and win[a[r]] > cnt[a[r]]){
                  win[a[l]]--;
                  l++;
            }
            ans += r-l+1;
            r++;
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

