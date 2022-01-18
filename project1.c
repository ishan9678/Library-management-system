#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();
void addBook();
void displayBooks();
struct books
{
    char Title[100];
    char Author[25];
    char Genre[25];
    int pages;
    float cost;
}library[200];
int i = 0;
FILE *fPointer;
char readFile[200];
int main()
{
    int choice;
    fPointer = fopen("bookList","a+");
    do
    {
        putchar('\n');
        menu();
        putchar('\n');
        puts("Enter a choice");
        scanf("%d%*c",&choice);
        putchar('\n');

        switch(choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                exit(0);
            default: printf("\n%d is not a valid choice\n",choice);
                     continue;
        }
    }while((choice>=1)||(choice<=3));
    fclose(fPointer);
    return 0;
}
void menu()
{
    puts("What do you want to do?");
    puts("1. Add a new book");
    puts("2. Display existing books");
    puts("3. Exit");
}
void addBook()
{
    fprintf(fPointer,"\n");
    puts("Enter title of the book");
    fgets(library[i].Title,sizeof(library[i].Title),stdin);
    fprintf(fPointer,"Book name: %s",library[i].Title);
    puts("Enter name of the author");
    fgets(library[i].Author,sizeof(library[i].Author),stdin);
    fprintf(fPointer,"Author name: %s",library[i].Author);
    puts("Enter name of the genre");
    fgets(library[i].Genre,sizeof(library[i].Genre),stdin);
    fprintf(fPointer,"Genre: %s",library[i].Genre);
    puts("Enter the number of pages");
    scanf("%d",&library[i].pages);
    fprintf(fPointer,"Page count: %d\n",library[i].pages);
    puts("Enter the price of the book");
    scanf("%f",&library[i].cost);
    fprintf(fPointer,"Price: %.2f rupees\n",library[i].cost);
    i++;
}
void displayBooks()
{
    fseek(fPointer,0,SEEK_SET);
    while(!feof(fPointer))
    {
        fgets(readFile,sizeof(readFile),fPointer);
        readFile[strcspn(readFile,"\n")] = 0;
        puts(readFile);
    }
}


