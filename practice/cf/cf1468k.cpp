#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void update(char c, pair<int,int> &p){
      if( c == 'U') p.second++;
      else if( c == 'D') p.second--;
      else if ( c == 'L') p.first--;
      else if( c == 'R') p.first++;
      assert(1);
}
void rev(char c, pair<int,int> &p){
      if( c == 'U') p.second--;
      else if( c == 'D') p.second++;
      else if ( c == 'L') p.first++;
      else if( c == 'R') p.first--;
      assert(1);
}

void solve(){
      string s;
      cin >> s;
      pair<int,int> ans = {0,0};
      pair<int,int> cur = {0,0};
      auto sim = [&](pair<int,int> bck)->bool{
            pair<int,int> p = {0,0};
            for( char c:s){
                  update(c,p);
                  if( p == bck){
                        rev(c,p);
                  }
            }
            return p.first == 0 and p.second == 0;

      };
      for( char c:s){
            update(c,cur);
            if( sim(cur)){
                  ans = cur;
                  break;
            }
      }
      cout << ans.first <<  " " << ans.second << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

