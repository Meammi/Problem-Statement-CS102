#include <stdio.h>
int check_Num(int N,int matrix[][N]);
int check_Sum(int N,int matrix[][N]);

int main(){
    //Input dimesion of matrix
    int N = 0;
    scanf(" %d",&N);
    //Input Matrix using multidimensional array
    int matrix[N][N];
    int i = 0;
    while(i < N){
        int j = 0;
        while(j < N){
            scanf(" %d",&(matrix[i][j]));
            j++;
        }
        i++;
    }

    int check_Unique = check_Num(N,matrix);//Check every element is not same.
    int check_MagicSquare = check_Sum(N,matrix);//Check sum of row, column, and diagonal is equal.
    if (check_MagicSquare == 1 && check_Unique == 1){//Check Two condition Unique and Sum is true
        printf("This is a magic square!");
    }
    else{
        printf("This is NOT a magic square!");
    }
    
    return 0;
}
//Check all element
int check_Num(int N,int matrix[][N]){
    int i = 0;
    while (i < N)
    {
        int j = 0;
        while (j < N)   
        {
            int l = 0;
            while (l < N)//loop row to compare
            {
                int k = 0;
                while (k < N)//loop column to compare
                {
                    if(matrix[i][j] == matrix[l][k] && (i != l || j != k)){
                        return 0;
                    }
                    k++;
                }
                l++;
            }
            j++;
        }
        i++;
    }
    return 1;
}
int check_Sum(int N,int matrix[][N]){
    int sumCol = 0;
    int sumRow = 0;
    int sumDia = 0;

    int i = 0;
    int j = 0;
    int temp = 0;
    //Check sum of each row is equal.
    while (i < N){
        j = 0;
        sumRow = 0;
        while (j < N){//Sum Row.
            sumRow = sumRow + matrix[i][j];
            j++;
        }
        if(i != 0 && temp != sumRow){//Compare sum from previous loop with sum from the current loop which this is not the first loop.
            return 0;
        }
        temp = sumRow;
        i++;
    }
    sumRow = 1;//if the code reaches to this line that means sum of each row is equal. set SumRow to one represent that it is true.
    j = 0;//pepare for next loop.
    i = 0;
    //Check sum of each Column is equal.
    while (j < N){
        i = 0;
        sumCol = 0;
        while (i < N){//Sum Column.
            sumCol = sumCol + matrix[i][j];
            i++;
        }
        if(j != 0 && temp != sumCol){//Compare sum from previous loop with sum from the current loop which this is not the first loop.
            return 0;
        }
        temp = sumCol;
        j++;
    }
    sumCol = 1;//if the code reaches to this line that means sum of each Column is equal. set SumCol to one represent that it is true.
    j = 0;//peapre for next loop.
    i = 0;
    //Check sum of each diagonal is equal.
    int checkDial = 0; //diagonal from top left to bottom right.
    int checkDiar = 0; //diagonal from top right to bottom left.
    while (i < N){
        checkDial = checkDial + matrix[i][i];
        checkDiar = checkDiar + matrix[i][N-i-1];
        i++;
    }
    if(checkDial == checkDiar){//Check if sum of each diagonal is equal. Set sumDia to 1 represent that it is true.
        sumDia = 1;
    }
    
    if(sumCol == 1 && sumRow == 1 && sumDia == 1){//Check every if condition is true return 1 to represent sum of each column, row, and diagonal is equal.
        return 1;   
    }
    else{
        return 0;
    }
}