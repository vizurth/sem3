﻿#include "headers/stdafx.h"
#include "headers/MyVector.h"

Vector::Vector (double c1, double c2) {
	x=c1;   y=c2;
}

Vector::Vector () {
	x = y = 0.;
}

Vector::Vector(const Vector& other) {
	*this = other; // используется переопределенное =
}

void Vector::Out() const {
	cout << "\nVector:  x = " << x << ",  y = " << y;
}

//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& other){	// Присвоение
	if (this == &other){
		return *this;
	}

	x = other.x;
	y = other.y;
	return *this;
}

Vector Vector::operator+ (const Vector& other){
	Vector result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;

	return result;
}

Vector Vector::operator* (double scalar) const {
	Vector result(x * scalar, y * scalar);
	return result;
}

Vector operator*(double scalar, const Vector& vec){
	Vector result(vec.GetX() * scalar, vec.GetY() * scalar);
	return result;
}

double operator*(const Vector& a, const Vector& b){
	return a.x * b.x + a.y * b.y;
}

double Vector::operator!() const {
	return sqrt(x * x + y * y);
}

bool Vector::operator>(const Vector& other) const{
	return (!(*this) > (!other)); // сравниваем по длине
}

bool Vector::operator<(const Vector& other) const{
	return (!(*this) < (!other)); // сравниваем по длине
}

bool Vector::operator==(const Vector& other) const{
	return (fabs(x - other.x) < __DBL_EPSILON__) && (fabs(y - other.y) < __DBL_EPSILON__); // используем машинный эпсилонт
}

void Vector::Move(Vector& v){
	x += v.x;
	y += v.y;
}

double Vector::Area() const{
	return 0.0;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
  os << "(" << v.GetX() << ", " << v.GetY() << ")";
  return os;
}