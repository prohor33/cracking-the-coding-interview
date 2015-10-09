#include <string>
#include <stdio.h>
#include <fstream>

int main(int argn, char** argv) {
	if (argn < 2) {
		printf("please, use filename as argument\n");
		return 1;
	}
	std::string filename(argv[1]);
	std::ifstream file(filename.c_str());
	int sum = 0;
	while (file.good()) {
		std::string str;
		getline(file, str);
		int n = std::stoi(str);
		sum += n;
	}
	printf("%i\n", sum);
	return 1;
}