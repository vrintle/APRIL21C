#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    do {
        long long int N, sum = 0;
        cin >> N;
        
        sum += (N/4) * 44;
        if(N%4 == 1) {
            sum += (N > 4 ? 1 : 0) * 12 + 20;
        } else if(N%4 == 2) {
            sum += (N > 4 ? 1 : 0) * 8 + 36;
        } else if(N%4 == 3) {
            sum += (N > 4 ? 1 : 0) * 4 + 51;
        } else {
            sum += 16;
        }
        
        cout << sum << '\n';
    } while(--n);
    
	return 0;
}
