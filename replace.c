#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	int i;
	// only valid for non-negative number
	for(i=0;i<n;i++) {
		scanf("%d", a+i);
	}
	int max=a[0], min=a[0];
	// finding min and max
	for(i=0;i<n;i++) {
		if(a[i]>max) {
			max = a[i];
		} else if(a[i] < min) {
			min = a[i];
		}
	}
	int lmin = min-1;
	int lmax = max+1;	// used to add to value, to keep track of value which is at it's correct position
	int h = n/2 - 1;
	i = -1;
	int rep = lmin;
	int count = 0;	// count values which has been put to it's correct position
	for(count=0;count<n;count++) {
		if(rep == lmin) {
			int j;
			for(j=i+1;j<n&&a[j]>max;j++); // this loop will iterate at max n times, hence time complexity is O(n) only.
			if(j==n) {
				break;
			}
			i=j;
			rep = a[j];
			a[j]=lmin;
		}
		if(i<=h) {
			i = 2*i+1;
		} else {
			i = 2*(n-1-i);
		}
		int tmp = a[i];
		a[i] = rep+lmax;
		rep = tmp;
	}
	for(i=0;i<n;i++) {
		a[i] -= lmax;
	}
	for(i=0;i<n;i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
