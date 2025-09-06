#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int q,x; cin >> q >> x;
      set< pair< int,int >> s;
      vector<int> cnt(x+1);
      int l = 0, r= 0;
      while(q--){
            int k; 
            cin >> k;
            k = k%x;
            cnt[k]++;
            while(  cnt[r] > l){
                  r++;
                  if( r == x){
                        l++;
                        r = 0;
                  }
            }
            cout << l*x + r << '\n';
      }
}

