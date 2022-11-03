#pragma once

template <class T>
class Vectors
{
private:
	unsigned size;
	T* vector;
	static double MIN_D;
public:
	Vectors(unsigned size = 0);
	Vectors(const Vectors& v);
	~Vectors();
	unsigned GetSize() const;
	void SetVector();
	void PrintVector() const;
	Vectors operator = (const Vectors& v);
	T& operator [] (const unsigned& i) const;
	Vectors operator + (const Vectors& v);
	Vectors operator - (const Vectors& v);
	T operator * (const Vectors& v);
	Vectors operator * (const int& c); //��������� ���������������
	Vectors operator / (const int& c);
	bool operator == (const Vectors& v) const;
	bool operator != (const Vectors& v) const;
	friend std::ostream& operator << (std::ostream& out, const Vectors& point);
}; 
