#include<stdio.h>

double fun (double arr[3][4], int i)
{
    double temp=arr[i][i];
    for (int j=0; j<4; j++)
    {
        arr[i][j]=arr[i][j]/temp;
    }
    for (int k=i+1; k<3; k++)
    {
        double te = arr[k][i];
        for (int j=0; j<4; j++)
        {
            arr[k][j]-=te*arr[i][j];
        };
    }
}

void main(void)
{
    double array[3][4];
    printf("Enter the elements of a row separated by a space and then press 'enter'  :\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<4; j++)
        {
            scanf("%lf", &array[i][j]);
        };
    };
    for (int i=0; i<3; i++)
    {
        fun (array, i);
    };
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (-1>10000*array[i][j] || 10000*array[i][j]>0)
            {
            printf("%.5f ", array[i][j]);
            };
            if (-1<10000*array[i][j] && 10000*array[i][j]<=0)
            {
            printf("%f ", 0.0);
            };
        };
        printf("\n");
    };
    printf("\n");
    float x, y, z;
    z=array[2][3];
    y=array[1][3]-(z*array[1][2]);
    x=array[0][3]-(y*array[0][1])-(z*array[0][2]);
    printf ("The solution is (%.5f, %.5f, %.5f)", x, y, z);
}