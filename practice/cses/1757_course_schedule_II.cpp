#include<bits/stdc++.h>

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
            int a,b; cin >> a >> b;
            G[a].push_back(b);
            deg[b]++;
      }
      priority_queue<int> q;
      for( int i = 1; i <= n; i++){
            if( deg[i] == 0){
                  q.push(-i);
            }
      }
      vector<int> ans;
      while(!q.empty()){
            int u = -q.top();
            q.pop();
            ans.push_back(u);
            for(int v:G[u]){
                  deg[v]--;
                  if( deg[v] == 0){
                        q.push(-v);
                  }
            }
      }
      for(int x:ans){
            cout << x << " ";
      }
      cout << '\n';
}

