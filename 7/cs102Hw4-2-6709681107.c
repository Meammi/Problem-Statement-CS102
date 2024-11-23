#include<stdio.h>
#include<string.h>

struct dataPerson{
    int id;
    char name[50];
    int age;
    float income;
};

int main(){
    struct dataPerson list[100];
    int choice = 0;
    int i = 0;

    while (choice != 3)
    {
        printf("Poverty Registration System \n1. Register New Person \n2. Display All Registered Persons \n3. Exit\n");
        printf("==\nEnter your choice: ");
        scanf(" %d",&choice);

        if(choice == 1){
            printf("Enter ID:");
            scanf(" %d",&list[i].id);
            printf("Enter Name:");
            scanf(" %[^\n]%*c",list[i].name);
            printf("Enter Age: ");
            scanf(" %d",&list[i].age);
            printf("Enter Income: ");
            scanf(" %f",&list[i].income);
            i++;
        }
        else if(choice == 2){
            if(i > 0){
                printf("ID   Name               Age     Monthly Income\n");
                int j = 0;
                while( j < i){
                    printf("%-5d%-20s%-5d%.2f\n",list[j].id,list[j].name,list[j].age,list[j].income);
                    j++;
                }
            }
            else{
                printf("No registered persons to display.\n");
            }
        }
        printf("==\n");
    }
    

    return 0;
}