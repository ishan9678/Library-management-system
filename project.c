#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();
void addBook();
void displayBooks();
void noBooks();
struct books
{
    char Title[100];
    char Author[25];
    char Genre[25];
    int pages;
    float cost;
}library[200];
int count = 0;
int i = 0;
int main()
{
    int choice;
    do
    {
        putchar('\n');
        menu();
        putchar('\n');
        puts("Enter a choice");
        scanf("%d%*c",&choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                noBooks();
                break;
            case 4:
                exit(0);
            default: printf("\n%d is not a valid choice\n",choice);
                     continue;
        }
    }while((choice>=1)||(choice<=4));
    return 0;
}
void menu()
{
    puts("What do you want to do?");
    puts("1. Add a new book");
    puts("2. Display existing books");
    puts("3. Number of books in the library");
    puts("4. Exit");
}
void addBook()
{
    puts("Enter title of the book");
    fgets(library[i].Title,sizeof(library[i].Title),stdin);
    puts("Enter name of the author");
    fgets(library[i].Author,sizeof(library[i].Author),stdin);
    puts("Enter name of the genre");
    fgets(library[i].Genre,sizeof(library[i].Genre),stdin);
    puts("Enter the number of pages");
    scanf("%d",&library[i].pages);
    puts("Enter the price of the book");
    scanf("%f",&library[i].cost);
    count++;
    i++;
}
void displayBooks()
{
    for(i=0;i<count;i++)
    {
        printf("\nDetails of book %d\n",i+1);
        printf("Book name: %s",library[i].Title);
        printf("Author name: %s",library[i].Author);
        printf("Genre: %s",library[i].Genre);
        printf("Page count: %d\n",library[i].pages);
        printf("Price: %.2f\n",library[i].cost);
    }
}
void noBooks()
{
    printf("Total number of books in the library are %d\n",count);
}
