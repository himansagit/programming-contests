#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      int n;
      cin >> n;
      vector< pair<int,int> > a(n);
      rep(i,0,n) cin >> a[i].second;
      rep(i,0,n) cin >> a[i].first;
      sort(all(a));
      int res = 0;
      int sum = 0;
      rep(i,0,n){
            if( a[i].second > 0) sum += a[i].second;
            res = max(res, sum - a[i].first);
      }
      cout << res << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

