#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    do {
        float t, k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;
        v *= k1 * k2 * k3;
        t = 100 / v;
        if(t < 9.575) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } while(--n);
    
	return 0;
}
