#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    do {
        int l, k;
        string s;
        cin >> l >> k;
	    cin.ignore();
        getline(cin, s);
    	int c = 0, i = 0, b = 0;
    	for(; i < l; i++) {
    		if(s[i] == '*') {
    			c++;
    			if(c >= k) {
    				b = 1;
    				break;
    			}
    		} else {
    			c = 0;
     		}
    	}
    	if(b) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    } while(--n);
	return 0;
}
