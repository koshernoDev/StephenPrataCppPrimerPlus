#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
public:
  Customer() {arrive_ = processtime_ = 0;}
  void set(long);
  long when() const {return arrive_;}
  int ptime() const {return processtime_;}
private:
  long arrive_;
  int processtime_;
};

typedef Customer Item;

class Queue
{
public:
  Queue(int qs = Q_SIZE);
  ~Queue();

  bool isEmpty() const;
  bool isFull() const;
  int size() const;
  bool enQueue(const Item&);
  bool deQueue(Item&);

private: 
  struct Node_ {
    Item item;
    struct Node_* next_;
  };
  enum {Q_SIZE = 10};

  Node_* front_;
  Node_* rear_;
  int items_;
  const int qsize_;

  Queue(const Queue& q) : qsize_(0) {}
  Queue& operator=(const Queue& q) {return *this;}
};


#endif // QUEUE_H_