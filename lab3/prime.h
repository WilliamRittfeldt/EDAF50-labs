#ifndef SIEVEOFERATOSTHENES_H
#define SIEVEOFERATOSTHENES_H

#include <vector>
#include <string>

class SieveOfEratosthenes {
public:
    explicit SieveOfEratosthenes(int max);
    void printPrimes() const;
    int largestPrimeLessThan(int limit) const;

private:
    int maxNumber;
    std::string sieve;
    void generatePrimes();
};

#endif // SIEVEOFERATOSTHENES_H
