#include<bits/stdc++.h>

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      string t;
      cin >> t;
      if( t == "first"){
           int n;
           cin >> n;
           vector<int> a(n);
           string s(n,'a');
           for( int i = 0; i < n; i++){
                 cin >> a[i];
                 s[i] = (char)'a' + a[i] -1;
           }
           cout << s << '\n';
      }else{
            string s; cin >> s;
            int n = s.length();
            cout << n << '\n';
            for( int i = 0; i < n; i++){
                  cout << s[i] - 'a' + 1<< ' ';
            }
            cout << '\n';
      }
}

