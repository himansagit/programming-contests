#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x-1;
      }
      queue<int> q;
      vector<pair<int,int>> edge;
      int m = a[0];
      for( int i = 1; i < n; i++){
            int x = a[i];
            while( !q.empty() and q.front() < x){
                  edge.push_back({q.front(),x});
                  q.pop();
            }
            if( m < x){
                  edge.push_back({m,x});
            }else{
                  q.push(m);
                  m = x;
            }
      }
      if( edge.size() != n-1){
            cout << "NO\n";
      }else{
            assert(edge.size() == n-1);
            cout << "YES\n";
            for( auto p:edge){
                  cout << p.first+1 << " " << p.second+1 << '\n';
            }
      }

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

