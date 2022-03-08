#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int k = s.size();
    
    long result = 1;
    int factor = n;
    while (factor > 0) {
        result *= factor;
        factor -= k;
    }
    
    cout << result;
    return 0;
}