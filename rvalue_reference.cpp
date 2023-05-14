//https://learn.microsoft.com/ko-kr/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170
//lvalue can be left and right value of '='
//lvalue is the value not disposed after single expression
//rvalue is the value disposed after single expression like numeric, operation, and function

#include "rvalue_reference.h"
#include <memory>

struct W
{
	int a, b;
   W(int& A, int& B) : a(A), b(B) {}
   int sum() {return a+b;}
};

struct X
{
   X(const int&, int&) {}
};

struct Y
{
   Y(int&, const int&) {}
};

struct Z
{
	int a, b;
   Z(const int& A, const int& B): a(A), b(B) {}
   int sum() {return a+b;}
};

template<typename T, typename A1, typename A2>
T* rvfactory(A1& a1, A2& a2) {
	return new T(a1, a2);
}

template<typename T, typename A1, typename A2>
T* factory(const A1& a1, const A2& a2) {
	return new T(a1, a2);
}

int rvalue_reference() {
	int a = 4, b = 5;
	W* pw = rvfactory<W>(a, b);
	Z* pz = factory<Z>(2, 2);

	printf("pw sum : %d\n", pw->sum());
	printf("pz sum : %d\n", pz->sum());
	return pw->sum();
}

int rvalue_reference2() {
	Z* pz = factory<Z>(2, 2);

	printf("pz sum : %d\n", pz->sum());
	return pz->sum();
}

