#include <cstdio>
#include <iostream>
using namespace std;

#define ll long long
const int MOD =  1000000007;


void mul(ll int A[2][2], ll int M[2][2]) {

  A[0][0] =  ( ( A[0][0] * M[0][0] ) % MOD + ( A[0][1] * M[1][0] ) % MOD ) % MOD;
  A[0][1] =  ( ( A[0][0] * M[0][1] ) % MOD + ( A[0][1] * M[1][1] ) % MOD ) % MOD;
  A[1][0] =  ( ( A[1][0] * M[0][0] ) % MOD + ( A[1][1] * M[1][0] ) % MOD ) % MOD;
  A[1][1] =  ( ( A[1][0] * M[0][1] ) % MOD + ( A[1][1] * M[1][1] ) % MOD ) % MOD;

}


void pow(ll int A[2][2], ll int x) {

  if( x == 0 || x == 1)
      return;

  ll int M[2][2] = {{1,1},{1,0}};

  pow(A, x/2);

  mul(A, A);

  if ( x % 2  != 0)
     mul(A, M);
}



int main()
{

	ll int T,N;

	cin >> T;

	while(T--) {

		cin >> N;

	            ll int ans = 0;
		ll int A[2][2] = {{1,1},{1,0}};

		 if ( N == 0 )
		    ans = 0;

		  else if ( N == 1 )
		    ans =  2;

		  else if ( N ==  2 )
		   ans = 3;

		  else{

		  pow( A, N - 2 );

		  ans =( A[0][0] * 3 + A[0][1] * 2 ) % MOD;
		 }


		cout << ans << endl;
	}
	return 0;
}
