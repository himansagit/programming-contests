#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      int n;
      cin >> n;
      string s;
      cin >> s;
      int o = count(s.begin(),s.end(),'1');
      int z = count(s.begin(),s.end(),'0');
      if( o&1 or s[0] != '1' or s[n-1] != '1'){
            cout << "NO\n";
            return;
      }
      string a,b;
      int cnto = 0, cntz = 0;
      rep(i,n){
            if( s[i] == '1'){
                  if( cnto < o/2){
                        a += "(";
                        b += "(";
                  }else{
                        a += ")";
                        b += ")";
                  }
                  cnto++;
            }else{
                  if(cntz&1){
                        a += "(";
                        b += ")";
                  }else{
                        a += ")";
                        b += "(";
                  }
                  cntz++;
            }
      }
      cout << "YES\n";
      cout << a << "\n" << b << "\n";
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

//110011
//((()))
//(()())
//1010
//(())
//10110001
//((())())
