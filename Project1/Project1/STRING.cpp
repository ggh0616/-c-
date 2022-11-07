//------------------------------------------------------------------
// STRING.cpp
// 표준 string과 같은 동작을 하는 class
// 2022년 11월 7일 c++										9주차 2일
//------------------------------------------------------------------

#include <iostream>
#include "STRING.h"

bool 관찰{ false };		// 2022.11.07 관찰메세지 제어용

STRING::STRING() : num{ }, p{ nullptr } 	// 디폴트 생성자 (num, p 를 초기화)
{
	if (관찰)
		std::cout << "STRING() - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

STRING::STRING(const char* s) : num{ strlen(s) } 	// 디폴트 생성자 (num, p 를 초기화)
{
	p = new char[num];
	memcpy(p, s, num);
	if (관찰)
		std::cout << "STRING(const char*) - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

STRING::~STRING()	// 소멸자
{	
	if (관찰)
		std::cout << "~STRING() - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
	delete[] p;
}

STRING::STRING(const STRING& other) : num{ other.num }		// 복사생성자
{
	p = new char[num];
	memcpy(p, other.p, num);
	if (관찰)
		std::cout << "STRING(const STRING&) - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

STRING& STRING::operator=(const STRING& other)				// 복사할당연산자
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	memcpy(p, other.p, num);
	if (관찰)
		std::cout << "operator=(const STRING&) - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

STRING::STRING(STRING&& other) : num{ other.num }	//이동생성자
{
	p = other.p;
	other.num = 0;
	other.p = nullptr;
	if (관찰)
		std::cout << "STRING(STRING&&) - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

STRING& STRING::operator=(STRING&& other)		// 이동할당연산자
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;
	if (관찰)
		std::cout << "operator=(STRING&&) - 글자수: " << num << " , 메모리: " << static_cast<void*>(p) << std::endl;
}

int STRING::getNum() const
{
	return num;
}

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];

	return os;
}

