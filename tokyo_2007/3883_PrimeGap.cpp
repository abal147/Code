#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int maxPrime = 1299709 + 1;

set<int> primes;

void primeSieve(int n) {
   bool *isPrime = (bool *)malloc(sizeof(bool) * n);
   memset(isPrime, true, sizeof(bool) * n);
   
   for (int i = 4; i < n; i += 2) {
      isPrime[i] = false;
   }
   primes.insert(2);
   
   for (int i = 3; i < n; i += 2) {
      if (isPrime[i]) {
         for (int j = i; j < n; j += i) {
            isPrime[j] = false;
         }
         primes.insert(i);
      }
   }
}

int primeGap(int n) {
   if (primes.count(n) == 1) {
      return 0;
   } else {
      set<int>::iterator p = upper_bound(primes.begin(), primes.end(), n);
      int val = *p--;
      return val - *p;
   }
}

int main() {
   primeSieve(maxPrime);
   int n;
   
   while (scanf("%d\n", &n) == 1 && n) {
      printf("%d\n", primeGap(n));
   }
   
   return 0;
}
