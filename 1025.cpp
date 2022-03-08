#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    
    int k;
    cin >> k;
    
    int g[k];
    for (int i = 0; i < k; i++) {
        cin >> g[i];
    }
    
    sort(g, g + k);
    
    int sum = 0;
    for (int i = 0, l = k / 2 + 1; i < l; i++) {
        sum += g[i] / 2 + 1;
    }
    
    cout << sum;
    return 0;
}