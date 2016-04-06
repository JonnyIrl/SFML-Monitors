#include "ExtraIncludes.h"
#include <SFML/System.hpp>
#include <iostream>

#define MAX 10

class BoundedBuffer
{
public:
	BoundedBuffer();
	~BoundedBuffer();
	void Produce(int element);
	int Consume();
	void AddNewItem();
	void RemoveItem();

private:
	int buffer[MAX];
	int fill, use;
	int fullEntries;
	sf::Mutex monitor;  // monitor lock
	bool empty;
	bool full;
};
