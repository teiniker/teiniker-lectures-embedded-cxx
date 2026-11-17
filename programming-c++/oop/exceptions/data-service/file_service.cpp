#include <string>
#include <stdexcept>
#include <fstream>
#include <filesystem>

#include "file_service.h"

using namespace std;

FileService::FileService(const string& filename)
{
    if (filename.empty())
    {
        throw invalid_argument("Invalid filename!");
    }

    _filename = filename;
}

string FileService::readFile() const
{
    if (!filesystem::exists(_filename))
    {
        throw FileNotFound("File " + _filename + " not found!");
    }

    ifstream file(_filename);

    if (!file)
    {
        throw runtime_error("File " + _filename + " cannot be opened!");
    }

    string content;
    string line;

    while (getline(file, line)) 
    { 
        if (!content.empty())
        {
            content.append("\n");  // Keep the line structure
        }

        content.append(line);
    }

    return content;
}

void FileService::writeFile(const string& content)
{
    // TODO
}
