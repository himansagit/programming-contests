#include<bits/stdc++.h>

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      string t; cin >> t;
      if( t == "first"){
            int n; cin >> n;
            string s(10*n,'a');
            for( int i = 0; i < n; i++){
                  int x; cin >> x;
                  for( int j = 0; j < 10; j++){
                        s[10*i + j] = (char)'a' + x%10;
                        x /= 10;
                  }
            }
            cout << s << '\n';
      }else if( t == "second"){
            
           string s; cin >> s;
           int n = s.length();
           n /= 10;
           cout << n << '\n';
           for( int i = 0; i < n; i++){
                 int x = 0;
                for(int j = 9; j >= 0; j--){
                   x= 10 * x + s[10*i + j] - 'a'; 
                } 
                cout << x << ' ' ;
           }
           cout << '\n';
      }else{
            cerr << "ERROR\n";
      }
}

