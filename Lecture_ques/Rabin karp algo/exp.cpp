#include <bits/stdc++.h>
using namespace std;

#define d 256   
#define q 101   

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    int p = 0;  
    int t = 0;  
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        // Check hash values
        if (p == t) {
            // Check characters one by one
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // If hash becomes negative, convert to positive
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";

    rabinKarp(text, pattern);

    return 0;
}