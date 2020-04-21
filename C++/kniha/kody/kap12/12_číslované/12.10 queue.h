// queue.h -- rozhraní tøídy Queue
#ifndef QUEUE_H_
#define QUEUE_H_
// Tato fronta bude obsahovat položky tøídy Customer
class Customer
{
private:
	long arrive; // èas pøíchodu zákazníka
	int processtime;// doba odbavení zákazníka
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
// definice s platností uvnitø tøídy
	// Node definice vnoøené struktury existující pouze uvnitø tøídy
	struct Node { Item item; struct Node * next;};
	enum {Q_SIZE = 10};
// privátní èlenové tøídy
	Node * front; // ukazatel na zaèátek fronty
	Node * rear; // ukazatel na konec fronty
	int items; // aktuální poèet položek fronty
	const int qsize;// maximální poèet položek fronty
	// preventivní definice nutné pro zamezení veøejného kopírování
	Queue(const Queue & q) : qsize(0) { }
	Queue & operator=(const Queue & q) { return *this;}
public:
	Queue(int qs = Q_SIZE); // vytvoøí frontu s limitem qs
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item); // pøidá položku na konec
	bool dequeue(Item &item); // odebere položku ze zaèátku
};
#endif
