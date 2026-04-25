
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Add virtual cards at boundaries
    a[0] = 1;
    a[n + 1] = 1;
    
    // dp[i][j] = maximum value from igniting cards in interval [i, j]
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    
    // Process intervals of increasing length
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            
            // Try each card k as the last one ignited in [i, j]
            for (int k = i; k <= j; k++) {
                long long left = (k > i) ? dp[i][k - 1] : 0;
                long long right = (k < j) ? dp[k + 1][j] : 0;
                long long current = (long long)a[i - 1] * a[k] * a[j + 1];
                
                dp[i][j] = max(dp[i][j], left + right + current);
            }
        }
    }
    
    cout << dp[1][n] << endl;
    
    return 0;
}
