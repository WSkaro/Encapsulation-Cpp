#include <iostream>
#include "Integer.h"

Integer::Integer() : Value(0) {};

Integer::Integer(int value) : Value(value) {};

Integer Integer::operator + (const Integer& _other) {
	return this->Value + _other.Value;
}

Integer* Integer::operator += (const Integer& _other) {
	this->Value += _other.Value;
	return this;
}

Integer Integer::operator - (const Integer& _other) {
	return this->Value - _other.Value;
}

Integer* Integer::operator -= (const Integer& _other) {
	this->Value -= _other.Value;
	return this;
}

Integer Integer::operator * (const Integer& _other) {
	return this->Value * _other.Value;
}

Integer* Integer::operator *= (const Integer& _other) {
	this->Value *= _other.Value;
	return this;
}

Integer Integer::operator / (const Integer& _other) {
	return this->Value / _other.Value;
}

Integer* Integer::operator /= (const Integer& _other) {
	this->Value /= _other.Value;
	return this;
}

Integer Integer::operator % (const Integer& _other) {
	return this->Value % _other.Value;
}

Integer* Integer::operator %= (const Integer& _other) {
	this->Value %= _other.Value;
	return this;
}

Integer Integer::operator << (const Integer& _other) {
	return this->Value << _other.Value;
}

int Integer::Pow(const Integer exponent) {
	int tmp = this->Value;
	for (int i = 1; i < exponent.Value; i++) {
		this->Value *= tmp;
	}

	return this->Value;
}
