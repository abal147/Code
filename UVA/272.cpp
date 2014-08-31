//272 - Tex Quotes
#include <cstdio>

int main() {
	bool seen = false;
	int c;
	while ((c = getchar()) > 0) {
		if (c < 0) break;
		if (c == '"') {
			if (!seen) {
				putchar('`');
				putchar('`');
			} else {
				putchar('\'');
				putchar('\'');
			}
			seen = !seen;
		} else {
			putchar(c);
		}
	}
	return 0;
}
