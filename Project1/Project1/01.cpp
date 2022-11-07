//------------------------------------------------------------------
// 2022년 11월 7일 c++										9주차 2일
// c++ 언어가 제공하는 string클래스와 같은 기능을 갖는 STRING을 만들어 본다.
// 2022.11.07 STRING 파일 분리
//------------------------------------------------------------------

#include <iostream>
#include "save.h"
#include "STRING.h"

// 객체의 이동 - 프로그래머가 직접 이동시킬 일은 없다.
// 라이브러리 함수가 이동을 지원하는 객체인 경우 복사하는 대신 이동을 사용한다.
// ex) sort, 모든 동적자료구조(vector, list, set, map, unordered_set, ...)
// 클래스가 이동을 지원한다면 비약적으로 실행 속도가 빨라진다.

extern bool 관찰;

//--------
int main()
//--------
{
	STRING s[5]{ "123", "1", "12345", "1234", "12" };

	// [문제] s를 글자 수 기준 오름차순으로 정렬하라.

	std::cout << sizeof(s[0]) << std::endl;
	관찰 = true;
	qsort(s, 5, sizeof(STRING), [](const void* p, const void* q) {
		STRING a = *(STRING*)p;
		STRING b = *static_cast<STRING*>(const_cast<void*>(q));

		return a.getNum() - b.getNum(); });
	관찰 = false;

	관찰 = true;
	for (const STRING& s : s)		// s 라는 새로운 공간을 만들고 s를 하나씩 가져온다.		읽기만 하려면 const &를 붙인다.
		std::cout << s << std::endl;		// operator(os, const STRING& s)
	관찰 = false;

	save("01.cpp");
	// save("STRING.h");
	// save("STRING.cpp");
}