#include <string>
#include <stdio.h>

std::string rgb2hex(char* str);
std::string int2hex_str256(int n);

int main(int argn, char** arg) {

	if (argn < 2) {
		printf("please, use rgb color (x,x,x) as an argument\n");
		return 0;
	}

	printf("%s\n", rgb2hex(arg[1]).c_str());

	return 0;
}

std::string rgb2hex(char* str) {
	std::string hex_str("#");
	std::string numb_str;
	while (*str != '\0') {
		if ('0' <= *str && *str <= '9') {
			char c[2];
			c[0] = *str;
			c[1] = '\0';
			numb_str += std::string(c);
		} else {
			if (!numb_str.empty()) {
				int n = std::stoi(numb_str);
				hex_str += int2hex_str256(n);
			}
			numb_str.clear();
		}
		str++;
	}
	return hex_str;
}

std::string int2hex_str256(int n) {
	std::string hex_str;
	while (n > 0) {
		int x = n % 16;
		n /= 16;
		char c[2];
		c[0] = (x > 9 ? ('A' - 10) : '0') + x;
		c[1] = '\0';
		std::string str(c);
		hex_str += str;
	}
	for (int i = 0; i < 2; i++) {
		if (hex_str.length() < i + 1) {
			std::string str("0");
			str += hex_str;
			hex_str = str;
		}
	}
	return hex_str;
}