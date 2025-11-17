#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<int> a;
      for( int i = 0; i < 10; i++){
            int x = pow(3,i);
            a.push_back(x);
            a.push_back(2*x);
      }
      if( n == 20){
            for( int i = 1; i <= 10; i++){
                  cout << i << " " << i << " ";
            }
      }else{
            for( int x:a) cout << x << " ";
      }
      cout << '\n';
}

