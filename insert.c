#include <stdio.h>

void main() {
    int i, j, a[20], t, n;

    printf("Enter the Size of the Array: ");
    scanf("%d", &n);

    printf("Enter the Array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Unsorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    for(i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = t;
    }

    printf("SORTED ARRAY:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
