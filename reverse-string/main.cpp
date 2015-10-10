#include <stdio.h>

void reverse_str(char* str);

int main(int argn, char** argv) {
	if (argn < 2) {
		printf("please, input any string as an argument to reverse it\n");
		return 1;
	}
	reverse_str(argv[1]);
	printf("%s\n", argv[1]);
}

void reverse_str(char* str) {
	int s = 0;
	while (str[s] != '\0')
		s++;
	for (int i = 0; i < s / 2; i++) {
		int j = s - 1 - i;
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}