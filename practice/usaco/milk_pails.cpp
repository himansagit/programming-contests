#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

bool state[500][500];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
#ifndef LOCAL
      freopen("pails.in","r",stdin);
      freopen("pails.out","w",stdout);
#endif
      memset(state,0,sizeof(state));
     int x,y,k,m; cin >> x >> y >> k >> m;
      // both pails can never be 
      // partially filled simultaniously
      vector<int> mark(500);
      queue<array<int,3>> q;
      q.push({0,0,0});
      int ans = m;
      while(!q.empty()){
            auto node = q.front();
            q.pop();
            int a = node[0];
            int b = node[1];
            int c = node[2];
            if( c > k) continue;
            if( state[a][b] ) continue;
            state[a][b] = 1;
            ans = min( ans, abs(m-a-b));
            c++;
            q.push({x,b,c}); // fill 0
            q.push({a,y,c}); // flll 1
            mark[a+b] = 1;
            debug(a,b,c,a+b);
            // 0 -> 1;
            if( b+a <= y)
                  q.push({0,a+b,c});
            else
                  q.push({a+b-y,y,c});
            // 1 -> 0;
            if( a+b <= x)
                  q.push({a+b,0,c});
            else
                  q.push({x,a+b-x,c});
      }
      cout << ans << '\n';
}

