#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.length();

    if (k == 0) {
        long long ans = 0;
        long long countZero = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                countZero++;
            } else {
                ans += (countZero * (countZero + 1)) / 2;
                countZero = 0;
            }
        }

        ans += (countZero * (countZero + 1)) / 2;

        cout << ans << "\n";
        return 0;
    }

    long long ans = 0;
    long long prefix = 0;

    unordered_map<long long, long long> freq;
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            prefix++;

        if (freq.find(prefix - k) != freq.end()) {
            ans += freq[prefix - k];
        }

        freq[prefix]++;
    }

    cout << ans << "\n";
}