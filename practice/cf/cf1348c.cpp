#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      int n,k;
      cin >> n >> k;
      string s;
      cin >> s;
      sort(s.begin(),s.end());
      if( s[0] < s[k-1]){
            cout << s[k-1] << "\n";
            return;
      }
      cout << s[0];
      if( k < n and s[k] == s[n-1]){
            // distribute equally
            int c = (n-1)/k;
            rep(i,c) cout << s[n-1];
      }else{
            for(int i = k; i < n; i++) cout << s[i] ;
      }
      cout << "\n";
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

