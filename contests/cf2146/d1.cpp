#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define int long long
#define rep(i,b) for( int i = 0; i < (b); ++i)

int get(int x){
      int ans = 1;
      while( ans *2 <= x) ans *= 2;
      return ans;
}
bool isb(int x,int i){
      if( (x&(1LL<<i)) == 0) return false;
      else return true;
}
void solve(){
      int L,R; cin >> L >> R;

      vector<int> a(R-L+1);
      iota(a.begin(),a.end(),L);
      int ans = 0;
      auto fill = [&](auto self,int l, int r)->void{
            debug(l,r);
            if( l > r) return;
            if(l == r){
                  ans += a[l];
                  return;
            }
            int i = 31;
            int  m = 0;
            while( isb(a[l],i) == isb(a[r],i)){
                  if( isb(a[l],i)){
                        m += (1LL << i);
                  }
                  i--;
            }
            m += (1LL << i);
            assert(i >= 0);
            debug(a[l],m,a[r],i);
            int c = m-1, b = m;
            int  y = l +m- a[l];
            int x= y-1;
            debug(x,y);
            while( x >= l and y <= r){
                  a[x] = b;
                  a[y] = c;
                  ans += 2LL*(c|b);
                  b++;
                  c--;
                  y++;
                  x--;
            }
            debug(x,y);
            self(self,l,x);
            self(self,y,r);
      };
      fill(fill,0,R-L);
      cout << ans << '\n';
      for(int &x:a){
            cout << x << " ";
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--){
            debug(tc);
            solve();
      }
}

