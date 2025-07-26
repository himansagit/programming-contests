#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG

void solve(){
      int n,k,x;
      cin >> n >> k >> x;
      vector<string> s(n);
      rep(i,n) cin >> s[i];
      sort( s.begin(), s.end());
      string t;
      vector<int> ids;
      int cnt = 0;
      auto find = [&](auto self, int d)->void{
            if( d == k){
                  debug(ids);
                  cnt++;
                  return;
            }
                  
            if(cnt > x)
                  return;
            rep(j,n){
                  ids.push_back(j);
                  self(self,d+1);
                  if( cnt   == x)
                        return;
                  ids.pop_back();
            }
      };
      find(find,0);
      debug(cnt);
      debug(ids);
      for(int j:ids) t += s[j];
      cout << t;

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

