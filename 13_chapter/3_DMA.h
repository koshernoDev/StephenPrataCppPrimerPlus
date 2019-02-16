#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class DMA
{
public:
	DMA(const char *, int);
	DMA(const DMA &);
	virtual ~DMA() = 0;
	DMA & operator=(const DMA &);
	friend std::ostream & operator<<(std::ostream &, const DMA &);
private:
	char * label_;
	int    rating_;
};

class baseDMA : public DMA
{
};

class lacksDMA : public DMA
{
public:
	lacksDMA(const char *, const char *, int);
	lacksDMA(const char *, const DMA &);
	friend std::ostream & operator<<(std::ostream &, const lacksDMA &);
private:
	enum { COL_LEN_ = 40};
	char color_[COL_LEN_];
};

class hasDMA : public DMA
{
public:
	hasDMA(const char *, const char *, int);
	hasDMA(const char *, const DMA &);
	hasDMA(const hasDMA &);
	~hasDMA();
	hasDMA operator=(const hasDMA &);
	friend std::ostream & operator<<(std::ostream &, const hasDMA &);
private:
	char * style_;
};

#endif // DMA_H_