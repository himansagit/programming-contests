#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
     int n;
     cin >> n;
     vector<i64> a(n);
     rep(i,n) cin >> a[i];
     sort( a.begin(), a.end());
     i64 x = a[0]*a[n-1];
     vector<i64> d;
     for( i64 i = 2; i*i <=x; i++){
           if(x%i == 0){
                 i64 l = i;
                 i64 r = x/i;
                 d.push_back(l);
                 if( l != r) 
                       d.push_back(r);
           }
     }
     
     if( d.size() != n){
            cout << "-1\n";
            return;
     }
     sort(d.begin(), d.end());
     rep(i,n){
            if( a[i] != d[i] ){
                  cout << "-1\n";
                  return;
            }
     }
     cout << x << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

