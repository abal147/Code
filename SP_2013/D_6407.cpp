#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

long long int diff (long long int head, long long int tail, long long int n) {
	long long int half = ((tail * (tail + 1)) / 2) - ((head * (head - 1)) / 2);
	long long int total = ((n * (n + 1)) / 2) - half;
	return abs(total - half);
}

void splitClock(long long int n) {

	long long int head = 1, tail = 1;

	long long int best = n * (n+1) / 2;

	long long int b1, b2;

	while (tail <= n) {
		while (diff(head+1, tail, n) < diff(head, tail, n) && head <= tail) {
			head++;
		} 

		if (diff(head, tail, n) < best) {
			b1 = head;
			b2 = tail;
			best = diff(head, tail, n);
		}
		tail++;
	}

	printf("%lld %lld\n", b1, b2);
}

int main() {
	int size;
	while(scanf("%d\n", &size) == 1 && size) {
		splitClock(size);
	}
	return 0;
}