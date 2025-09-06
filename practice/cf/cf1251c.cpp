#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      string s;
      cin >> s;
      vector<int> odd,even;
      for(char c:s){
            int x = c - '0';
            if( x%2 == 0) even.push_back(x);
            else odd.push_back(x);
      }
      int l = 0 , r = 0;
      while( l < odd.size() or r < even.size()){
            if(l == odd.size()){
                  cout << even[r++];
            }else if( r == even.size()){
                  cout << odd[l++];
            }else{
                  if( odd[l] <= even[r]){
                        cout << odd[l++];
                  }else{
                        cout << even[r++];
                  }
            }
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

