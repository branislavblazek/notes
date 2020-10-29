// queuetp.h -- šablona fronty s vnoøenou tøídou
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	// Node je definice vnoøené tøídy
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i):item(i), next(0){ }
	};
	Node * front; // ukazatel na zaèátek fronty
	Node * rear; // ukazatel na konec fronty
	int items; // aktuální poèet položek fronty
	const int qsize; // maximální poèet položek fronty
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const
	{
	return items == 0;
	}
	bool isfull() const
	{
	return items == qsize;
	}
	int queuecount() const
	{
	return items;
	}
	bool enqueue(const Item &item); // pøidá položku na konec fronty
	bool dequeue(Item &item); // odebere položku z fronty
};

// metody šablony QueueTP
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}
template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node * temp;
	while (front != 0) // dokud fronta není prázdná
	{
		temp = front; // uloží adresu první položky
		front = front->next;// nastaví ukazatel na následující položku
		delete temp; // zruší pùvodní první položku
	}
}

// Pøidání položky na konec fronty
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node(item); // vytvoøí uzel
	if (add == NULL)
		return false; // konec v pøípadì nedostatku pamìti
	items++;
	if (front == 0) // jestliže je fronta prázdná,
		front = add; // pøidá položku na zaèátek fronty
	else
		rear->next = add; // jinak na konec fronty
	rear = add; // ukazatel na konec fronty ukazuje na nový uzel
	return true;
}

// Uloží první položku do promìnné item a odstraní ji z fronty
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item; // nastaví item na první položku fronty
	items--;
	Node * temp = front; // uloží adresu první položky
	front = front->next; // nastaví zaèátek na následující položku
	delete temp; // zruší pùvodní první položku
	if (items == 0)
		rear = 0;
	return true;
}

#endif
