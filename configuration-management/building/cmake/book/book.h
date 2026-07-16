#pragma once

#include <string>

class Book
{
public:
    // Constructor
    Book(const std::string& isbn, const std::string& author, const std::string& title);

    // Accessor methods for isbn
    std::string isbn() const { return _isbn; }
    void set_isbn(const std::string& isbn) { _isbn = isbn; }

    // Accessor methods for author
    std::string author() const { return _author; }
    void set_author(const std::string& author) { _author = author; }

    // Accessor methods for title
    std::string title() const { return _title; }
    void set_title(const std::string& title) { _title = title; }

    // Method to convert the object to JSON
    std::string toJson() const;

private:
    std::string _isbn;
    std::string _author;
    std::string _title;
};
