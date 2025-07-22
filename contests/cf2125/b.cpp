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
      i64 a,b,k;
      cin >> a >> b >> k;
      i64 g = gcd(a,b);
      i64 d = max(a,b)/g;
      if(d <= k){
            cout<<"1\n";
      }else{
            cout<<"2\n";
      }
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

