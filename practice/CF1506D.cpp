#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG


void solve(int){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  sort(all(a));
  vector<int> b;
  int cnt = 1;
  for( int i = 1; i < n; i++)
  {
    if( a[i] == a[i-1]){
      cnt++;
    }else{
      b.pb(cnt);
      cnt = 1;
    }
  }
  b.pb(cnt);
  sort(all(b));
  debug(b);
  int ans = n;
  if(sz(b) > 1){
    if(b.back() <= n-b.back()){
      ans = (n%2 == 0 ? 0 :1);
    }else{
      ans = 2*b.back() - n;
    }
  }
    cout<< ans <<"\n";
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

