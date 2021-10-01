//Dashboard for our Project! iCare la Gestion
#include <stdio.h>
#include <st

//Function to sign up

    scanf("%s", &users[i].password);
    for (j = 0; j < strlering.h>
#include <time.h>
#include<math.h>

//LOGIN PART
struct authentic
{
    char username[50];
    char password[50];
} users[20];n(users[i].password); j++)
    {
        if (isdigit(users[i].password[j]))
        {
            counter = 1;
        }
    }
    if (counter == 0)
    {
        printf("Pasword too Weak, Enter strong password\n");
        goto label;
    }
    printf("Succesfully Registered!\n");
    i++;
}
//function to login
void login()
{
    char temp[50], temp1[50];
    int us = 0;
    printf("Enter valid username\n");
    scanf("%s", &temp);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(temp, users[i].username) == 0)
        {
            us = 1;
            printf("Enter password:\n");
            scanf("%s", &temp1);
            if (strcmp(temp1, users[i].password) == 0)
            {
               
            }
            else
            {
                printf("Wrong password!\n");
                login();
            }
        }
    }
    if(us != 1)
    {
        login();
    }
}
void authenticate()
{
    int temp;
    int i = 1;
    while (i)
    {
        printf("Enter 1 to Signup\nEnter 2 for login\n");
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            i = 0;
            break;

        default:
            exit(0);
        }
    }
}
/* CANTEEN PART
 * iCare la Gestion!
 */

    int ward_num;
} u[100];
void signup()
{
    int i = 0, j = 0, counter = 0;
    printf("Enter an Username\n");
    scanf("%s", &users[i].username);
    printf("Enter a strong password\n");
label:
//structure to enter food item details
struct item
{
    int avail;
    int price;
} item[10];

//function to display menu
void display_menu()
{
    item[0].price = 20;
    item[1].price = 30;
    item[2].price = 40;
    item[3].price = 25;
    item[4].price = 18;
    item[5].priceitem[5].avail, item[5].price);
    printf("Veg Puff \t %d \t\t %d\n", item[6].avail, item[6].price);
    printf("Salad    \t %d \t\t %d\n", item[7].avail, item[7].price);
    printf("Bonda    \t %d \t\t %d\n", item[8].avail, item[8].price);
    printf("Vada     \t %d \t\t %d\n", item[9].avail, item[9].price);
}

//structer to enter coustmer details
struct user
{
    char name[50];
    char type;
//function to take coustmers order
void manager_update()
{
    printf("To update do the following steps\n Press 0 for Samosa\n");
    printf("Press 1 for Cutlet\n");
    printf("Press 2 for Sandwich\n");
    printf("Press 3 for Vada Pav\n");
    printf("Press 4 for Bhelpuri\n");
    printf("Press 5 for Dhokla\n");
    printf("Press 6 for Veg puff\n");
    printf("Press 7 for Salad\n");
    printf("Press 8 for Bonda\n");
    printf("Press 9 for Vada\n");

    int i;
    scanf("%d", &i);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    item[2].price = 40;
    item[3].price = 25;
    item[4].price = 18;
    item[5].price = 20;
    item[6].price = 10;
    item[7].price = 8;
    item[8].price = 19;
    item[9].price = 35;
    int i = 0, temp1, temp2, bill = 0, order_next = 1, next_cust = 1;
    while = 20;
    item[6].price = 10;
    item[7].price = 8;
    item[8].price = 19;
    item[9].price = 35;
    printf("Snack:\n Item name: \t Available \t Price\n");
    printf("Samosa   \t %d \t\t %d\n", item[0].avail, item[0].price);
    printf("Cutlet   \t %d \t\t %d\n", item[1].avail, item[1].price);
    printf("Sandwich \t %d \t\t %d\n", item[2].avail, item[2].price);
    printf("Vada Pav \t %d \t\t %d\n", item[3].avail, item[3].price);
    printf("Bhelpuri \t %d \t\t %d\n", item[4].avail, item[4].price);
    printf("Dhokla   \t %d \t\t %d\n", 
            printf("Ward number\n");
            scanf("%d", &u[i].ward_num);
        }

        //asking coustmer for next order
        while (order_next)
        {
            printf("To order do the following steps\n Press 0 for Samosa\n");
            printf("Press 1 for Cutlet\n");
            printf("Press 2 for Sandwich\n");
            scanf("%d", &temp1);
                printf("Update Current Available Items\n");
    scanf("%d", &item[i].avail);
}

//fumction to give bill
void billing()
{
    item[0].price = 20;
    item[1].price = 30;
            printf("Enter quantity\n");
            scanf("%d", &temp2);
            //to check availability of the stock
            if (item[temp1].avail >= temp2)
            {
                item[temp1].avail = item[temp1].avail - temp2;
                bill = bill + (item[temp1].price) * temp2;
            }
            else
            {
                printf("OUT OF STOCK, We are really sorry!\n");
            }

            printf("Order one more item? Enter any non-zero value \n");
            scanf("%d", &order_next);
        }
        if (u[i].ward_num != NULL)
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Your total bill is Rs %d inclusive of Rs 10 Delivery charge to ward number %d\n", bill + 10, u[i].ward_num);
            
        }
        else
      al bill is Rs %d", bill);
        }  
        printf("Customer on line? Press 1 else 0");
        scanf("%d", &next_cust);
        i++;
    }
    temp1 = 0, temp2 = 0;
    bill = 0;
}

