#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power (int x, int a)
{
    if(a==0)
    {
        return 1;
    }
    else{
        return x*power(x, a-1);
    }
}
int abs(int x)
{
    if(x<0)
    {
        x*=-1;
    }
    return x;
}

int main()
{
    FILE * fpointer = fopen("points.txt", "r");
    int num = 0;
    fscanf(fpointer, "%d", &num);
    int x_coordinates[num];
    int y_coordinates[num];
    for(int i=0; i<num; i++)
    {
        fscanf(fpointer, "%d %d", &x_coordinates[i], &y_coordinates[i]);
    }

    int distance= abs(x_coordinates[0]-x_coordinates[1])+ abs(y_coordinates[0]-y_coordinates[1]);
    int first, second;
    for(int k=0; k<num; k++)
    {
        for (int j=k+1; j<num; j++)
        {
            if(abs(x_coordinates[k]-x_coordinates[j])+ abs(y_coordinates[k]-y_coordinates[j])< distance)
            {
                distance=abs(x_coordinates[k]-x_coordinates[j])+ abs(y_coordinates[k]-y_coordinates[j]);
                first=k;
                second=j;
            }
        }
    }
    printf("The smallest distance is between: \n");
    printf("%d and %d (in the human way of counting)", first+1, second+1);
    printf("\nThe distance: ");
    printf("%d", distance);






    fclose(fpointer);

    return 0;
}
