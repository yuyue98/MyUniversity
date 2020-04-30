#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int n;
	long long a, b, c;
	long long sum;
    cin>>n;
	// scanf("%d", &n);
	for (int i = 0; i < n; i++) {
        cin>>a>>b>>c;
		// scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
        printf("Case #%d: ", i + 1);
		if (a > 0 && b > 0 && a+b<0) {
			printf("true");
		}
		else if (a < 0 && b < 0 && a+b>=0) {
			printf("false");
		}
		else {
			printf(a+b > c ? "true" : "false");
		}
        printf("\n");
	}
	
	return 0;
}