//canteen reception
void canteen()
{
    int temp;
    while (1)
    {
        printf("Enter 1 to Display Menu\nEnter 2 for Updating stocks\nEnter 3 for Bill\nAny other key to exit\n");
        scanf("%d", &temp);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        switch (temp)
        {
        case 1:
            display_menu();
            break;
        case 2:
            manager_update();
            break;
        case 3:
            billing();
            break;
        default:
     {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Your tot
    int id;
    int type;
    float entry_time;
    float exit_time;
    float diff_time;
    int vacancy;

} park[100];

//Function to find quickest vacant slot
int find_least_slot(struct vehicle *park)
{
    int k = 0, i = 0;
    while (park[i].vacancy == 0 && i < 100)
    {
        k++;
        i++;
    }
    return k;
}

//Function to return local time
float time_calculation()
{
    time_t get_time;
    time(&get_time);
    printf("%s", get_time);
    return (difftime(0, get_time));
}

void exit_parking(struct vehicle *park)
{
    int id_check, temp = 0;
    printf("Enter your unique id: \n");
    scanf("%d", &id_check);

    //Find Slot by having unique id
    for (int i = 0; i < 100; i++)
    {
        if (park[i].id == id_check)
        {
            temp = i;
        }
    }
    //park[temp].exit_time = time_calculation();
    //printf("%d", park[temp].diff_time);
    payment(&park, temp);
    park[temp].vacancy = 0;
}

void payment(struct vehicle *park, int m)
{
    int fare = 0;
   // printf("hii\n");
    //Giving fares According to type and time
    if (park[m].type == 2)
    {
        if (park[m].diff_time < 60 * 60)
        {
            fare = 30;
        }
        else if (park[m].diff_time < 2 * 60 * 60)
        {
            fare = 50;
        }
        else
        {
            fare = 50 + ((park[m].diff_time / 60 * 60)+1) * 10;
        }
    }
    else
    {
        if (park[m].diff_time < 60 * 60)
        {
            fare = 50;
        }
        else if (park[m].diff_time < 2 * 60 * 60)
        {
            fare = 80;
        }
        else
        {
            fare = 80 + ((park[m].diff_time / 60 * 60)+1) * 10;
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Your total fare was = Rs%d\n", fare);
    
}

void parking()
{
    int i, j, temp = 1;
    for (i = 0; i < 100; i++)
    {
        park[i].vacancy = 0;
    }

    while (temp)
    {
        int least_slot_available = find_least_slot(&park);
        printf("Enter your unique id\n");
        scanf("%d", &park[least_slot_available].id);

        j = 0;
        for (i = 0; i < 100; i++)
        {
            if (park[i].vacancy == 0)
                break;
            else
                j++;
        }
        //park[least_slot_available].entry_time = time_calculation();
        //Enter Details and feeding it to struct elements
        printf("Enter vehicle type:\n");
        printf("2-wheeler\tPress 2\n4-wheeler\tPress 4\nType:\t");
        scanf("%d", &park[j].type);
        printf("Park at cabin number %d\n", j);
        park[j].vacancy = 1;
        printf("The next car is in queue? \n");
        scanf("%d", &temp);
        if (temp == 3)
        {
            exit_parking(&park);
        }
        else if (temp >= 100)
        {
            exit(1);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}
/*LIBRARY PART 
 *iCare la gestion!
 */

//defining the properties of the fields used in the program

#define IN 1
#define OUT 0

void Add_book();
void Search_book();
void Display_book();
void author();
void stock();
void Exit();

char info[500];

//structure to enter book details
struct
{
    int book_id;
    char book_name[25];
    char author[25];
    int num_of_chaps;
    char title[500];
    int status;
} book;

//initializing the files used in the program
FILE *library_record;

int library()
{
    int choice = 0, i;

    do
    {
        // main menu of the library
        printf("\n\t~~MENU~~\n 1> Add New Book\n 2> Search book \n 3> Display Complete Information\n 4> Display Books of a paticular author\n 5> List the Count of Books (Issued & in stock)\n \n\n\t Enter your choice <1-5>: ");
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            Add_book();
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        case 2:
            Search_book();
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        case 3:
            Display_book();
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        case 4:
            author();
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        case 5:
            stock();
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        case 6:
            Exit();
        default:
            printf(" ! Invalid Input...\n");
        }
    } while (choice != 10);
    return (0);
}

// adding a new book to the library
void Add_book()
{
    int i;
    book.status = IN;
    //opening the library_record file
    library_record = fopen("library_record.txt", "a+");
    printf("Enter The uniqueid of The Book :(Integer) \n");
    scanf("%d", &book.book_id);
    printf("Enter The Name of The Book :\n");
    scanf("%s", book.book_name);
    printf("Enter The Name of author :\n");
    scanf("%s", book.author);
    printf("Enter The Number of title Of The Book:(Integer)\n");
    scanf("%d", &book.num_of_chaps);
    fprintf(library_record, "\n%d\t%s\t%s\t%d\t%d\t", book.book_id, book.book_name, book.author, book.status, book.num_of_chaps);
    printf("Enter The title Of The Book : \n");
    for (i = 0; i < book.num_of_chaps; i++)
    {
        scanf("%s", book.title);
        fprintf(library_record, "%s\t", book.title);
    }
    fclose(library_record);
    printf("A New Book has been Added Successfully...\n");
}

//function to display a particular book details
void Display_book()
{
    library_record = fopen("library_record.txt", "a+");
    printf("\nBookid\tName\tAuthor\tStatus\tNo.\tTitles\n", info);
    do
    {
        fgets(info, 500, library_record);
        printf("%s\n", info);
    } while (!feof(library_record));
    fclose(library_record);
}

//function to a search a book
void Search_book()
{
    int i;
    char Target[25], stats[3];
    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The File is Empty...\n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
        scanf("%s", Target);
        while (!feof(library_record) && Found == 0)
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (strcmp(Target, book.book_name) == 0)
                Found = 1;
            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        if (Found)
        {
            if (book.status == IN)
                strcpy(stats, "IN");
            else
                strcpy(stats, "OUT");

            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe author is:  %s\nThe Book Status %s\n\n", book.book_id, book.book_name, book.author, stats);
        }
        else if (!Found)
            printf("! There is no such Entry...\n");
        fclose(library_record);
    }
}

//function to display books written by a particular author
void author()
{
    int i;
    char Target[500];
    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The file is empty... \n\n");
    else
    {
        printf("\nEnter The Name Of author : ");
        scanf("%s", Target);
        printf("\nBooks:");
        while (!feof(library_record))
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (strcmp(Target, book.author) == 0)
            {
                Found = 1;
                printf("\n\t%s", book.book_name);
            }
            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        if (!Found)
            printf(" Alas We dont have it here sir!\n");
        fclose(library_record);
    }
}

//function to check and count the stock
void stock()
{
    int i, stockcount = 0;

    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while (!feof(library_record))
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (book.status == IN)
            {
                stockcount++;
            }
            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        fclose(library_record);
        printf("\nCount of  of Books in stock:%d\n", stockcount - 1);
    }
}
void Exit()
{
    exit(0);
}
