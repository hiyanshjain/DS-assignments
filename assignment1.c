
#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;
    int i, j, k, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Transpose of Matrix A");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (r1 == r2 && c1 == c2)
            {
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        C[i][j] = A[i][j] + B[i][j];
                    }
                }

                printf("Addition:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            }
            else
                printf("Addition is not possible.");
            break;

        case 2:
            if (r1 == r2 && c1 == c2)
            {
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        C[i][j] = A[i][j] - B[i][j];
                    }
                }

                printf("Subtraction:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            }
            else
                printf("Subtraction is not possible.");
            break;

        case 3:
            if (c1 == r2)
            {
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        C[i][j] = 0;

                        for (k = 0; k < c1; k++)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }

                printf("Multiplication:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
            }
            else
                printf("Multiplication is not possible.");
            break;

        case 4:
            printf("Transpose of Matrix A:\n");
            for (j = 0; j < c1; j++)
            {
                for (i = 0; i < r1; i++)
                {
                    printf("%d ", A[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}
