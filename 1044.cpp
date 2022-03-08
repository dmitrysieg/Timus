#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int maxSum = 9;
    int sums[maxSum + 1];
    fill(sums, sums + maxSum + 1, 1);
    
    int prevSums[4 * 9 + 1];
    copy(sums, sums + maxSum + 1, prevSums);
    int prevMaxSum = maxSum;
    
    for (int i = 2, l = n / 2; i <= l; i++) {
        maxSum = 9 * i;
        int sums2[maxSum + 1];
        fill(sums2, sums2 + maxSum + 1, 0);
        for (int j = 0; j <= maxSum; j++) {
            int currSum = 0;
            for (int k = 0; k <= 9; k++) {
                if (j - k >= 0 && j - k <= prevMaxSum) {
                    currSum += prevSums[j - k];
                }
            }
            sums2[j] = currSum;
        }
        copy(sums2, sums2 + maxSum + 1, prevSums);
        prevMaxSum = maxSum;
    }
    
    int luckyCount = 0;
    for (int i = 0; i <= maxSum; i++) {
        luckyCount += prevSums[i] * prevSums[i];
    }
    
    cout << luckyCount;
    return 0;
}