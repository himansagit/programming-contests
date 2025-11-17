#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<string> s(n);
      int c = 0;
      for( int i = 0; i < n; i++){
            cin >> s[i];
            c += count(s[i].begin(), s[i].end(), '#');
      }
      if( c == 4){
            for( int i = 0; i < n-1; i++){
                 for( int j = 0; j < n-1; j++){
                      if( s[i][j] == '#' and s[i+1][j] == '#' and s[i][j+1] == '#' and s[i+1][j+1] == '#'){
                            cout << "Yes\n";
                            return;
                      }
                 } 
            }
      }
     auto cnt = [&](int r, int c, int t, int h)->int{
            int  cn = 0;
            while( min(r,c) >= 0 and max(r,c) < n){
                  if( s[r][c] == '#'){
                        cn++;
                  }
                  if( t == 0){
                        t = 1;
                        r += 1;
                  }else{
                        t = 0;
                        c += h;
                  }
            }
            return cn;
     };     
     bool  ok = false;
     for( int i = 0; i< n; i++){

           if( cnt(0,i,0,1) == c) ok = true;
           if( cnt(0,i,1,1) == c) ok = true;
           if( cnt(0,i,0,-1) == c) ok = true;
           if( cnt(0,i,1,-1) == c) ok = true;

           if( cnt(i,0,0,1) == c) ok = true;
           if( cnt(i,0,1,1) == c) ok = true;
           if( cnt(i,0,0,-1) == c) ok = true;
           if( cnt(i,0,1,-1) == c) ok = true;
           
           if( cnt(i,n-1,0,1) == c) ok = true;
           if( cnt(i,n-1,1,1) == c) ok = true;
           if( cnt(i,n-1,0,-1) == c) ok = true;
           if( cnt(i,n-1,1,-1) == c) ok = true;
     }

     if( ok ) cout << "Yes\n";
     else cout << "No\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

