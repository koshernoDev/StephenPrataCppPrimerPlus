#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
public:
  String ();
  String(const char*);
  String(const String&);
  ~String();

  int lenght() const {return length_;}
  void stringLow();
  void stringUp();
  int has(const char) const;

  String& operator=(const	String&);
  String& operator=(const char*);
  char& operator[](int);
  const char& operator[](int) const;
  String& operator+(const String&);

  friend bool operator<(const String&, const String&);
  friend bool operator>(const String&, const String&);
  friend bool operator==(const String&, const String&);
  friend std::ostream& operator<<(std::ostream&, const String&);
  friend std::istream& operator>>(std::istream&, String&);
  friend String operator+(const String&, const String&);

  static int howMany();

  static const int CIN_LIM = 80;

private:
  char* string_;
  int length_;
  static int numStrings_;
};

#endif // STRING_H_