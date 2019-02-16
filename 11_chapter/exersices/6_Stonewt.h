// 5_Stonewt.h -- class Stonewt definition.
#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt
{
public:
	enum Mode {STONE, POUND, FLOAT_POUND};
	
	Stonewt();
	Stonewt(double pds, Mode form = STONE);
	Stonewt(int stn, double pds, Mode form = STONE);
	~Stonewt() {};
	
	void setForm(Mode);
	void reset(int stn = 0, double pds = 0.0, Mode form = STONE);

	friend Stonewt operator+(const Stonewt&, const Stonewt&);
	friend Stonewt operator-(const Stonewt&, const Stonewt&);
	friend Stonewt operator*(const Stonewt&, double n);
	friend Stonewt operator*(double n, const Stonewt&);
	friend bool operator>(const Stonewt&, const Stonewt&);
	friend bool operator>=(const Stonewt&, const Stonewt&);
	friend bool operator<(const Stonewt&, const Stonewt&);
	friend bool operator<=(const Stonewt&, const Stonewt&);
	friend bool operator!=(const Stonewt&, const Stonewt&);
	friend bool operator==(const Stonewt&, const Stonewt&);
	friend std::ostream& operator<<(std::ostream& os, 
		                              const Stonewt& stonewt);

private:
	Mode form_;
	int stones_;
	double pdsLeft_;
	double pounds_;
};

#endif // STONEWT_H_