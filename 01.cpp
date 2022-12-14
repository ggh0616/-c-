//------------------------------------------------------------------
// 2022년 12월 2일 c++									  13주차 1일
// 
// 템플릿(template) - 소스코드를 컴파일러가 생성할 수 있는 틀 (자료형과 무관한 코딩)
// 제네릭(Generics) 프로그래밍을 하기 위한 C++의 핵심 키워드
// 
// - 장점: 자료형의 종류가 무한하더라도 컴파일러가 필요한 코드를 알아서 생성
// - 단점: 컴파일 하는 시간이 조금 더 걸린다.
//		   오류가 났을때 뭐가 잘못됐는지 이해하기 어렵다.
// - 오해: 템플릿으로 작성한 코드는 속도가 느리다.
//		-> 절대 그렇지 않다.
//------------------------------------------------------------------

#include <iostream>
#include <string>
#include "save.h"

// [문제] 템플릿 함수 하나만 작성하여
// main이 수정없이 실행되게 하라.

// 템플릿 함수는 선언과 정의를 한번에 한다.
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

//template< >	// 템플릿을 Dog에 대하여 특수화(specialization)
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

