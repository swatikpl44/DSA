#include<bits/stdc++.h>
using namespace std;

/*  Given two arrays, A and B, find the number of pairs for which GCD(a, b) != 1, where a is a number in A and b in B. 
	1 <= length of A, B <= 1e5, 1 <= values <= 1e9
*/

/* Approach -
	The first step is to use Eratosthenes sieve to calculate the prime numbers up to sqrt(10^9). This sieve can then be used to quickly 
	find all prime factors of any number less than 10^9 (see the generatePrimeFactors(...) function in the code sample below).

	Next, for each A[i] with prime factors p0, p1, ..., pk, we compute all possible sub-products X - p0, p1, p0p1, p2, p0p2, p1p2, p0p1p2, p3, p0p3, ..., p0p1p2...pk 
	and count them in map cntp[X]. Effectively, the map cntp[X] tells us the number of elements A[i] divisible by X, 
	where X is a product of prime numbers to the power of 0 or 1. So for example, for the number A[i] = 12, the prime factors are 2, 3. 
	We will count cntp[2]++, cntp[3]++ and cntp[6]++.

	Finally, for each B[j] with prime factors p0, p1, ..., pk, we again compute all possible sub-products X and use the Inclusion-exclusion principle 
	to count all non-coprime pairs C_j (i.e. the number of A[i]s that share at least one prime factor with B[j]). The numbers C_j are then subtracted 
	from the total number of pairs - N*N to get the final answer.
	
*/

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
	
	// With s^2 the upper bound on the elements of A and B, building the sieve is O(s log log s).
	precompute();
	
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	map<int, int> cntp;
	for (int i = 0; i < n; i++) { 
		// Factoring each element is at most O(log log s), so for all elements, it's O(n log log s).
        auto f = generatePrimeFactors(a[i]);

        // count possible products using non-repeating prime factors of A_i
        vector<pair<int, int>> x;
        x.push_back({ 0, 1 });

		// There are less than 2^(log log s) = (log s)^(log 2) < s sub-products for any element, so for all elements, 
		// computing the sub-products (and counting all non-coprime pairs) is at most O(s).
		
        for (auto p : f) {
            int k = x.size();
            for (int i = 0; i < k; ++i) {
                int nn = x[i].first + 1;
                int pp = x[i].second * p;

                ++cntp[pp];
                x.push_back({ nn, pp });
            }
        }
    }
    
    // use Inclusion–exclusion principle to count non-coprime pairs
    // and subtract them from the total number of prairs N*N

    int cnt = n; cnt *= n;

    for (int i = 0; i < n; i++) {
        auto f = generatePrimeFactors(b[i]);

        vector<pair<int,int>> x;
        x.push_back({ 0, 1 });

        for (auto p : f) {
            int k = x.size();
            for (int i = 0; i < k; ++i) {
                int nn = x[i].first + 1;
                int pp = x[i].second * p;

                x.push_back({ nn, pp });
				
				/* C_j = (cntp[p0] + cntp[p1] + ... + cntp[pk]) -
      						(cntp[p0p1] + cntp[p0p2] + ... + cntp[pk-1pk]) +
      							(cntp[p0p1p2] + cntp[p0p1p3] + ... + cntp[pk-2pk-1pk]) -
      								...
      			*/
      			
      			// Simliar to P(A U B U C) formula
                if (nn % 2 == 1) {
                    cnt -= cntp[pp];
                } else {
                    cnt += cntp[pp];
                }
            }
        }
    }
    
    cout << cnt << endl;
	return 0;
}
