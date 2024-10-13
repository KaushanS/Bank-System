#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_LENGTH 10

//global variable
char CusName[50],cusPass[20],cusIdnum[MAX_LENGTH],cusUsername[MAX_LENGTH];


//account creation
void accountCreate(){
    int newbalance=0;

    FILE *cusDetails=fopen("CustomerDetails.txt","a");

    //customer details
    printf("\n\n\n========================================================");
    printf("\n\nCreate your user name here:");
    scanf("%s",&cusUsername);
    printf("Create your Password here :");
    scanf("%s",&cusPass);
    printf("Enter your name here :");
    scanf("%s",&CusName);
    printf("Enter your Id number here :");
    scanf("%s",&cusIdnum);

    //random number
    srand(time(NULL));

    int randomNumber = rand() % 100000 + 80070000;

    printf("\n\nYour Account number: %d\n", randomNumber);

    system("cls");

    printf("\nAccount create successfully......!!!!\n\n");

    fprintf(cusDetails,"\n%s\t\t%s\t\t%s\t\t%s\t\t\t%d\t\t%d",cusUsername,cusPass,CusName,cusIdnum,randomNumber,newbalance);

    fclose(cusDetails);  // Close the file

    checking();


}
void deposit(char *username) {
    int amount;
    printf("\n\t\t  Enter the amount to deposit: ");
    scanf("%d", &amount);

    // Open the file in read mode
    FILE *cusCheck = fopen("CustomerDetails.txt", "r");

    // Create a temporary file to write the updated data
    FILE *tempFile = fopen("temp.txt", "w");

    char showUser[MAX_LENGTH], showPass[MAX_LENGTH], showId[10], showName[50];
    int balance, showAcc;

    // rite the updated data
    while (fscanf(cusCheck, "%s%s%s%s%d%d", showUser, showPass, showName, showId, &showAcc, &balance) == 6) {
        if (strcmp(username, showUser) == 0) {
            // pdate the balance
            balance += amount;
        }

        // Write the data to the temporary file
        fprintf(tempFile, "\n%s\t\t%s\t\t%s\t\t%s\t\t\t%d\t\t%d", showUser, showPass, showName, showId, showAcc, balance);
    }

    fclose(cusCheck);
    fclose(tempFile);

    // Delete the original file
    remove("CustomerDetails.txt");
    rename("temp.txt", "CustomerDetails.txt");

    system("cls");

    printf("\n\t\t  Deposit successful! Your new balance is %d.\n", balance);


}

// Withdraw money
void withdraw(char *username) {
    int amount;
    printf("\n\t\t  Enter the amount to withdraw: ");
    scanf("%d", &amount);

    // Open the file in read mode
    FILE *cusCheck = fopen("CustomerDetails.txt", "r");

    // Create a temporary file to write the updated data
    FILE *tempFile = fopen("temp.txt", "w");

    char showUser[MAX_LENGTH], showPass[MAX_LENGTH], showId[10], showName[50];
    int balance, showAcc;

    // Read the data from the file and write the updated data to the temporary file
    while (fscanf(cusCheck, "%s%s%s%s%d%d", showUser, showPass, showName, showId, &showAcc, &balance) == 6) {
        if (strcmp(username, showUser) == 0) {
            // If the username matches, update the balance
            if (balance >= amount) {
                balance -= amount;
            } else {
                printf("\n\t\t  Insufficient balance!\n");
                return;
            }
        }

        // Write the data to the temporary file
        fprintf(tempFile, "\n%s\t\t%s\t\t%s\t\t%s\t\t\t%d\t\t%d", showUser, showPass, showName, showId, showAcc, balance);
    }

    fclose(cusCheck);
    fclose(tempFile);

    // Delete the original file and rename the temporary file
    remove("CustomerDetails.txt");
    rename("temp.txt", "CustomerDetails.txt");

    system("cls");

    printf("\n\t\t  Withdrawal successful! Your new balance is %d.\n", balance);
}
//checking user name and password
void checking()
{

    char showUser[MAX_LENGTH],showPass[MAX_LENGTH],showId[10],showName[50];
    char checkUser[MAX_LENGTH],checkPass[20],password[MAX_LENGTH],checkName[MAX_LENGTH];
    int found = 0, deposit_amount=0,balance=0,showAcc;
    char choose;

    printf("\n========================================================");
    printf("\n\nEnter your User name and Password\n");
    printf("Enter your user name : ");
    scanf("%s",&checkUser);
    printf("Enter your password: ");
    scanf("%s",&checkPass);

    FILE *cusCheck=fopen("CustomerDetails.txt","r");

  while(fscanf(cusCheck,"%s%s%s%s%d%d",showUser,showPass,showName,showId,&showAcc,&balance)==6)
{
    if(strcmp(checkUser,showUser)==0 && strcmp(checkPass,showPass)==0)
    {
        found = 1;
        break;
    }
}
    fclose(cusCheck);

    system("cls");

    //check if user name and password combination

    if(found)
        {
        printf("\n\nLogin successful...!\n\n");
        printf("\n========================================================");
        printf("\n\t\t  Your account details\n\n");
        printf("\t\t  Username: %s\n", showUser);
        printf("\t\t  Password: %s\n", showPass);
        printf("\t\t  ID: %s\n", showId);
        printf("\t\t  Name: %s\n", showName);
        printf("\t\t  Account Number: %d\n", showAcc);
        printf("\t\t  Balance: %d\n", balance);

         char option;
        do {
            printf("\n========================================================");
            printf("\n\t\t  Please select your option\n\n\t\t  D.Deposit money\n\t\t  W.Withdraw money\n\t\t  E.Exit\n");
            printf("\n\t\t  Enter your option: ");
            scanf(" %c", &option);

            if (option == 'D' || option == 'd')
            {
                deposit(showUser);

            }
            else if (option == 'W' || option == 'w')
            {
                withdraw(showUser);

            }
            else if (option == 'E' || option == 'e')
            {
                printf("Exiting...\n");
            }
            else
            {
                printf("\n\nInvalid input!!!\n");
            }
        }
        while (option != 'E' && option != 'e');
    }
    else
    {
        printf("\n\nInvalid user name or password..!!!!!!\n");
    }
}
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}



//..............................................................................................................


int main()
{
    char option;
    printf("\n\n\t\t\t**********WELCOME TO FUTURE BANKING**********\n\n");
    gotoxy(18, 5);
    printf("\t\t**********************************");
    gotoxy(25, 7);
    printf("\n****BANK ACCOUNT SYSTEM MENU****\n\n");
    gotoxy(20, 10);
    printf("\nPLEASE SELECT YOUR OPTION\n\n");
    gotoxy(20,14);
    printf("A.Create account\n");
    gotoxy(20,16);
    printf("B.Already user..Log in...\n");

    printf("\n\t\t    Please select your option: ");

    scanf(" %c",&option);

    if(option=='A'||option=='a')
    {
        accountCreate();
    }
    else if(option=='B'||option=='b')
    {
        checking();
    }
    else
    {
        printf("Invalid input!!!");
    }

return 0;
}
