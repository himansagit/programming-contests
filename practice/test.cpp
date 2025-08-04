#include<bits/stdc++.h>
//#include<iostream>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int cnt = 0;

void func(char a,char b, char c, int n){
      if( n == 1){
            cout << a << " -> " << c << "\n";
            cnt++;
            return;
      }

      func(a,c,b,n-1);
      cout << a << " -> " << c << "\n";
      cnt++;
      func(b,a,c,n-1);
}

void solve(){
      char a = 'A', b = 'B', c = 'C';
      int n;
      cin >> n;
      func(a,b,c,n);
      cout << cnt;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

