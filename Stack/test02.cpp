#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		int miny;
		miny = m * n - pow(n - 1, 2) / 4;
		printf("%d\n", miny);
	}
	return 0;
}