#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using P = array<int,3>;
void solve(){
     int n; cin >> n;
     vector<P> a(n);
     rep(i,n){
           a[i][2] = i+1;
           cin >> a[i][1];
     }
     rep(i,n) cin >> a[i][0];
     sort( a.begin(), a.end(),greater<P>());
     vector<int> last(n+1,0);
     vector<pair<int,int>> ans;
     rep(i,n){
           //if( a[i][0] == a[i][1]) continue;
           if( a[i][0] < a[i][1] or (a[i][0] > a[i][1] and last[a[i][0]] == 0)){
                  cout << "-1\n";
                  return;
           }else if( a[i][0] > a[i][1]){
                 ans.push_back({a[i][2], last[a[i][0]]});
           }
           if( last[a[i][1]] == 0) last[a[i][1]] = a[i][2];
     }
     cout << ans.size() << '\n';
     for( int i = ans.size()-1; i >= 0; i--) cout << ans[i].first << " " << ans[i].second << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

