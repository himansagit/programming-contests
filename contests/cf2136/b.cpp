#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      string s; cin >> s;

      int cnt = 0;
      for( int i = 0; i < n; i++){
            if( s[i] == '1') cnt++;
            else {
                  if( cnt >= k){
                        cout << "No\n";
                        return;
                  }else{
                        cnt = 0;
                  }
            }
      }
      if( cnt >= k){
            cout << "No\n";
            return;
      }
      vector<int> ans(n);
      cnt = count( s.begin(), s.end(), '1');
      int l = 1, r = cnt+1;
      rep(i,n){
            if( s[i] == '0') ans[i] = r++;
            else ans[i] = l++;
      }
      cout << "Yes\n";
      for( int x:ans) cout << x << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

