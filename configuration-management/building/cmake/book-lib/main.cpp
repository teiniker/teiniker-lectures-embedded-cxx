#include "book.h"
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         

    assert("978-0131103627" == book.isbn());
    assert("Brian W. Kernighan and Dennis Ritchie" == book.author());
    assert("The C Programming Language" == book.title()); 
    assert("{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}" == book.toJson());

    return EXIT_SUCCESS;
}