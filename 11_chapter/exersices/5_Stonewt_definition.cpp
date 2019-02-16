#include <iostream>
#include "5_Stonewt.h"

static const int PDS_PER_STONE = 14;

Stonewt::Stonewt()
{
	stones_ = pdsLeft_ = pounds_ = 0;
	form_ = STONE;
}

Stonewt::Stonewt(double pds, Mode form)
{
	stones_ = int(pds) / PDS_PER_STONE;
	pdsLeft_ = int(pds) % PDS_PER_STONE + pds - int(pds);
	pounds_ = pds;
	form_ = form;
}

Stonewt::Stonewt(int stn, double pds, Mode form)
{
	stones_ = stn + int(pds) / PDS_PER_STONE;
	pdsLeft_ = int(pds) % PDS_PER_STONE + pds - int(pds);
	pounds_ = stn * PDS_PER_STONE + pds;
	form_ = form;
}

void Stonewt::setForm(Mode form)
{
	form_ = form;
}

void Stonewt::reset(int stn, double pds, Mode form)
{
	stones_ = stn + int(pds) / PDS_PER_STONE;
	pdsLeft_ = int(pds) % PDS_PER_STONE + pds - int(pds);
	pounds_ = stn * PDS_PER_STONE + pds;
	form_ = form;
}

Stonewt operator+(const Stonewt& first, const Stonewt& second)
{
	Stonewt result(first.pounds_ + second.pounds_);
  return result;
}

Stonewt operator-(const Stonewt& first, const Stonewt& second)
{
	Stonewt result(first.pounds_ - second.pounds_);
  return result;
}

Stonewt operator*(const Stonewt& stonewt, double n)
{
  Stonewt result(stonewt.pounds_ * n);
  return result;
}

Stonewt operator*(double n, const Stonewt& stonewt)
{
  return stonewt * n;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& stonewt)
{
	if (stonewt.form_ == Stonewt::STONE) {
		os << stonewt.stones_ << " stones, " << stonewt.pdsLeft_ << " pds.\n";
	}
	else if (stonewt.form_ == Stonewt::POUND) {
		os << int(stonewt.pounds_) << " pounds.\n";
	}
	else if (stonewt.form_ == Stonewt::FLOAT_POUND) {
		os << stonewt.pounds_ << " pounds.\n";
	}
  else {
  	os << "Wrong Stonewt format!\n";
  }	
  return os;
}