#include <stdio.h>
#define max 10

void create(int m[max][max], int s[max][3], int row, int col) {
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

void display(int s[max][3]) {
    int x = s[0][2];
    printf("Sparse matrix representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= x; i++) {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main() {
    int m[max][max], s[max][3];
    int row, col;

    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &row, &col);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    create(m, s, row, col);
    display(s);

    return 0;
}