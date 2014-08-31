#include <cstdio>

const int MAXN = 10005;

int prev[MAXN];
int succ[MAXN];

int survivor(int n, int k, int m) {
   for (int i = 1; i <= n; ++i) {
      succ[i] = i + 1;
      prev[i] = i - 1;
   }
   succ[n] = 1;
   prev[1] = n;
   int j = m;
   for (int i = 1; i < n; ++i) {
      //printf("killing: %d\n", j);
      prev[succ[j]] = prev[j];
      succ[prev[j]] = succ[j];
      j = prev[j];
      
      int left = n - i;
      int lim = k % left;
      for (int c = 0; c < (lim); ++c) {
         j = succ[j];
      }
   }
   return j;
}

int main() {
   int n, k, m;
   while (scanf("%d%d%d\n", &n, &k, &m) == 3 && n && m && k) {
      printf("%d\n", survivor(n, k, m));
   }
}
