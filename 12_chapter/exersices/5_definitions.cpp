#include "5_queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize_(qs)
{
	front_ = rear_ = nullptr;
	items_ = 0;
}

Queue::~Queue()
{
	Node_* temp;

	while (front_ != nullptr) {
		temp = front_;
		front_ = front_->next_;
		delete temp;
	}
}

bool Queue::isEmpty() const
{
	return items_ == 0;
}

bool Queue::isFull() const
{
	return items_ == qsize_;
}

int Queue::size() const
{
	return items_;
}

bool Queue::enQueue(const Item& item)
{
	if (isFull()) {
		return false;
	}

	Node_* add = new Node_;

	add->item = item;
	add->next_ = nullptr;
	++items_;

	if (front_ == nullptr) {
		front_ = add;
	}
	else {
		rear_->next_ = add;
	}

	rear_ = add;

	return true;
}

bool Queue::deQueue(Item& item)
{
	if (front_ == nullptr) {
		return false;
	}

	item = front_->item;
	--items_;
	Node_* temp = front_;
	front_ = front_->next_;
	delete temp;

	if (items_ == 0) {
		rear_ = nullptr;
	}

	return true;
}

void Customer::set(long when)
{
	processtime_ = std::rand() % 3 + 1;
	arrive_ = when;
}