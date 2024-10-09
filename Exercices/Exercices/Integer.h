#ifndef INTEGER_H__
#define INTEGER_H__

class Integer {
private:
	int Value;
public:
	Integer();
	Integer(int value);

	Integer operator + (const Integer& _other);
	Integer* operator += (const Integer& _other);
	Integer operator - (const Integer& _other);
	Integer* operator -= (const Integer& _other);
	Integer operator * (const Integer& _other);
	Integer* operator *= (const Integer& _other);
	Integer operator / (const Integer& _other);
	Integer* operator /= (const Integer& _other);
	Integer operator % (const Integer& _other);
	Integer* operator %= (const Integer& _other);
	Integer operator << (const Integer& _other);

	int Pow(Integer exponent);
};

#endif