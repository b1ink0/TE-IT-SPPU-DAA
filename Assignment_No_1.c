#include <stdio.h>

struct PW {
    int profit[100];
    int weight[100];
    float ratio[100];
    int capacity;
    int length;
};

struct PW input(){
    struct PW pw;
    int n, p, w;
    printf("<---------------------------->\nInput Number Of Product: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("\nInput Profit & Weight: ");
        scanf("%d %d", &pw.profit[i], &pw.weight[i]);
        pw.ratio[i] = (float) pw.profit[i]/ pw.weight[i];
    }
    printf("\nInput Capacity: ");
    scanf("%d", &pw.capacity);
    pw.length = n;
    return pw;
}

void display(struct PW pw){
    printf("\nProfit   Weight   Ratio\n");
    for (int i = 0; i < pw.length; i++){
        printf("\n%d %s %d %s %f\n", pw.profit[i], "     ", pw.weight[i], "     ", pw.ratio[i]);
    }
    printf("\n%s %d\n", "Capacity:", pw.capacity);
}

struct PW sort(struct PW pw){
    int i, j;
    for (i = 0; i < pw.length - 1; i++){
        for(j = 0; j < pw.length - i - 1;j++){
            if (pw.ratio[j] < pw.ratio[j + 1]){
                int tp = pw.profit[j];
                int tw = pw.weight[j];
                float tr = pw.ratio[j];
                pw.profit[j] = pw.profit[j+1];
                pw.weight[j] = pw.weight[j+1];
                pw.ratio[j] = pw.ratio[j+1];
                pw.profit[j+1] = tp;
                pw.weight[j+1] = tw;
                pw.ratio[j+1] = tr;
            }
        }
    }
    return pw;
}

struct PW sortD(struct PW pw){
    int i, j;
      for (i = 0; i < pw.length - 1; i++){
        for(j = 0; j < pw.length - i - 1;j++){
            if (pw.weight[j] > pw.weight[j + 1]){
                int tp = pw.profit[j];
                int tw = pw.weight[j];
                float tr = pw.ratio[j];
                pw.profit[j] = pw.profit[j+1];
                pw.weight[j] = pw.weight[j+1];
                pw.ratio[j] = pw.ratio[j+1];
                pw.profit[j+1] = tp;
                pw.weight[j+1] = tw;
                pw.ratio[j+1] = tr;
            }
        }
    }
    return pw;
}

void greedy(struct PW pw){
    pw = sort(pw);
    int w = pw.capacity;
    float result = 0;
    for (int i = 0; i < pw.length; i++){
        if(w > pw.weight[i]){
            result += pw.profit[i];
            w -= pw.weight[i];
        } else {
            result += pw.ratio[i] * w;
            break;
        }
    }
    printf("\n%s %f\n", "Greedy Method Solution:", result);
}

int max(int x, int y){
    if (x > y){
        return x;
    } else {
        return y;
    }
}

void dynamicP(struct PW pw){ 
    pw = sortD(pw);
    display(pw);
    int M[pw.length + 1][pw.capacity + 1];
    for (int i = 0; i < pw.length + 1; i++){
        for (int j = 0; j < pw.capacity + 1; j++){
            if(i == 0 || j == 0){
                M[i][j] = 0; 
            } else {
                if (j - pw.weight[i - 1] >= 0){
                    M[i][j] = max(pw.profit[i -1] + M[i-1][j - pw.weight[i - 1]], M[i-1][j]);
                }
                 else if (i == 1) {
                    M[i][j] = 0;
                } else {
                    if (M[i - 1][j] > 0){
                        M[i][j] = M[i - 1][j];
                    } else {
                        M[i][j] = 0;
                    }
                }
            }
        }
    }
    int result[pw.length];
    int temp = M[pw.length][pw.capacity];
    for (int i = pw.length; i >= 0; i--){
        for (int j = pw.capacity; j >= 0; j--){
                 printf("%d ", M[i][j]);
                 if (i > 0){
                    if (M[i][j] == M[i - 1][j]){
                        result[i - 1] = 0;
                        break;
                    } else {
                        if (temp - pw.profit[i - 1] >= 0){
                            result[i - 1] = 1;
                            temp -= pw.profit[i - 1];
                            break; 
                        } else {
                            continue;
                        }
                    }
                 }
        }
         printf("\n");
    }
    printf("\n%s %d\n", "Profit:", M[pw.length][pw.capacity]);
}

int main(){
    struct PW pw;
    int flag = 1;
    while (flag)
    {
        printf("%s", "\nChoose From The Option!\n1.Input Values\n2.Display Values\n3.Greedy Method\n4.Dynamic Programming\n5.Exit..");
        int i;
        printf("\nEnter Choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            pw = input();
            break;
        case 2:
            display(pw);
            break;
        case 3:
            greedy(pw);
            break;
        case 4:
            dynamicP(pw);
            break;
        case 5:
            flag = 0;
            printf("\nExit....\n");
            break;
        default:
            break;
        }
       
    }
    return 0;
}