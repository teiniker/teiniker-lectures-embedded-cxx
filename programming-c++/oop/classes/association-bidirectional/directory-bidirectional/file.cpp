#include <string>
#include "file.h"

using namespace std;

File::File(const string& name, size_t size)
    : _name{name}, _size{size}
{
    _directory = NULL;
}

// Association: File ---[1]-> Directory
