#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int get(int n){
      return (n*(n-1))/2;
}

void solve(){
      int n,k;cin >> n >> k;
      int r = get(n) - k;
      vector<int> subs;
      bool ok = true;
      auto dfs = [&]( int s, int l, int r)->void{
            for( int i = s; i >= 1 and ok; i--){
                  if( get(i) <= r){
                        subs.push_back(i);
                       
                  }
            }
      };
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

