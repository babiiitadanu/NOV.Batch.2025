#include<stdio.h>
#include<string.h>

char name[25];
char password[12];
char tname[25];
char tpassword[12];

void menu();

int busCount=8;

int busNumber[8]={101,102,103,104,105,106,107,108};

char sourceCity[8][20]={
    "Delhi","Mumbai","Jaipur","Kolkata","Bangalore",
    "Chennai","Hyderabad","Pune"
};

char destinationCity[8][20]=
{
    "Bihar","Pune","Udaipur","Goa","Delhi",
    "Kolkata","Chennai","Jaipur"
};

int totalSeats[8]={50,40,45,55,60,50,45,40};
int bookedSeats[8]={0,0,0,0,0,0,0,0};

float fare[8]={500.00,300.00,450.00,550.00,600.00,400.00,350.00,500.00};


void login()
{
    printf("Enter your name: ");
    scanf("%s",&tname);
    if (strcmp(name,tname)==0) 
    {
          printf("Username not matched\n");
    }

    printf("Enter your password: ");
    scanf("%s",&tpassword);
    if (strcmp(password,tpassword)==0) 
    {
          printf("Password matched\n");
          menu();
      } else {
          printf("Password not matched\n");
      }
}

void signup()
{
    int valid = 0;

    while (!valid)
    {
        int i;

        printf("Enter your name: ");
        scanf("%s", name);

        
        if (strlen(name) < 5)
        {
            printf("Name must be at least 5 characters long.\n");
            continue;
        }

      
        for (i = 0; i < strlen(name); i++)
        {
               
            char alpha;
            alpha=name[i];

            if((alpha>='a' && alpha<='z') ||(alpha >= 'A' && alpha <= 'Z') ||(alpha=='@')|| (alpha == '_'))
            {

            }

            
            else 
            {
                 printf("Name must contain only alphabets.\n");
                break;

            }

            
        }

        if (i < strlen(name))
            continue;

        printf("Enter your password: ");
        scanf("%s", password);

      
        if (strlen(password) < 6)
        {
            printf("Password must be at least 6 characters long.\n");
            continue;
        }

      
        if (strcmp(name, password) == 0)
        {
            printf("Password cannot be same as name.\n");
            continue;
        }

        
        for (i = 0; i < strlen(password); i++)
        {
            if (!((password[i] >= 'A' && password[i] <= 'Z') ||
                  (password[i] >= 'a' && password[i] <= 'z') ||
                  (password[i] >= '0' && password[i] <= '9')))
            {
                printf("Password can contain only letters and numbers.\n");
                break;
            }
        }
        if (i < strlen(password))
            continue;
            if (strcasecmp(name, password) == 0)
{
    printf("Password cannot be same as name (case-insensitive).\n");
    continue;
}

        valid = 1;
        printf("Signup successful!\n");
    }
}

void mainmenu()
{
    while (1)
    {        
        int choice;
        printf("\033[31m");
        printf("\nBUS RESERVATION SYSTEM\n");
        printf("\033[0m");

        printf("\033[33m");
        printf("1.Signup\n");
        printf("2.Login\n");
        printf("3.Exit\n");
        printf("\033[0m");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            signup();
            break;
            
            case 2:
            login();
            break;
            
            case 3:
            printf("Exit successfully\n");
            return;
            
            default:
            printf("Invalid option\n");
            break; 
        }
    }
}

void bookTicket()
{
    int busNo,seats,i;

    printf("Available buses and their details:\n");

    for (i=0;i<busCount;i++) {
        printf("Bus Number: %d\n",busNumber[i]);
        printf("Source City: %s\n",sourceCity[i]);
        printf("Destination City: %s\n",destinationCity[i]);
        printf("Available Seats: %d\n",totalSeats[i] - bookedSeats[i]);
        printf("Fare: %.2f\n\n",fare[i]);
    }

    printf("Enter Bus Number to book: ");
    scanf("%d",&busNo);

    for (i=0;i<busCount;i++)
    {
        if (busNumber[i]==busNo)
        {
            printf("You have selected Bus %d\n",busNo);
            printf("Source City: %s\n",sourceCity[i]);
            printf("Destination City: %s\n",destinationCity[i]);
            printf("Available Seats: %d\n",totalSeats[i] - bookedSeats[i]);
            printf("Fare: %.2f\n",fare[i]);

            printf("Enter Number Of Seats to Book: ");
            scanf("%d",&seats);

            if (bookedSeats[i] + seats<=totalSeats[i])
            {
                bookedSeats[i] +=seats;
                printf("\nBooking Successful! %d seats booked on Bus %d\n",seats,busNo);
            }
            else
            {
                printf("Not enough seats available\n");
            }
            return;
        }
    }
    printf("Invalid Bus Number\n");
}

void cancelTicket()
{
    int busNo,seats,i;

    printf("Enter Bus Number: ");
    scanf("%d",&busNo);

    for (i=0;i<busCount;i++)
    {
        if (busNumber[i]==busNo)
        {
            printf("Enter Seats to Cancel: ");
            scanf("%d",&seats);

            if (seats<=bookedSeats[i])
            {
                bookedSeats[i] -=seats;
                printf("Ticket cancelled successfully\n");
            }
            else
            {
                printf("Invalid seat count\n");
            }
            return;
        }
    }
    printf("Invalid Bus Number\n");
}

void checkBusStatus()
{
    int busNo,i;

    printf("Please enter Bus Number: ");
    scanf("%d",&busNo);

    for (i=0;i<busCount;i++)
    {
        if (busNumber[i]==busNo)
        {
            printf("\033[34m");
            printf("\nBus Number:        %d\n",busNumber[i]);
            printf("Source City:        %s\n",sourceCity[i]);
            printf("Destination City:   %s\n",destinationCity[i]);
            printf("Total Seats:        %d\n",totalSeats[i]);
            printf("Available Seats:    %d\n",totalSeats[i] - bookedSeats[i]);
            printf("Fare:               %.2f\n",fare[i]);
            printf("\033[0m");
            return;
        }
    }
    printf("Invalid Bus Number\n");
}

void logout()
{
    printf("Logged out successfully\n");
}

void menu()
{
    int number;

    while (1)
    {
        printf("\033[31m");
        printf("\n  USER MENU  \n");
        printf("\033[0m");

        printf("\033[33m");
        printf("1.Book a Ticket\n");
        printf("2.Cancel a Ticket\n");
        printf("3.Check Bus Status\n");
        printf("4.Logout\n");
        printf("\033[0m");

        printf("Please enter your choice: ");
        scanf("%d",&number);

        if (number==1)
        {
            bookTicket();
        }
        else if (number==2)
        {
            cancelTicket();
        }
        else if (number==3)
        {
            checkBusStatus();
        }
        else if (number==4)
        {
            logout();
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
}

int main()
{
    mainmenu();
    return 0;
}