//------------------------------------------------------------------
// STRING.cpp
// ǥ�� string�� ���� ������ �ϴ� class
// 2022�� 11�� 7�� c++										9���� 2��
//------------------------------------------------------------------

#include <iostream>
#include "STRING.h"

bool ����{ false };		// 2022.11.07 �����޼��� �����

STRING::STRING() : num{ }, p{ nullptr } 	// ����Ʈ ������ (num, p �� �ʱ�ȭ)
{
	if (����)
		std::cout << "STRING() - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
}

STRING::STRING(const char* s) : num{ strlen(s) } 	// ����Ʈ ������ (num, p �� �ʱ�ȭ)
{
	p = new char[num];
	memcpy(p, s, num);
	if (����)
		std::cout << "STRING(const char*) - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
}

STRING::~STRING()	// �Ҹ���
{	
	if (����)
		std::cout << "~STRING() - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
	delete[] p;
}

STRING::STRING(const STRING& other) : num{ other.num }		// ���������
{
	p = new char[num];
	memcpy(p, other.p, num);
	if (����)
		std::cout << "STRING(const STRING&) - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
}

STRING& STRING::operator=(const STRING& other)				// �����Ҵ翬����
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	memcpy(p, other.p, num);
	if (����)
		std::cout << "operator=(const STRING&) - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
}

STRING::STRING(STRING&& other) : num{ other.num }	//�̵�������
{
	p = other.p;
	other.num = 0;
	other.p = nullptr;
	if (����)
		std::cout << "STRING(STRING&&) - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
}

STRING& STRING::operator=(STRING&& other)		// �̵��Ҵ翬����
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;
	if (����)
		std::cout << "operator=(STRING&&) - ���ڼ�: " << num << " , �޸�: " << static_cast<void*>(p) << std::endl;
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

