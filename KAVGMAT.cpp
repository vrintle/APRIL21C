#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long int n, m, k, w = 0;
		cin >> n >> m >> k;
		
		long long int mat[n][m], pref[n][m];
		
		for(long long int r = 0; r < n; r++) {
			for(long long int c = 0; c < m; c++) {
				cin >> mat[r][c];
			}
		}
		
		for(long long int r = 0; r < n; r++) {
			for(long long int c = 0; c < m; c++) {
				if(r && !c) {
					pref[r][c] = mat[r][c] + pref[r-1][c];
				} else if(c && !r) {
					pref[r][c] = mat[r][c] + pref[r][c-1];
				} else if(r && c) {
					pref[r][c] = pref[r-1][c] + pref[r][c-1] - pref[r-1][c-1] 
					+ mat[r][c];
				} else {
					pref[r][c] = mat[r][c];
				}
				
				// cout << pref[r][c] << ' ';
			}
			// cout << '\n';
		}
		
		long long int min = n < m ? n : m, r, c;
		for(long long int s = 1; s <= min; s++) {
			// cout << "size = " << s << '\n';
			r = 0;
			while(r <= n-s) {
				c = 0;
				while(c <= m-s) {
					double sum = pref[r+s-1][c+s-1];
					
					if(r && !c) {
						sum -= pref[r-1][c+s-1];
					} else if(!r && c) {
						sum -= pref[r+s-1][c-1];
					} else if(r && c) {
						sum -= pref[r-1][c+s-1] + pref[r+s-1][c-1] - 
						pref[r-1][c-1];
					}
					
					sum /= double(s*s);
					// cout << "avg = " << sum << '\n';
					// cout << "row = " << r << ", col = " << c << '\n';
					if(sum >= k) {
						w += m-s-c+1;
						break;
					} else {
						c++;
					}
				}
				r++;
			}
		}
		
		cout << w << '\n';
	}
	
	return 0;
}
