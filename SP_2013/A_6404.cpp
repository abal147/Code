#include <cstdio>

char in[6];
int diff[5];

bool isPinSecure() {
	scanf("%c%c%c%c%c%c\n", &in[0], &in[1], &in[2], &in[3], &in[4], &in[5]);

	diff[0] = in[1] - in[0];
	diff[1] = in[2] - in[1];
	diff[2] = in[3] - in[2];
	diff[3] = in[4] - in[3];
	diff[4] = in[5] - in[4];

	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (int i = 0; i < 6; ++i) {
		if (++count[in[i] - '0'] == 3) {
			return false;
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (diff[i] == 1) {
			if (diff[i+1] == 1) {
				return false;
			}
		}
		if (diff[i] == -1) {
			if (diff[i+1] == -1) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		if (isPinSecure()) {
			printf("ACCEPTABLE\n");
		} else {
			printf("WEAK\n");
		}
	}
	return 0;
}