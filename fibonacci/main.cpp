#include <stdio.h>
#include <string>
#include <assert.h>
#include <unordered_map>

typedef unsigned long long int T;
T fib(int n);

int main(int argn, char** argv) {
	if (argn < 2) {
		printf("please, use fibonacci n as an argument\n");
		return 1;
	}
	int n = std::stoi(argv[1]);

	printf("%llu\n", fib(n));
	return 1;
}

typedef std::unordered_map<int, T> HashMap;
HashMap cached_fib;

T fib(int n) {
	assert(n >= 0);
	if (n < 0)
		return -1;
	if (n == 0 || n == 1)
		return 1;

	HashMap::const_iterator it = cached_fib.find(n);
	if (it != cached_fib.end())
		return it->second;
	const T& x = fib(n - 1) + fib(n - 2);
	cached_fib[n] = x;
	return x;
}