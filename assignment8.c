#include <stdio.h>
#include <string.h>

struct job
{
    int jobID;     /*integer id for the job*/
    char name[50];  /*size of the name*/
};

int length = 5;    
struct job j[5];    
int rear = -1;      /*keeps track of the last inserted job*/
int front = -1;     /*keeps track of the last processsed job or the deleted position*/

int isEmpty()         /*is empty function checks if the queue is empty or not*/
{
    if (rear == front)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (rear == length - 1)   /*since the length is 5, the last index is 4*/
    {
        return 1;
    }
    return 0;
}

void add(struct job j[5], char name[50], int id) /* function to add a job to the queue */
{
    if (isFull())
    {
        printf("Queue is full"); 
    }
    else
    {
        rear++;                                /*increment the rear index to add a new job*/
        strcpy(j[rear].name, name);            /*copy the name to the job structure*/  
        j[rear].jobID = id;                    /*assign the job ID to the job structure*/
        printf("\nElement added id = %d and name = %s\n", 
               j[rear].jobID, j[rear].name); /*print the added element*/
    }
}

void processjob()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        front++;
        printf("\nDeleted item is : ID = %d name = %s\n",
               j[front].jobID,
               j[front].name);
    }
}

void display()
{
    int i;     /*i is the counter*/
    for (i = front + 1; i <= rear; i++) /*loop throught queue from the front to rear*/
    {
        printf("\nID: %d || Name = %s\n", j[i].jobID, j[i].name); /*print the job id and name*/
    }
}

int main()
{
    int n;
    char name1[50];
    int cont = 1; /*cont is variable for the menu driven program and not a loop counter*/
    int JobID;

    do
    {
        printf("\nEnter your choice : 1) AddingJob 2) Processing job 3) Display jobs 4) Exit\n");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
            {
                printf("Enter the name: ");
                
                scanf("%s", name1);

                printf("Enter the jobID");
                scanf("%d", &JobID); 
                add(j, name1 , JobID);
            }
            break;

            case 2:
                processjob();
                break;

            case 3:
                display();
                break;

            case 4:
                cont = 0;
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    while (cont == 1);

    return 0;
}