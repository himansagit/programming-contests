#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m;
      cin >> n >> m;
      vector<vector<int>> G(m);
      vector<pair<int,int>> days(m);
      rep(i,m){
            int k;
            cin >> k;
            rep(i,k){
                  int f;
                  cin >> f;
                  G[i].push_back(f-1);
            }
            days[i] = {k,i+1};
      }
      sort(days.begin(), days.end());
      vector<int> cnt(n);
      

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

