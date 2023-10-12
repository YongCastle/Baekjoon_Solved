#include <cstdio>

int n, a[310], d[310];
int max(int p, int q) {return p>q ? p:q;}
int main() {
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		d[i] = max(d[i-2], d[i-3]+a[i-1]) + a[i];
	}
	printf("%d", d[n]);
	return 0;
}