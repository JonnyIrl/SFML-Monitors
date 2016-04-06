#include "BoundedBuffer.h"

using namespace std;

BoundedBuffer::BoundedBuffer()
{
	use = fill = fullEntries = 0;
}

BoundedBuffer::~BoundedBuffer()
{
}

void BoundedBuffer::AddNewItem()
{
	fullEntries++;
	cout << "Added new item count = " << fullEntries << endl;
}

void BoundedBuffer::RemoveItem()
{
	fullEntries--;
	cout << "Removed item count = " << fullEntries << endl;
}

int BoundedBuffer::Consume()
{
	monitor.lock();
	bool full = false;

	//If the entries is empty then we have to wait for something to be made..
	while (fullEntries == 0)
	{
		if (!full)
		{
			cout << "Empty right now.. waiting for something to be produced" << endl;
			full = true;
		}
	}

	int tmp = buffer[use];
	use = (use + 1) % MAX;
	fullEntries--;

	cout << "Just took an element" << endl << "Count =  " << fullEntries << endl;


	//Unlock the mutex
	monitor.unlock();

	sf::sleep(sf::milliseconds(15 + rand() % 600));
	return tmp;
}

void BoundedBuffer::Produce(int element)
{
	//Lock the mutex
	monitor.lock();
	bool full = false;

	//If the entries is full then we have to wait..
	while (fullEntries == MAX)
	{
		if (!full == MAX)
		{
			cout << "Full right now.. waiting" << endl;
			full = true;
		}
	}

	buffer[fill] = element;
	fill = (fill + 1) % MAX;
	fullEntries++;

	cout << "Added new element to be removed.." << "Count =  " << fullEntries << endl;

	//Unlock the mutex
	monitor.unlock();

	sf::sleep(sf::milliseconds(15 + rand() % 600));
}