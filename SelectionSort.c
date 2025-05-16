#include <stdio.h>

void main() {
    int i, j, a[20], t, n, min;
    
    // Read the size of the array
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    
    // Read the array elements
    printf("Enter the Array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Print the unsorted array
    printf("Unsorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // Selection Sort algorithm
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j <=n-1; j++) {
            if(a[min] > a[j]) {
                min = j;
            }
        }
        // Swap the found minimum element with the first element
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    
    // Print the sorted array
    printf("SORTED ARRAY:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
