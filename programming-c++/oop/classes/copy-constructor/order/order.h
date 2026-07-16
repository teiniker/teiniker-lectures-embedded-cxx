#pragma once

#include <string>
#include <vector>

#include "line.h"

class Order 
{
	private:
		int _id; 
		std::string _name;
		std::vector<OrderLine*> _lines;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const std::string& name);	
		Order(const Order& old);	// Copy Constructor   
		   
		int id(void) const { return _id; }
		std::string name(void) const { return _name; }
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };
