#include<bits/stdc++.h>

using namespace std;


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      int n, m;
      cin >> n >> m;
      string s;
      cin >> s;
      int t = s.length();
      debug(s);
      int l = 0, r= 0, u = 0, d = 0;
      int h = 0, v = 0;
      int i = 0;
      for(i = 0; i < t; i++){
            if( s[i] == 'L'){
                  h--;
                  l = min( l, h);
                  if( r -l +1 > m){
                        assert(l == h);
                        v = 1+u;
                        h = 1-l-1;
                        break;
                  }
            }else if( s[i] == 'R'){
                  h++;
                  r = max(r, h);
                  if( r - l + 1 > m){
                        assert(r==h);
                        h = 1-l;
                        v = 1+u;
                        break;
                  }
            }else if( s[i] == 'D'){
                  v--;
                  d = min( d, v);
                  if( u-d +1 > n){
                        assert(d == v);
                        v = 1+u;
                        h = 1-l;
                        break;
                  }

            }else{
                  v++;
                  u = max(u, v);
                  if(u-d+1 > n){
                        assert(u == v);
                        v = 1+u-1;
                        h = 1-l;
                        break;
                  }
                        
            }
      }
      
      debug(t,i,l,r,u,d);
      if( i == t){
            v = 1+u;
            h = 1-l;
      }

      cout << v << " " << h <<"\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

