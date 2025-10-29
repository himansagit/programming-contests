#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      vector<int> dist(n);
      rep(i,n) dist[i] = a[i];
      priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
      rep(i,n){
            q.push({a[i],i});
      }
      while( !q.empty()){
            auto [d,u] = q.top();
            q.pop();
            if( d > dist[u]) continue;
            if( u > 0){
                  int newd = max(dist[u], abs(a[u] - a[u-1]));
                  if( newd < dist[u-1]){
                        dist[u-1] = newd;
                        q.push({newd,u-1});
                  }
            }
            if( u < n-1){
                  int newd = max(dist[u], abs(a[u] - a[u+1]));
                  if( newd < dist[u+1]){
                        dist[u+1] = newd;
                        q.push({newd,u+1});
                  }
            }
      }
      cout << *max_element(dist.begin(), dist.end()) << '\n';
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

