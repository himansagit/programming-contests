#include<bits/stdc++.h>

using namespace std;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int t = 250000;
      for( int k = 1 ; k <= 20; k++){
            int cost = pow(2,k/2)*k + k*1000 + ((t + pow(2,k)-1)/(pow(2,k)))*(1000+pow(2,k));
            cout << k << " "  << cost << endl;
      }
}

