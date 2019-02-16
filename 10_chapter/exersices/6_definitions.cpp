#include "6_Move.h"
#include <iostream>

Move::Move(double x, double y)
{
  x_ = x;
  y_ = y;
}

void Move::showMove() const
{
  std::cout << "x = " << x_ << ", "
            << "y = " << y_ << std::endl;
}

Move Move::add(const Move& move) const
{
	Move temp(this->x_, this->y_);

	temp.x_ += move.x_;
	temp.y_ += move.y_;

	return temp;
}

void Move::reset(double x, double y)
{
	x_ = x;
	y_ = y;
}