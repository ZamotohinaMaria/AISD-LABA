#pragma once
#include <iostream>
#include <vector>
#include <complex>

template <class T>
class Vectors
{
private:
	unsigned size;
	std::vector<T> values;
	static double MIN_D;

public:
	Vectors(unsigned size = 0);
	Vectors(const Vectors& v);
	~Vectors();

	auto begin() { return values.begin(); } //iterator on the begin
	auto end() { return values.end(); } //iterator on the end

	auto cbegin() const { return values.cbegin(); }//const iterator on the begin
	auto cend() const { return values.cend(); }//const iterator on the end
	
	unsigned GetSize() const;
	void SetVector();
	Vectors operator = (const Vectors& v);
	T operator [] (const unsigned& i) const;
	void set(const unsigned& i, T val);
	Vectors operator + (const Vectors& v);
	Vectors operator - (const Vectors& v);
	double operator * (const Vectors& v);
	Vectors operator * (T c); //обспечить коммутативность
	Vectors operator / (T c);
	bool operator == (const Vectors& v) const;
	bool operator != (const Vectors& v) const;
	/*friend ostream& operator << (ostream& out, const Vectors<T>& point);*/
};
#pragma once
