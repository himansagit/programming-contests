#include<bits/stdc++.h>

using namespace std;

void compress( vector<int> &a){
      int n = a.size();
      vector<int> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}

template<typename T> struct BIT{
      vector<T> bit;
      int n;
      BIT(int _n){
            n = _n;
            bit.assign(n,0);
      }
      BIT( vector<int> &a){
            n = a.size();
            bit.assign(n,0);
            for( int i = 0; i < n; i++){
                  update(i,a[i]);
            }
      }
      void update(int i,T x){
            while( i < n){
                  bit[i] += x;
                  i = i |(i+1);
            }
      }
      T get(int i){
            T res = 0;
            assert(i < n);
            while( i >= 0){
                 res += bit[i]; 
                 i = (i&(i+1)) - 1;
            }
            return res;
      }
      T get(int l, int r){
            return get(r) - get(l-1);
      }
};

bool comp(array<int,3> &a, array<int,3> &b){
      if( a[0] == b[0]) return a[1] > b[1];
      else return a[0] < b[0];
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<array<int,3>> A(n);
      vector<int> TMP(2*n); // for index compression
      for( int i = 0; i < n; i++){
            cin >> A[i][1] >> A[i][0];
            A[i][2] = i;
            TMP[2*i] = A[i][1];
            TMP[2*i+1] = A[i][0];
      }
      compress(TMP);
      for( int i = 0; i < n; i++){
            A[i][1] = TMP[2*i];
            A[i][0] = TMP[2*i+1];
      }

      sort( A.begin(), A.end(), comp);
      vector<int> B(n), C(n);

      BIT<int> f1(2*n+2), f2(2*n+2);
      for( int i = 0; i < n; i++){
            B[A[i][2]] = f1.get(A[i][1],A[i][0]);            
            f1.update(A[i][1],1); 
      }
      for( int i = 0; i < n; i++) swap(A[i][0], A[i][1]);
      sort( A.begin(), A.end(), comp);
      for( int i = 0; i < n; i++){
            C[A[i][2]] = f2.get(A[i][1],2*n+1);
            f2.update( A[i][1],1);
      }
      for( int i = 0; i < n; i++) cout << (B[i] > 0 ? 1: 0) << ' ';
      cout << '\n';
      for( int i = 0; i < n; i++) cout << (C[i] > 0 ? 1: 0) << ' ' ;
      cout << '\n';

}

