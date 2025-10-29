#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int inf = 1e9;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      #ifndef LOCAL
            freopen("dining.in","r",stdin);
            freopen("dining.out","w",stdout);
      #endif
      int n,m,k;
      cin >> n >> m >> k;
      vector<vector<pair<int,int>>> G(n+1);
      rep(i,m){
            int a,b,c;
            cin >> a >> b >> c;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
      }
      priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
      q.push({0,n});
      vector<int> sd(n+1,inf);
      sd[n] = 0;
      while( !q.empty()){
            auto [d,u] = q.top();
            q.pop();
            if( sd[u] < d) continue;
            for( auto [v,w]:G[u]){
                  if( sd[v] > d + w){
                        q.push({sd[v] = d + w, v});
                  }
            }
      }
      
      vector< int > md(n+1,inf);
      vector<int> bale(n+1);
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
      rep(i,k){
            int j,x; cin >> j >> x;
            bale[j] = x;
      }
      for(int i = 1;i <= n; i++){
            if( bale[i] > 0){ 
                  md[i] = sd[i] - bale[i];
                  Q.push({md[i],i});
            }
      }
      while( !Q.empty()){
            auto [d,u] = Q.top();
            Q.pop();
            if( md[u] < d) continue;
            for( auto [v,w]:G[u]){
                  if( md[v] > d + w){
                        Q.push({md[v] = d + w, v});
                  }
            }
      }
      debug(sd,md);
      for( int i = 1; i < n; i++){
            if( md[i] <= sd[i]){
                  cout << "1\n";
            }else{
                  cout << "0\n";
            }
      }
}

