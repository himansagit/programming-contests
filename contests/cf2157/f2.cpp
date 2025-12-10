#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      if( n == 4){
            // same as sample test case
            cout << "4\n1 4\n3 1\n2 1\n3 1\n"; 
            return 0;
      }

      for( int L = 1; L <= 20000; L *= 2){
            vector<pair<int,int>> m;
            int t = 1;
            int cost = 0;
            int last = -1;
            int l = 0;
            while( t <= L){
                  //m.push_back({n,1});
                  //cout << n+1 << " 1\n";
                  //cost += 1001;
                  //int c = 0;
                  for(int j = n - t; j > 0; j -= 2*t){
                        m.push_back({j,t});
                        cost += t;
                        l += t;
                        if( j > last) cost += 1000;
                        last = j;
                        //c++;
                  }
                  //debug(test);
                  //debug(t,c, c*t);
                  t *= 2;
            }
            int s = n%t;
            //cout << m.size() << " " << cost << " " << l <<'\n';
            for( int i = s; i < n; i += t){
                  m.push_back({i,t});

                  l += t;
                  cost += 1000+t;
            }
            cout << L << " " << m.size() << " " << cost << " " << l <<'\n';

      }
}
/// 750000
/// 750 -> 512
