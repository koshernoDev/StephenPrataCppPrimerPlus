#include <cstring>
#include <cctype>
#include "2_String.h"

int String::numStrings_ = 0;

String::String()
{
	length_ = 1;
	string_ = new char[length_];
	string_[0] = '\0';
	++numStrings_;
}

String::String(const char* string)
{
	length_ = strlen(string);
	string_ = new char[length_ + 1];
	strcpy(string_, string);
	++numStrings_;
}

String::String(const String& string)
{
	length_ = string.length_;
	string_ = new char[length_ + 1];
	strcpy(string_, string.string_);
	++numStrings_;
}

String::~String()
{
	delete [] string_;
	--numStrings_;
}

void String::stringLow()
{
  for (int i = 0; i < length_; ++i) {
  	if (isupper(string_[i])) {
  		string_[i] = tolower(string_[i]);
  	}
  }
}

void String::stringUp()
{
	for (int i = 0; i < length_; ++i) {
		if (islower(string_[i])) {
			string_[i] = toupper(string_[i]);
		}
	}
}

int String::has(const char ch) const
{
  int counter = 0;

  for (int i = 0; i < length_; ++i) {
  	if (string_[i] == ch) {
  		++counter;
  	}
  }

  return counter;
}

String& String::operator=(const String& string)
{
	if (this == &string) {
		return *this;
	}

	delete [] string_;

	length_ = string.length_;
	string_ = new char[length_ + 1];
	strcpy(string_, string.string_);

	return *this;
}

String& String::operator=(const char* string)
{
	delete [] string_;

	length_ = strlen(string);
	string_ = new char[length_ + 1];
	strcpy(string_, string);

	return *this;
}

char& String::operator[](int i)
{
	return string_[i];
}

const char& String::operator[](int i) const
{
	return string_[i];
}

String& String::operator+(const String& string)
{
  String temp(*this);

  delete [] string_;

  string_ = new char[temp.length_ + string.length_ + 1];

  strcpy(string_, temp.string_);
  strcat(string_, string.string_);

  length_ += string.length_;

  return *this;.
}

bool operator<(const String& first, const String& second)
{
	return (strcmp(first.string_, second.string_) < 0);
}

bool operator>(const String& first, const String& second)
{
  return second < first;
}

bool operator==(const String& first, const String& second)
{
	return (strcmp(first.string_, second.string_) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	os << string.string_;
	return os;
}

std::istream& operator>>(std::istream& is, String& string)
{
	char temp[String::CIN_LIM];
	is.get(temp, String::CIN_LIM);

	if (is) {
		string = temp;
	}

	while (is && is.get() != '\n') {
		continue;
	}

	return is;
}

String operator+(const String& first, const String& second)
{
  String temp(first);

  temp = temp + second;

  return temp;
}

int String::howMany()
{
	return numStrings_;
}