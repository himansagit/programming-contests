#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n, k; cin >> n >> k;
      vector<int> a(n);
      int n4 = 4*n+4;
      vector<int> f(n4);
      for( int i = 0; i < n; i++){
            cin >> a[i];
            f[a[i]]++;
      }
      vector<int> cnt(n4);
      int l = 0, r = n4; 
      while( l < r){
            int m = (l+r)/2;
            //debug(l,r,m);
            fill(cnt.begin(), cnt.end(),0); 
            deque<pair<int,int>> q;
            for( int i = 1; i < n4; i++){
                  
                  // drop
                  if( !q.empty() and q.front().first == i){
                        cnt[i] += q.front().second;
                        q.pop_front();
                  }

                  if( f[i] > 0){
                        if( m > 0)
                              q.push_back({i+m,f[i]});
                        else cnt[i] += f[i];
                  }
                  if( !q.empty()){
                        q.back().second--;
                        if(q.back().second == 0){
                              q.pop_back();
                        }
                        cnt[i]++;
                  }
                  //debug(q);
            }
            bool ok = true;
            //debug(cnt);
            for( int i = 1; i < n4; i++) {
                  if( cnt[i] > k) ok = false;
            }
            if( ok) r = m;
            else l = m+1;
      }
      cout << l << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

