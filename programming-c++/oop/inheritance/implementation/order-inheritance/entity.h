#pragma once

class Entity 
{
	private:
		int _id; 
 
	public:
		Entity(int id);
		
		int id(void) { return _id; }
 };
