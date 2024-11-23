#include <stdio.h>

struct client{
    int accountNumber;
    char name[50];
    float blanace;
};
void addCustomer(int *iptr,struct client *listptr);
void deposit(int *iptr,struct client *listptr);
void withdraw(int *iptr,struct client *listptr);
void displayCustomers(int *iptr,struct client *listptr);

int main(){
    struct client list[100];
    int choice = 0;
    int i = 0;

    while(choice != 5){
        printf("Bank Management System\n1. Add New Customer\n2. Deposit Money\n3. Withdraw Money\n4. Display All Customers\n5.Exit\n");
        printf("Enter your chice: ");
        scanf(" %d",&choice);

        if(choice == 1){
            addCustomer(&i, list);
        }
        else if(choice == 2){
            deposit(&i, list);
        }
        else if(choice == 3){
            withdraw(&i, list);
        }
        else if(choice == 4){
            displayCustomers(&i, list);
        }
    }

    printf("Exiting Program.");
    return 0;
}

void addCustomer(int *iptr,struct client *listptr){
    printf("Enter account number:");
    scanf("%d",&listptr[*iptr].accountNumber);
    printf("Enter customer name:");
    scanf(" %[^\n]%*c",listptr[*iptr].name);
    printf("Enter initial balance:");
    scanf("%f",&listptr[*iptr].blanace);

    *iptr += 1;
}

void deposit(int *iptr,struct client *listptr){
    while(1){
        int id;
        printf("Enter account number for deposit:");
        scanf(" %d",&id);
        int j = 0;
        while(j < *iptr){
            if (id == listptr[j].accountNumber){
                float amount = 0;
                printf("Enter amount to deposit:");
                scanf("%f",&amount);
                listptr[j].blanace = listptr[j].blanace + amount;
                printf("Deposit successful. New balance:%.2f\n",listptr[j].blanace);
                return;
            }
            j++;
        }
        printf("account not found.\n");
    }
}

void withdraw(int *iptr,struct client *listptr){
    while(1){
        int id;
        printf("Enter account number for withdrawal:");
        scanf(" %d",&id);
        int j = 0;
        while(j < *iptr){
            if (id == listptr[j].accountNumber){
                float amount = 0;
                printf("Enter amount to withdraw:");
                scanf("%f",&amount);
                if(listptr[j].blanace - amount >= 0){
                    listptr[j].blanace = listptr[j].blanace - amount;
                    printf("Deposit successful. New balance:%.2f\n",listptr[j].blanace);
                    return;
                }
                else{
                    printf("Your money is not enough for withdrawal\n");
                    return;
                }
            }
            j++;
        }
        printf("account not found.\n");
    }
}

void displayCustomers(int *iptr,struct client *listptr){
    int j = 0;
    while(j < *iptr){
        printf("Account Number: %d, Name: %s , Balance: %.2f\n",listptr[j].accountNumber,listptr[j].name,listptr[j].blanace);
        j++;
    }
}