#include <gtest/gtest.h>

#include "book.h"

TEST(BookTest, Constructor) 
{
    Book book("1984", "George Orwell", "978-3730614389");

    EXPECT_EQ("1984", book.title());
    EXPECT_EQ("George Orwell", book.author());
    EXPECT_EQ("978-3730614389", book.isbn());
}

TEST(BookTest, ConstructorWithNew) 
{
    Book* book = new Book("1984", "George Orwell", "978-3730614389");

    EXPECT_EQ("1984", book->title());
    EXPECT_EQ("George Orwell", book->author());
    EXPECT_EQ("978-3730614389", book->isbn());

    delete book;
}

TEST(BookTest, Setters) 
{
    Book book("1984", "George Orwell", "978-3730614389");

    // Using setter methods to modify the Book object
    book.title("Animal Farm");
    book.author("George Orwell");
    book.isbn("978-3730615874");

    EXPECT_EQ("Animal Farm", book.title());
    EXPECT_EQ("George Orwell", book.author());
    EXPECT_EQ("978-3730615874", book.isbn());
}