#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int ask(int i, int j ){
      cout << "? " << i << " " << j << endl;
      int x;
      cin >> x;
      return x;
}

void solve(){
      int n;
      cin >> n;
      if( n == 1){
            cout << "! 1"<< endl;
            return;
      }
      vector<int> a(n+1);
      int l = 1, r = 2;
      while(l <= n and r <= n){
            int x = ask(l,r);
            int y = ask(r,l);
            if( x > y){
                  a[l] = x;
                  l = r;
                  r++;
            }else{
                  a[r] = y;
                  r++;
            }
      }
      a[l] = n;
      cout << "! ";
      rep(i,n) cout << a[i+1] << " ";
      cout << endl;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

