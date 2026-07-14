#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity 
{
	private:
		int _id; 
 
	public:
		Entity(int id);
		
		int id(void) { return _id; }
 };

#endif /*_ENTITY_H_ */
