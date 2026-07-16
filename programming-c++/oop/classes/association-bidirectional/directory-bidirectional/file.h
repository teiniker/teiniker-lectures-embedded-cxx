#pragma once

#include <string>
#include "directory.h"

class File 
{
	private:
		std::string _name; 
		size_t _size;
		Directory* _directory = NULL;	// ---[0..1]-> Directory
 
	public:
		File(const std::string& name, size_t size);
    
		std::string name(void) const { return _name; }
		void set_name(const std::string& name) { _name = name; }
		
		size_t size(void) const { return _size; }
		void set_size(const size_t size) { _size = size; }
		
		// Association: File ---[1]-> Directory
		Directory* directory(void) const { return _directory; }
		void set_directory(Directory* directory) { _directory = directory; }
 };
