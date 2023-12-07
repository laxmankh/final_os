#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define max_thread 3
#define max 3 
int step_i=0;
int mat1[20][20];
int mat2[20][20];
int matc[20][20];


void* multi(void* arg)
{
    int i=step_i++;
    for(int j=0;j<max;j++)
    {
        for(int k=0;k<max;k++)
        {
            matc[i][j]+=mat1[i][k]*mat2[k][j];
        }
    }
}


int main()
{
    printf("Enter the element in matrix1:");
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    
    printf("Enter the element in matrix2:");
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    pthread_t threads[max_thread];
    for(int i=0;i<max_thread;i++)
    {
        int *p;
        pthread_create(&threads[i],NULL,multi,(void*)(p));
    }
    for(int i=0;i<max_thread;i++)
    {
        pthread_join(threads[i],NULL);
    }
    printf("multiplication :");
        for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            printf("%d",matc[i][j]);
        }
        printf("\n");
    }
}