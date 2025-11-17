#include<bits/stdc++.h>

using namespace std;


void merge_sort( int l, int r, vector<int> &a){
      static vector<int> tmp(r+1);
      if( r - l + 1 <= 1) return;
      int m = (l+r)/2;
      merge_sort(l,m,a);
      merge_sort(m+1,r,a);
      int i = l, j = m+1, k= l;
      while( k <= r){
            if( i <= m and j <= r){
                  if( a[i] <= a[j]) tmp[k++] = a[i++];
                  else tmp[k++] = a[j++];

            }else if( i <= m){
                  tmp[k++] = a[i++];
            }else{
                  tmp[k++] = a[j++];
            }
      }
      for( int i = l; i <= r; i++) a[i] = tmp[i];

}
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<int> a(n);
      for( int &a:a) cin >> a;

      merge_sort(0,a.size()-1,a);
      for( int &a: a) cout << a << " ";

      cout << '\n';
}

