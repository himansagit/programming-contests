#include<bits/stdc++.h>

#ifdef LOCALl
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int q(int i, int x){
      cout << "? " << i << " " << x << endl;
      int r; cin >> r;
      return r;
}
void solve(){
     int n; cin >> n;
      vector<int> pos(n+1);

      vector<int> mark(n+1);
      int p = 0;
      int left = n;
      while(left > 1){
            debug(left);
            debug(pos);
            int x = (1 << p);
            vector<int> c(2);
            vector<int> zeros, ones;
            for(int i = 1; i < n; i++){
                  if( mark[i] == 0){
                        int r = q(i,x);
                       c[r]--; 
                       if( r == 0) zeros.push_back(i);
                       else ones.push_back(i);
                  }
            }
            debug(c);
            for(int i = 1; i <= n; i++){
                  if( pos[i] == 0){
                        if( (i&x) == 0) c[0]++;
                        else c[1]++;
                  }
            }
            debug(c);
            debug(zeros,ones);
            assert( ( c[0] == 0 and c[1] == 1) or (c[0] == 1 and c[1] == 0));
            if( c[0] == 1){
                  for( int i = 1; i <= n; i++){
                        if( pos[i] == 0){
                              if( (i&x) > 0)
                                    pos[i] = 1;
                        }
                  }
                  for( int i:ones){
                        left--;
                        mark[i] = 1;
                  }
            }else{
                  for( int i = 1; i <= n; i++){
                        if( pos[i] == 1) continue;
                        if( (i&x) == 0)
                              pos[i] = 1;
                  }
                  for( int i:zeros){
                        left--;
                        mark[i] = 1;
                  }
            }
            p++;
      }
      for( int i = 1; i <= n; i++){
            if( pos[i] == 0){
                  cout << "! " << i << endl;
                  return;
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

