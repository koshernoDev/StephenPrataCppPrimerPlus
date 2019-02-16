// 1_Vector.h  
// Class Vector with operation << and coordinate mode.
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace vector
{
	class Vector
	{
	public:
		// RECT - rectangular coordinate mode,
		// POL - polar coordinate mode:
		enum Mode {RECT, POL};

    //................Open methods................

    // Constructors:
		Vector();
		Vector(double firstParemeter, double secondParameter, 
			     Mode form = RECT);
		// Destructor:
		~Vector();
		// Resets parameters:
		void reset(double firstParemeter, double secondParameter,
			         Mode form = RECT);
    // Get values of parameters:
		double xValue() const {return x_;}
		double yValue() const {return y_;}
		double moduleValue() const;
		double angleValue() const;
		// Set coordinate mode:
		void polarMode();
		void rectMode();

    // Overload of operations:
		Vector operator+(const Vector& vector) const;
		Vector operator-(const Vector& vector) const;
		Vector operator-() const;
		Vector operator*(double n) const;

    //................Friends................

    // Overloads * for multiplicate format like double * vector:
		friend Vector operator*(double n, const Vector& vector);
		// Overloads << for ostream:
		friend std::ostream& operator<<(std::ostream& os,
			                              const Vector& vector);
	private:
		// Parameters:
		double x_;
		double y_;
		// Mode:
		Mode mode_;

    // Closed methods for setting parameters:
		double getModule() const;
		double getAngle() const;
	};
}
// End namespace vector
#endif // VECTOR_H_