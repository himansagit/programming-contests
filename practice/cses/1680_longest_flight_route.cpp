#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n >> m;
      vector<vector<int>> G(n+1);
      vector<int> deg(n+1);
      rep(i,m){
            int a,b; cin >> a>> b;
            G[a].push_back(b);
            deg[b]++;
      }
      queue<pair<int,int>> q;
      rep(i,n){
            if( deg[i+1] == 0) q.push({i+1,i+1});
      }
      vector<int> l(n+1),prev(n+1);
      l[1] = 1;
      while(!q.empty()){
            auto [u,s] = q.front();
            q.pop();
            if( u == 1)  s = 1;
            for( int v:G[u]){
                  if( s == 1){
                        if( l[u]+1 > l[v]){
                              l[v] = l[u]+1;
                              prev[v] = u;
                        }
                  }
                  deg[v]--;
                  if(deg[v] == 0){
                        if( l[v] > 0)
                              q.push({v,1});
                        else
                              q.push({v,s});
                  }
            }
      }
      vector<int>  ans;
            int x = n;
            while(x != 0){
                  ans.push_back(x);
                  x = prev[x];
            }
      reverse(ans.begin(), ans.end());
      if( ans[0] != 1){
            cout << "IMPOSSIBLE";
      }else{
            cout << ans.size() <<'\n';
            for(int x:ans) cout << x << " ";
      }
      cout << '\n';
}

