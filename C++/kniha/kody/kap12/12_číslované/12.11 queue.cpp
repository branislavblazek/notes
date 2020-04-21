// queue.cpp - metody tøídy Customer a Queue
#include "queue.h"
#include <cstdlib> // (nebo stdlib.h) pro rand()
// metody tøídy Queue
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while (front != NULL) // dokud fronta není prázdná
	{
		temp = front; // uloží adresu první položky
		front = front->next; // nastaví ukazatel na další položku
		delete temp; // zruší pùvodní první položku
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

// Add item to queue
bool Queue::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node; // vytvoøí položku
	if (add == NULL)
		return false; // návrat pøi chybì
	add->item = item; // nastaví ukazatele  položky
	add->next = NULL;
	items++;
	if (front == NULL) // pokud je fronta prázdná
		front = add; // umístí položku na zaèátek
	else
		rear->next = add; // jinak na konec
	rear = add; // nastaví ukazatel rear na novou položku
	return true;
}

// Umístí první položku do promìnné item a odebere z fronty
bool Queue::dequeue(Item & item)
{
	if (front == NULL)
		return false;
	item = front->item; // nastaví ukazatel na první položku fronty
	items--;
	Node * temp = front; // uloží adresu první položky
	front = front->next; // nastaví ukazatel front na další položku
	delete temp; // zruší pøedchozí první položku
	if (items == 0)
		rear = NULL;
	return true;
}

// metoda tøídy Customer

// když zákazník pøijde, nastaví se
// èas pøíchodu do promìnné when a do promìnné pøedstavující
// dobu odbavení se nastaví náhodná hodnota v rozsahu 1 - 3.
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
