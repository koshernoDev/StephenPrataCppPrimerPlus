#ifndef MOVE_H_
#define MOVE_H_

class Move
{
public:
	Move(double x = 0.0, double y = 0.0);
	void showMove() const;
	Move add(const Move& move) const;
	void reset(double x = 0.0, double y = 0.0);

private:
	double x_;
	double y_;
};

#endif