#ifndef CD_H_
#define CD_H_

class CD
{
public:
	CD();
	CD(const char *,const char *, int, double);
	CD(const CD & d);
	virtual ~CD();
	virtual void report() const;
	CD & operator=(const CD &);
private:
	char performers_[50];
	char label_[20];
	int selections_;
	double playtime_;
};

class Classic : public CD
{
public:
	Classic();
	Classic(const char *,const char *,const char *, int, double);
	Classic(const char *, const CD &);
	~Classic();
	void report() const;
	Classic & operator=(const Classic &);
private:
  char name_[50];
};

#endif //CD_H_