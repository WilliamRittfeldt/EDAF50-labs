#include <bitset>
#include <climits>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
 
void sieve(int n, bool printAll)
{

    std::string primes(n,'P');

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (primes[p] == 'P') { 
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                primes[i] = 'C';
        }
    }
 
    if (printAll) {
        for (int p = 2; p <= n; p++)
            if (primes[p] == 'P') cout << p << " ";
    } else {
        for (int p = n; p > 1; p--) {
            if (primes[p] == 'P') {
                cout << p << endl;
                break; 
            }
        }
            
    }

    
}
 
// Driver Code
int main()
{
    cout << "Following are the prime numbers smaller "
         << " than 200" << endl;
    sieve(200, true);

        cout << "Largest prime number less than 100,000" << endl;
    sieve(100000, false);

    return 0;
}