#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+10;
int E[N];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      E[0] = E[1] = 0;
      for( int i = 2;i < N ;i++){
            int e = 0,x = i;
            while(x%2 == 0){
                  e++;
                  x /= 2;
            }
            E[i] = e;
            E[i] += E[i-1];
      }
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int res = 0;
      rep(i,n){
            if( E[n-1] - E[i] - E[n-1-i] == 0) res = res ^ a[i];
      }
      cout << res;
      
}

