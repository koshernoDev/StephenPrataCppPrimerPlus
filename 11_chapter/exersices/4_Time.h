// 4_Time.h -- class Time with friends
#ifndef TIME_H_
#define TIME_H_
#include <iostream>

class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void addMinute(int m);
	void addHour(int h);
	void reset(int h = 0, int m = 0);

  friend Time operator*(const Time& time, double n);
	friend Time operator*(double n, const Time& time);
  friend Time operator+(const Time& firstTime, const Time& secondTime);
  friend Time operator-(const Time& firstTime, const Time& secondTime);
	friend std::ostream& operator<<(std::ostream& os, const Time& time);

private:
  int hours_;
  int minutes_;	
};

#endif // TIME_H_