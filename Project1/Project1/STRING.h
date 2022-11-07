//------------------------------------------------------------------
// STRING.h
// 표준 string과 같은 동작을 하는 class
// 2022년 11월 7일 c++										9주차 2일
// 2022년 11월 7일 이동지원
//------------------------------------------------------------------

#pragma once

class STRING {
	size_t num;							// 저장한 글자 수
	char* p;							// 글자가 저장된 메모리 번지
public:
	STRING();							// 디폴트 생성자
	STRING(const char*);				
	~STRING();							// 소멸자

	STRING(const STRING&);				// 복사생성자
	STRING& operator=(const STRING&);	// 복사할당연산자			

	// 2022.11.07 이동생성자 코딩
	STRING(STRING&&);					// 이동생성자, && = r-value reference
	STRING& operator=(STRING&&);		// 이동할당연산자

	// 2022.11.07 getter
	int getNum() const;

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};