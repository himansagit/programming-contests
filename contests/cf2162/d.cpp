#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int q1(int l, int r){
      cout << 1 << " " <<  l << " " << r << endl;
      int s; cin >> s;
      return s;
}
int q2(int l, int r){
      cout << 2 << " " <<  l << " " << r << endl;
      int s; cin >> s;
      return s;
}
void solve(){
      int n; cin >> n;
      int sum = ((n+1)*n)/2;
      int t = q2(1,n);
      int w = t - sum;
      int l = 1, r = n;
      while( l < r){
            int m = (l+r)/2;
            int t1 = q1(1,m);
            int t2 = q2(1,m);
            if( t2 > t1){
                  r = m;
            }else{
                  l = m+1;
            }
      }
      cout << "! " << l << " " << l+w-1 << endl;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

