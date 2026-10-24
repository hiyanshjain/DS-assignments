#include <stdio.h>

void accept(int a[10][10], int m, int n)
{
    int i, j;
    printf("\nEnter the matrix values:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int m, int n)
{
    int i, j;
    printf("\nThe matrix values:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}

void compact(int a[10][10], int b[10][10], int m, int n)
{
    int i, j, k = 1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = k - 1;

    printf("\nCompact Matrix:");
    display(b, b[0][2] + 1, 3);
}

void transpose(int a[10][10], int b[10][10], int m, int n)
{
    int i, j, k;

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    k = 1;
    n = a[0][2];

    for(i = 0; i < a[0][1]; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == a[j][1])
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

int main()
{
    int a[10][10], triplet[10][10], trans[10][10];
    int m, n;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("\nEnter matrix elements:\n");
    accept(a, m, n);

    printf("\nOriginal Matrix:\n");
    display(a, m, n);

    compact(a, triplet, m, n);

    printf("\nTriplet Matrix:\n");
    display(triplet, triplet[0][2] + 1, 3);

    transpose(triplet, trans, m, n);

    printf("\nTranspose of Triplet Matrix:\n");
    display(trans, trans[0][2] + 1, 3);

    return 0;
}



















