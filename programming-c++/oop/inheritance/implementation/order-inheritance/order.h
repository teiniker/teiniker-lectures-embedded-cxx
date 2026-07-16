#pragma once

#include <string>
#include <vector>

#include "entity.h"
#include "order_line.h"

class Order : public Entity  
{
	private:
		std::string _name;
		std::vector<OrderLine*> _lines;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const std::string& name);	
		   
		std::string name(void) { return _name; }

		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };
