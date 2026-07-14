#ifndef _BOOK_H_
#define _BOOK_H_

#include <cstdint>
#include <string>

class Book 
{
private:
    std::string _title;
    std::string _author;
    std::string _isbn;

public:
    // Initializing Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // Copy Constructor
    Book(const Book &book) = default;

    // Default destructor
    ~Book() = default;  

    // Getter and Setter Methods
    std::string title() const { return _title; }
    void set_title(const std::string& title) { _title = title; }

    std::string author() const { return _author; }
    void set_author(const std::string& author) { _author = author; }

    std::string isbn() const { return _isbn; }
    void set_isbn(const std::string& isbn) { _isbn = isbn; }
};

#endif // _BOOK_H_