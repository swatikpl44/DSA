#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
void precompute() {
	
    primes.push_back(2);

	int cnt = 0;
    for (int i = 3; i*i <= 1e9; ++i) {
        bool isPrime = true;
        for (auto p : primes) {
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
}

vector<int> generatePrimeFactors(int a) {
		
	vector<int> f;
	
    for (auto p : primes) {
        if (p > a) break;
        if (a % p == 0) {
            f.push_back(p);
            do {
                a /= p;
            } while (a % p == 0);
        }
    }
    
    if (a > 1) f.push_back(a);

    return f;
}

int main() {
	
	int n;
	cin >> n;
	
	// n can be large upto 1e9
	precompute();
	
	vector<int> facs = generatePrimeFactors(n);
	
	for(int x: facs) cout << x << " ";
	cout << endl;
	return 0;
}
