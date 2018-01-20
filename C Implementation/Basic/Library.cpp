#include <iostream>
#include <cstring>

using namespace std;

void books(struct Book *book,int *val);

struct Book
{
    string  title;
    string  author;
    string  subject;
    int     book_id;
};


int main()
{
    int a=5;
    struct Book book1;
    struct Book book2;

    book1.title="Learn C++ Programming";
    book1.author="Chand Miyan";
    book1.subject="C++/C";
    book1.book_id=1;

    books(&book1,&a);

    book2.title="Learn Java Programming";
    book2.author="Chand Miy";
    book2.subject="Java Programming";
    book2.book_id=2;

    books(&book2,&a);
}

void books(struct Book *book, int *val)
{

   printf("Value = %d",*val);
   printf("\n");
   cout << "Book title : " << book->title <<endl;
   cout << "Book author : " << book->author <<endl;
   cout << "Book subject : " << book->subject <<endl;
   cout << "Book id : " << book->book_id <<endl;
}
