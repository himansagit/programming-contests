#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define int long long
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int inf = 2e12+5;
void solve(){
      int n,k,x; cin >> n >> k >> x;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      a.push_back(inf);
      int l = 0, r = 1e9+1;
      vector<int> ans;
      while( l < r){
            int m = (l+r+1)/2;
            ans.clear();
            int left = k, pos = 0, i = 0;
            while( left > 0){
                  if(  a[i] - pos >= m){
                        ans.push_back(pos);
                        pos++;
                        left--;
                  }else{
                        pos = a[i] + max(1LL,m);
                        i++;
                  }
            }
            if( left == 0 and ans.back() <= x){
                  l = m;
            }else{
                  r = m-1;
            }
      }
      //debug(l);
      int m = l;
      ans.clear();
            int left = k, pos = 0, i = 0;
            while( left > 0){
                  //debug(left,pos,i);
                  if(  a[i] - pos >= m){
                        ans.push_back(pos);
                        pos++;
                        left--;
                  }else{
                        pos = a[i] + max(1LL,m);
                        i++;
                  }
                  //debug(left,pos,i);
            }
      for(int &x: ans) cout << x << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

