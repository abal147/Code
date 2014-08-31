#include <cstdio>

int years(int max, int deficit) {
	int years = 0;
	while (deficit > max) {
		if (deficit & 1 || (deficit >> 1) < max) {
			deficit--;
		} else {
			deficit = deficit >> 1;
		}
		years++;
	}
	return years;
}

int main() {
	int max, deficit;

	while (scanf("%d %d\n", &max, &deficit) == 2 && max && deficit) {
		//printf("Processing %d %d\n", max, deficit);
		printf("%d\n", years(max, deficit));
	}

	return 0;
}