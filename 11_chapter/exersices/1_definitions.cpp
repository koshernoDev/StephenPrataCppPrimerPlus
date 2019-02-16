#include <cmath>
#include "1_Vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace vector
{
	// Calculates degrees in radian, approximately 57.295779...
	const double RAD_TO_DEG = 45.0 / atan(1.0);

  //................Closed methods................

  // Calculates module from x_ and y_:
	void Vector::setModule()
	{
		module_ = sqrt(x_ * x_ + y_ * y_);
	}

  // Calculates angle from atan(x_, y_):
	void Vector::setAngle()
	{
		if (x_ == 0.0 && y_ == 0.0) {
			angle_ = 0.0;
		}
		else {
			angle_ = atan2(y_, x_);
		}
	}

	// Sets x_ by polar coordinates:
	void Vector::setX()
	{
		x_ = module_ * cos(angle_);
	}

  // Sets y_ by polar coordinates:
	void Vector::setY()
	{
		y_ = module_ * sin(angle_);
	}

  //................Open methods................

  // Default constructor:
	Vector::Vector()
	{
		x_ = y_ = module_ = angle_ = 0.0;
		mode_ = RECT;
	}

  // Constructs vector by rectangular coordinates, if form_ == RECT
  // (default), or by polar, if form_ == POL:
	Vector::Vector(double firstParameter, double secondParameter,
		             Mode form)
	{
		mode_ = form;

		if (form == RECT) {
			x_ = firstParameter;
			y_ = secondParameter;
			setModule();
			setAngle();
		}
		else if (form == POL) {
			module_ = firstParameter;
			angle_ = secondParameter;
			setX();
			setY();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- "
			     << "vector set to 0.\n";
			x_ = y_ = module_ = angle_ = 0.0;
			mode_ = RECT;
		}
	}

  // Sets vector by rectangular coordinates, if form_ == RECT
  // (default), or by polar, if form_ == POL:
	void Vector::reset(double firstParameter, double secondParameter,
		             Mode form)
	{
		mode_ = form;

		if (form == RECT) {
			x_ = firstParameter;
			y_ = secondParameter;
			setModule();
			setAngle();
		}
		else if (form == POL) {
			module_ = firstParameter;
			angle_ = secondParameter;
			setX();
			setY();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- "
			     << "vector set to 0.\n";
			x_ = y_ = module_ = angle_ = 0.0;
			mode_ = RECT;
		}
	}


  // Destructor:
	Vector::~Vector()
	{

	}

  // Sets polar mode:
	void Vector::polarMode()
	{
		mode_ = POL;
	}

  // Sets rectangular mode:
	void Vector::rectMode()
	{
		mode_ = RECT;
	}

  //........Overload of operations:
  // Adding two vectors:
	Vector Vector::operator+(const Vector& vector) const
	{
		return Vector(x_ + vector.x_, y_ + vector.y_);
	}

  // Deducting two vectors:
	Vector Vector::operator-(const Vector& vector) const
	{
		return Vector(x_ - vector.x_, y_ - vector.y_);
	}

  // Changing sign of vector to opposite:
	Vector Vector::operator-() const
	{
		return Vector(-x_, -y_);
	}

  // Multiplicating vector on n:
	Vector Vector::operator*(double n) const
	{
		return Vector(x_ * n, y_ * n);
	}
  
  //........Friendly methods:
  // Multiplicating n on vector:
	Vector operator*(double n, const Vector& vector)
	{
		return vector * n;
	}

  // Shows reactangular cooradinates, if mode_ == RECT,
  // or shows polar coordinates, if mode_ == POL:
	std::ostream& operator<<(std::ostream& os,
		                       const Vector& vector)
	{
		if(vector.mode_ == Vector::RECT) {
			os << "(x, y) = (" << vector.x_ << ", " << vector.y_ << ")";
		}
    else if (vector.mode_ == Vector::POL) {
    	os << "(m, a) = (" << vector.module_ << ", "
    	   << vector.angle_ * RAD_TO_DEG << ")";
    }
    else {
    	os << "Vector object mode is invalid.";
    }
    return os;
	}
}
// End namespace vector