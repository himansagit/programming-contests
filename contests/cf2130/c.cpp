#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)


using P = array<int,3>;
bool comp(P a, P b){
      if( a[0] == b[0])
            return a[1] > b[1];
      else 
            return a[0] < b[0] ;
}
void solve(){
      int n;
      cin >> n;
      vector<P> a(n);

      int l,r;
      rep(i,n){
            cin >> l >> r;
            a[i] = {l,r,i+1};
      }
      sort( a.begin(), a.end(), comp);

      vector<int> res;
       l = 0, r = 0;
      rep(i,n){
            if( a[i][1] > r){
                  r = a[i][1];
                  res.push_back(a[i][2]);
            }
      }
      cout << res.size() << "\n";
      for( int x:res){
            cout << x << " " ;
      }
      cout << "\n";
}
      

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

