#include <iostream>
#include <cstdio>
using namespace std;

int bitManipulation3(int n, int i) {
    printf("%d\n", sizeof(int));
    printf("%x\n", 0x80000000);
printf("%d\n", 0x80000000 >> (i - 1));
return n ^ ((int)0x80000000 >> (i - 1));
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}