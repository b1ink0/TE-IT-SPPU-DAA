#include <stdio.h>
int M[10][10] = {
    {0, 20, 30, 10, 11},
    {15, 0, 16, 4, 2},
    {3, 5, 0, 2, 4},
    {14, 6, 18, 0, 3},
    {16, 4, 7, 16, 0}},
    cost = 0, n = 5, completd[10];
    
void TCP(int city);
int least(int city);

void TCP(int city)
{
    int i, ncity;
    completd[city] = 1;
    printf("%d-->", city + 1);

    ncity = least(city);
    
    if (ncity == 999){
        ncity = 0;
        printf("%d", ncity + 1);
        cost += M[city][ncity];
        return;
    }
    TCP(ncity);
}

int least(int city){
    int i, ncity = 999, min = 999, kmin;    

    for (int i = 0; i < n; i++){
        if (M[city][i] != 0 && completd[i] == 0){
            if (M[city][i] + M[i][city] < min){
                min = M[city][i] + M[i][city];
                kmin = M[city][i];
                ncity = i;
            }
        }
    }
    if (min != 999){
        cost += kmin;
    }
    return ncity;
}

int main()
{
    for(int i = 0; i< n; i++)
        completd[i] = 0;
    TCP(0);
    printf("\n%s %d\n", "Min Cost:", cost);
    // MReduce(M);
    return 0;
}