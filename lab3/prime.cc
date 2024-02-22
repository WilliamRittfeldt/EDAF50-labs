#include "prime.h"
#include <iostream>

SieveOfEratosthenes::SieveOfEratosthenes(int max) : maxNumber(max), sieve(std::string(max + 1, 'P')) {
    generatePrimes();
}

void SieveOfEratosthenes::printPrimes() const {
    for (int i = 2; i <= maxNumber; ++i) {
        if (sieve[i] == 'P') {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int SieveOfEratosthenes::largestPrimeLessThan(int limit) const {
    for (int i = limit - 1; i >= 2; --i) {
        if (sieve[i] == 'P') {
            return i;
        }
    }
    return -1; // In case there's no prime found, which shouldn't happen with proper inputs
}

void SieveOfEratosthenes::generatePrimes() {
    sieve[0] = sieve[1] = 'C'; // 0 and 1 are not prime
    for (int p = 2; p * p <= maxNumber; ++p) {
        if (sieve[p] == 'P') {
            for (int multiple = p * p; multiple <= maxNumber; multiple += p) {
                sieve[multiple] = 'C';
            }
        }
    }
}

int main() {
    int limit = 200;
    SieveOfEratosthenes sieve(limit);
    std::cout << "Prime numbers between 1 and " << limit << ":" << std::endl;
    sieve.printPrimes();

    int largeLimit = 100000;
    int largestPrime = sieve.largestPrimeLessThan(largeLimit);
    std::cout << "The largest prime number less than " << largeLimit << " is: " << largestPrime << std::endl;

    return 0;
}
