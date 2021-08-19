#include <bits/stdc++.h>
using namespace std;

// Longest prefix suffix
vector<int> lps;
void precompute(string p) {

	int len = 0;
    lps[0] = 0; 
  
    int i = 1;
    while (i < p.length()) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

}

int main() {
	string p, t;
	cin >> p >> t;

	int m = p.length();
	lps.resize(m + 1, 0);

	precompute(p);

	int i = 0, j = 0;
	int cnt = 0;
	while(i < t.length()) {

		if (p[j] == t[i]) {
            j++;
            i++;
        }
  
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        }
  
        else if (i < t.length() and p[j] != t[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
	}

	cout << cnt << endl;
}


