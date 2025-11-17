#include<bits/stdc++.h>

using namespace std;

int q(int l, int r){
      cout << "? " << l << " " << r << endl;
      int x; cin >> x;
      return x;
}

void solve1(){
      int n; cin >>n;
      int p = 1;
      bool f = false;
      for( int i = 0; i < n; i++){
            int x; cin >> x;
            if( x == n and !f){
                  p = 0;
            }else if( x == 1){
                  f = true;
            }
      }
      cout << p << '\n';
}

void solve2(){
      int n, p; cin >> n >> p;
      int l = 1, r = n;
      if( p == 0){
            while( l < r){
                  int m = (l+r+1)/2;
                  int x = q(m,n);
                  if( x == n-1) l = m;
                  else r = m-1;
            }
      }else{
            while( l < r){
                  int m = (l+r)/2;
                  int x = q(1,m);
                  if( x < n-1) l = m+1;
                  else r = m;
            }
      };
      cout << "! " << l << endl;
}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      string t; cin >> t;
      if( t == "first"){
            int tt; cin >> tt;
            while( tt--) solve1();
            
      }else if( t == "second"){
            int tt; cin >> tt;
            while( tt--) solve2();
      }else{
            cerr << "ERROR\n";
      }
      
}

