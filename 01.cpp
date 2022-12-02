//------------------------------------------------------------------
// 2022�� 12�� 2�� c++									  13���� 1��
// 
// ���ø�(template) - �ҽ��ڵ带 �����Ϸ��� ������ �� �ִ� Ʋ (�ڷ����� ������ �ڵ�)
// ���׸�(Generics) ���α׷����� �ϱ� ���� C++�� �ٽ� Ű����
// 
// - ����: �ڷ����� ������ �����ϴ��� �����Ϸ��� �ʿ��� �ڵ带 �˾Ƽ� ����
// - ����: ������ �ϴ� �ð��� ���� �� �ɸ���.
//		   ������ ������ ���� �߸��ƴ��� �����ϱ� ��ƴ�.
// - ����: ���ø����� �ۼ��� �ڵ�� �ӵ��� ������.
//		-> ���� �׷��� �ʴ�.
//------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

// [����] ���ø� �Լ� �ϳ��� �ۼ��Ͽ�
// main�� �������� ����ǰ� �϶�.

// ���ø� �Լ��� ����� ���Ǹ� �ѹ��� �Ѵ�.
template<class T>
T add(T a, T b)
{
	return a + b;
}

class Dog {
	int num;
public:
	Dog(int n) : num{ n } { }
	Dog operator+(const Dog& rhs) {
		Dog temp(*this);
		temp.num = num + rhs.num;
		return temp;
	}
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		os << dog.num;
		return os;
	}
};

//template< >	// ���ø��� Dog�� ���Ͽ� Ư��ȭ(specialization)
//Dog add(Dog a, Dog b)
//{
//	return a + b;
//}

//--------
int main()
//--------
{
	std::cout << add(1, 2) << std::endl;										// 3
	std::cout << add(std::string{"3 = "}, std::string{"1 + 2"}) << std::endl;	// 3 = 1 + 2
	std::cout << add(Dog(1), Dog(2)) << std::endl;								// 3
	save("01.cpp");
}

