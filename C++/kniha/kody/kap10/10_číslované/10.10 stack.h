// stack.h -- definice tøídy pro zásobník ADT
#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10}; 	// specifická konstanta tøídy
	Item items[MAX]; 	// místo pro uložení položek
	int top; 					// index položky na vrcholu zásobníku
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push() vrací false, jestliže je zásobník již plný, jinak vrací true
	bool push(const Item & item); 		// pøidá položku do zásobníku
	// pop() vrací false, jestliže je zásobník již prázdný, jinak vrací true
	bool pop(Item & item); 					// odebere horní položku ze zásobníku
};
#endif
