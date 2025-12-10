#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void fill( string &s, vector<pair<int,int>> &p){
      int n = s.length();
      for( int i = 0; i< n-3; i++){
            if( s[i] == '1'){
                  if( s[i+1] == '1'){
                        s[i] = '0';
                        s[i+1] = '0';
                        p.push_back({i+1,i+2});
                        i++;
                  }else if( i+2 < n){
                        if( s[i+2] == '1'){
                              p.push_back({i+1, i+3});
                              s[i] = '0';
                              s[i+1] = '1';
                              s[i+2] =  '0';
                        }else{
                              p.push_back({i+2,i+3});
                              p.push_back({i+1,i+2});
                              s[i] = '0';
                              s[i+1] = '0';
                              s[i+2] = '1';
                              i++;
                        }
                  }
            }
      }
}

void fill2( string &s, vector<pair<int,int>> &p){
      int n = s.length();
     //string t = s[n-4] + s[n-3] + s[n-2] + s[n-1]; 
     string t = s.substr(n-4,4);
     if( t == "0001"){
            p.push_back({n-2,n-1});
            p.push_back({n-2,n});
     }else if( t == "0010"){
           p.push_back({n-3,n-2});
           p.push_back({n-3,n-1});
     }else if( t == "0011"){
           p.push_back({n-1,n});
     }else if( t == "0100"){
           p.push_back({n-1,n});
           p.push_back({n-2,n});
     }else if( t == "0101"){
           p.push_back({n-2,n});
           p.push_back({n-3,n-2});
           p.push_back({n-3,n-1});
     }else if( t == "0110"){
           p.push_back({n-2,n-1});
     }else if( t == "0111"){
           p.push_back({n-2,n});
     }
}

void solve(){
      int n; cin >> n;
      string s,t; cin >> s >> t;
      vector<pair<int,int>> op1, op2;
      fill(s,op1);
      fill(t,op2);

      fill2(s,op1);
      fill2(t,op2);

      cout << op1.size() + op2.size() << '\n';
      for(auto p:op1) cout << p.first << " " << p.second << '\n';
      for( int i = op2.size()-1; i >= 0; i--){
            cout << op2[i].first << " " << op2[i].second << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

