#pragma once

#include <string>
#include <vector>

class File; // forward declaration

// Directory  ----[*]->  File
// Directory  <-[1]----  File

// Directory -[1]---[*]- File (bidirectional)
class Directory 
{
	private:
		std::string _name;
		std::vector<File*> _files;  // ---[*]-> File
 
	public:
		Directory(const std::string& name);
		
		std::string name(void) const { return _name; }
		void set_name(const std::string& name) { _name = name; }
		
		// ---[*]-> File
		void addFile(File* file);
		File* file(int index);
		int numberOfFiles(void);
 };
