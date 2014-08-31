#include <cstdio>

using namespace std;

int main() {
	int tests;
	scanf("%d\n", &tests);
	while (tests--) {
		int stops;
		scanf("%d\n", &stops);
		printf("%d\n", (1<<stops)-1);
	}
	return 0;
}
