#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create(int m[MAX][MAX], int s[MAX][3], int row, int col) {
    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = m[i][j];
                k++;
            }
        }
    }
    s[0][0] = row;
    s[0][1] = col;
    s[0][2] = k - 1;
}

void display(int s[MAX][3]) {
    int x = s[0][2];
    printf("Row\tCol\tValue:\n");
    for (int i = 0; i <= x; i++) {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}

void transpose(int s[MAX][3], int t[MAX][3]) {
    int k = 1;
    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];
    for (int i = 0; i < s[0][1]; i++) {
        for (int j = 1; j <= s[0][2]; j++) {
            if (i == s[j][1]) {
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }
}

int main() {
    int m[MAX][MAX];
    int s[MAX][3], t[MAX][3];
    int row, col;

    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &row, &col);

    printf("Enter the elements: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    create(m, s, row, col);
    printf("Sparse matrix representation:\n");
    display(s);

    transpose(s, t);
    printf("Transposed Sparse matrix representation:\n");
    display(t);

    return 0;
}
