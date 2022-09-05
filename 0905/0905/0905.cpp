//------------------------------------------------------------------
// 2022년 9월 5일 c++										1주차 2일
// 자료형(data type)
//------------------------------------------------------------------

#include <iostream>
#include <random>
#include "save.h"
using namespace std;

default_random_engine dre;

int main()
{
	int n[10000];		// n은 STACK에 생성된다.
	//new int;	// int는 free store에 생성된다.
	
	uniform_int_distribution<> uid;
	// n의 값을 제멋대로 입력
	for (int&n : n)
		n = uid(dre);
	// n의 값중 가장 큰 값을 찾아 출력하시오
	int max{n[0]};
	for (int num : n) {
		if (max < num)
			max = num;
	}
	cout << "최댓값은: " << max << endl;
	/*for (int n : n)
		cout << n << "\t";
	cout << endl;*/
	save("0905.cpp");
}	