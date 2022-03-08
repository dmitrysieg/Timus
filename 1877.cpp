#include <iostream>

using namespace std;

int main() {
    int k1, k2;
    cin >> k1 >> k2;
    
    if (k1 % 2 == 0 || k2 % 2 == 1) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
    return 0;
}