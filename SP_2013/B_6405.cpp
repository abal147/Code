#include <cstdio>

void divideMangoes(int m) {
	
	double hMangoes = m << 1;
	int base = hMangoes / 7;
	double r = hMangoes - (base * 7);

	double parents = base;
	double children = base;

	if (r >= 5) {
		children += 1.0;
		r -= 5;
	} else if (r >= 2) {
		parents += 1.0;
		r -= 2;
	}

	printf("%.1f %.1f %.1f %.1f\n", r/2, parents/2, parents/2, children/2);
}

int main() {
	int mangoes;
	while (scanf("%d\n", &mangoes) == 1 && mangoes) {
		divideMangoes(mangoes);
	}
	return 0;
}