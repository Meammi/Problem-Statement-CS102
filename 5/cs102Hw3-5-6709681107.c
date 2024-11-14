#include <stdio.h>

// Question 5 of Homework 3 (CS102 HW3 1/2567)
// Your program will not successfully be compiled and run properly until readSquare and findMagicNumber functions are defined correctly.
// Let's define readSquare and findMagicNumber functions here !
void readSquare(int arr[8][8], int N);
int findMagicNumber(int arr[8][8], int N);

int main(){

    int arr[8][8]; 
    int N;

    scanf("%d", &N);
    readSquare(arr, N);
    
    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}

void readSquare(int arr[8][8], int N){
    int i = 0;
    while(i < N){
        int j = 0;
        while(j < N){
            scanf(" %d",&(arr[i][j]));
            j++;
        }
        i++;
    }
}

int findMagicNumber(int arr[8][8], int N){
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
                    if(arr[i][j] == arr[l][k] && (i != l || j != k)){
                        return -1;
                    }
                    k++;
                }
                l++;
            }
            j++;
        }
        i++;
    }

    int sumCol = 0;
    int sumRow = 0;
    int sumDia = 0;

    i = 0;
    int j = 0;
    int temp = 0;

    while (i < N){
        j = 0;
        sumRow = 0;
        while (j < N){//Sum Row.
            sumRow = sumRow + arr[i][j];
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
            sumCol = sumCol + arr[i][j];
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
        checkDial = checkDial + arr[i][i];
        checkDiar = checkDiar + arr[i][N-i-1];
        i++;
    }
    if(checkDial == checkDiar){//Check if sum of each diagonal is equal. Set sumDia to 1 represent that it is true.
        sumDia = 1;
    }
    
    if(sumCol == 1 && sumRow == 1 && sumDia == 1){//Check every if condition is true return 1 to represent sum of each column, row, and diagonal is equal.
        return checkDial;   
    }
    else{
        return -1;
    }
}