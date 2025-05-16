#include <stdio.h>

struct polynomial {
    int exp;
    int coeff;
};

int main() {
    int m, n, i, j, k;
    printf("Enter the no. of terms of 1st polynomial: ");
    scanf("%d", &m);
    
    struct polynomial first[m];
    
    for (i = 0; i < m; i++) {
        printf("Enter coeff of term %d: ", i + 1);
        scanf("%d", &first[i].coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &first[i].exp);
    }
    printf("Enter the no. of terms of 2nd polynomial: ");
    scanf("%d", &n);
    
    struct polynomial second[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter coeff of term %d: ", i + 1);
        scanf("%d", &second[i].coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &second[i].exp);
    }

    printf("\nFirst polynomial: \n");
    for (i = 0; i < m; i++) {
        printf("%d x^%d", first[i].coeff, first[i].exp);
        if (i < m - 1) {
            printf(" + ");
        }
    }

    printf("\n\nSecond polynomial: \n");
    for (i = 0; i < n; i++) {
        printf("%d x^%d", second[i].coeff, second[i].exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }

    struct polynomial result[m + n];
    i = j = k = 0;

    while (i < m && j < n) {
        if (first[i].exp == second[j].exp) {
            result[k].coeff = first[i].coeff + second[j].coeff;
            result[k].exp = first[i].exp;
            i++,k++,j++;
        } else if (first[i].exp > second[j].exp) {
            result[k].coeff = first[i].coeff;
            result[k].exp = first[i].exp;
            i++,k++;
        } else {
            result[k].coeff = second[j].coeff;
            result[k].exp = second[j].exp;
            j++,k++;
        }
    }

    while (i < m) {
        result[k].coeff = first[i].coeff;
        result[k].exp = first[i].exp;
        i++,k++;
    }

    while (j < n) {
        result[k].coeff = second[j].coeff;
        result[k].exp = second[j].exp;
        j++,k++;
    }
 
    printf("\n\nResultant polynomial: \n");
    for (i = 0; i < k; i++) {
        printf("%d x^%d ", result[i].coeff, result[i].exp);
        if (i < k - 1) {
            printf("+ ");
        }
    }
    
    return 0;
}