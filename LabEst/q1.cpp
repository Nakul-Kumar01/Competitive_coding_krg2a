
#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string& p) {
    int m = p.size();
    vector<int> lps(m, 0);

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool kmpMatch(const string& s, const string& p) {
    int n = s.size();
    int m = p.size();

    vector<int> lps = computeLPS(p);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (p[j] == s[i]) {
            j++;
            i++;

            if (j == m) {
                return true;
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}

int main() {
    string s = "ABABDABACDABABC";
    string p = "ABAC";

    if (kmpMatch(s, p)) {
        cout << "Pattern found!" << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}


