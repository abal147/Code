//100 - The 3n + 1 Problem
#include <cstdio>
#include <algorithm>

using namespace std;

int cycles[1000001];

int cycleLength(long long int n) {
	int count = 0;
	while(n != 1) {
		if (n & 1) {
			//odd
			n = (n << 1) + n + 1;
		} else {
			n = n >> 1;
		}
		count++;
		if (n < 1000000) {
			if (cycles[n]) {
				count += cycles[n];
				break;
			}
		}
	}
	return count;
}

int main() {
	for (int i = 1; i <= 1000000; ++i) {
		cycles[i] = cycleLength(i);
	}

	int from, to;

	while (scanf("%d %d\n", &from, &to) == 2) {
		int res = 0;
		for (int i = min(from, to); i <= max(to, from); ++i) {
			res = max(res, cycles[i]);
		}
		printf("%d %d %d\n", from, to, res + 1);
	}

	return 0;
}
