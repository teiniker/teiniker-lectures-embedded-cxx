#include <string>
#include <sstream>
#include <stdexcept>

#include "data_service.h"

using namespace std;

DataService::DataService(FileService* fservice) 
    : _fservice{fservice} 
{
}

vector<int> DataService::readData() 
{
    try
    {
        string      content = _fservice->readFile();
        vector<int> data;

        for (const string& line : split(content, '\n'))
        {
            if (line.empty())
            {
                continue;   // Skip empty lines
            }

            for (const string& value : split(line, ','))
            {
                data.push_back(stoi(value));
            }
        }

        return data;
    }
    catch (const FileNotFound& e)
    {
        throw DataProcessingException(e.what());
    }
    catch (const logic_error&)  // invalid_argument, out_of_range from stoi()
    {
        throw DataProcessingException("Invalid value in data file!");
    }
}

void DataService::writeData(const vector<int>& data)
{
    // TODO
}

vector<string> DataService::split(const string& s, char delim) 
{
    vector<string> result;
    stringstream   ss(s);
    string         item;

    while (getline(ss, item, delim)) 
    {
        result.push_back(item);
    }

    return result;
}
