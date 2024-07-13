#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countValidPairs(int N, int K, int H) {
    long long count = 0;
    for (int A = 1; A <= N; ++A) {
        long long numerator = A * (long long)K - H;
        long long denominator = K - 1;
        if (numerator >= 0) {
            long long B = numerator / denominator;
            if (B >= 1 && B <= N) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    vector<long long> results(T);
    
    for (int i = 0; i < T; ++i) {
        int N, K, H;
        cin >> N >> K >> H;
        results[i] = countValidPairs(N, K, H);
    }
    
    for (long long result : results) {
        cout << result*(result-1) << "\n";
    }
    
    return 0;
}
