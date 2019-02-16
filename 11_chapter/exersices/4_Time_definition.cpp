// 4_Time_definitions.cpp -- methods Time realization.
#include "4_Time.h"

Time::Time()
{
	hours_ = minutes_ = 0;
}

Time::Time(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

void Time::addMinute(int m)
{
	minutes_ += m;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

void Time::addHour(int h)
{
	hours_ += h;
}

void Time::reset(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

Time operator*(const Time& time, double m)
{
	Time result;
	long totalMinutes = time.hours_ * m * 60 + time.minutes_ * m;
	result.hours_ = totalMinutes / 60;
	result.minutes_ = totalMinutes % 60;
	return result;
}

Time operator*(double m, const Time& time)
{
	return time * m;
}

Time operator+(const Time& firstTime, const Time& secondTime)
{
	Time result;
	long totalMinutes = (firstTime.hours_ * 60 + firstTime.minutes_) +
	                    (secondTime.hours_ * 60 + secondTime.minutes_);
  result.hours_ = totalMinutes / 60;
  result.minutes_ = totalMinutes % 60;
  return result;
}

Time operator-(const Time& firstTime, const Time& secondTime)
{
	Time result;
	long totalMinutes = (firstTime.hours_ * 60 + firstTime.minutes_) -
	                    (secondTime.hours_ * 60 + secondTime.minutes_);
  result.hours_ = totalMinutes / 60;
  result.minutes_ = totalMinutes % 60;
  return result;	                    
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
	os << time.hours_ << " hours, " << time.minutes_ << " minutes";
	return os;
}