#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,q;
      cin >> n >> q;
      vector<int> a(n+1);
      rep(i,n) cin >> a[i+1];
      auto find = [&](int l,int r)->bool{
            bool ok = true;
            int last = -1;
            for( int i = l; i <= r; i+= 2){
                  if( min( a[i], a[i+1]) < last){
                        ok = false;
                        break;
                  }else{
                        last = max(a[i], a[i+1]);
                  }
            }
            return ok;
      };
      rep(j,q){
            int l,r ;
            cin >> l >> r;
            int w = r-l+1;
            if( w <= 2){
                  cout << "YES\n";
                  continue;
            }
            if( w%2 == 0){
                  if(find(l,r)){
                        cout << "YES\n";
                        continue;
                  }
                  if(  a[l] > min(a[l+1],a[l+2]) or a[r] < max( a[r-1],a[r-2])){
                              cout << "NO\n";
                              continue;
                  }
                  if( find(l+1,r-1)) cout << "YES\n";
                  else cout << "NO\n";
            }else{
                  if( a[l] <= min(a[l+1],a[l+2]) and find(l+1,r)) cout << "YES\n";
                  else if( a[r] >= max(a[r-1],a[r-2]) and find(l,r-1)) cout << "YES\n";
                  else cout << "NO\n";
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

