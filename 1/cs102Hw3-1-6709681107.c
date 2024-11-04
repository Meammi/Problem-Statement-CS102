#include <stdio.h>
void minmax_Value(double num[],int length);
void reverse_Order(double num[],int lenght);
double avg_func(double num[],int length);
void above_Avg(double num[],int lenght,double avg);
void nav_Coordinate(double num[],int length);

int main(){
    // Input index
    int index = 0;
    double avg = 0;
    scanf(" %d\n",&index);
    double num[index];

    //Input array
    int i = 0;
    while (i < index)
    {
        scanf(" %lf",&num[i]);
        i++;
    }

    //call function
    minmax_Value(num,index);
    avg = avg_func(num,index);
    printf("Average: %.2lf",avg);
    reverse_Order(num,index);
    above_Avg(num,index,avg);
    nav_Coordinate(num,index);
    
    return 0;
}
//function check min&max&avg
void minmax_Value(double num[],int length){
    double avg = 0;
    double min_value = num[0];
    double max_value = 0;
    int min_index = 0;
    int max_index = 0;

    int i = 0;
    while(i < length){
        if(num[i] < min_value){
            min_value = num[i];
            min_index = i;
        }
        else if(num[i] > max_value){
            max_value = num[i];
            max_index = i;
        }
        avg = avg + num[i];
        i++;
    }

    printf("Maximum value: %.2lf\nMinimun value: %.2lf\nMaximum index: %d\nMinimum index: %d\n",
    max_value,min_value,max_index,min_index);
}
//function avg
double avg_func(double num[],int length){
    int i = 0;
    double avg = 0;
    while (i < length)
    {
        avg = avg + num[i];
        i++;
    }
    return avg/length;
}
//function reverse order
void reverse_Order(double num[],int lenght){
    int i = lenght-1;

    printf("\nReverse Order:");
    while(i >= 0){
        printf(" %.2lf",num[i]);
        i--;
    }
}
//function Above average
void above_Avg(double num[],int lenght,double avg){
    int i = 0;
    printf("\nAbove average list: ");
    while (i < lenght)
    {
        if (num[i]>avg)
        {
            printf(" %.2lf",num[i]);
        }
        i++;
    }
}
//function Negative Coordinates
void nav_Coordinate(double num[],int length){
    printf("\nNegative Coordinates:");
    int i = 0;
    
    while (i < length) //Check every index in array
    {
        if (num[i] < 0) //Check negative num in array
        {
            int j = i;
            while (j < length)//Find Coordinate and print
            {
                if(num[j] < 0 && num[j] != num[i]){
                    printf(" (%.2lf, %.2lf),",num[i],num[j]);
                }
                j++;
            }
        }
        i++;
    }
    
}
