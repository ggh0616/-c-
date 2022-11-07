//------------------------------------------------------------------
// 2022�� 11�� 7�� c++										9���� 2��
// c++ �� �����ϴ� stringŬ������ ���� ����� ���� STRING�� ����� ����.
// 2022.11.07 STRING ���� �и�
//------------------------------------------------------------------

#include <iostream>
#include "save.h"
#include "STRING.h"

// ��ü�� �̵� - ���α׷��Ӱ� ���� �̵���ų ���� ����.
// ���̺귯�� �Լ��� �̵��� �����ϴ� ��ü�� ��� �����ϴ� ��� �̵��� ����Ѵ�.
// ex) sort, ��� �����ڷᱸ��(vector, list, set, map, unordered_set, ...)
// Ŭ������ �̵��� �����Ѵٸ� ��������� ���� �ӵ��� ��������.

extern bool ����;

//--------
int main()
//--------
{
	STRING s[5]{ "123", "1", "12345", "1234", "12" };

	// [����] s�� ���� �� ���� ������������ �����϶�.

	std::cout << sizeof(s[0]) << std::endl;
	���� = true;
	qsort(s, 5, sizeof(STRING), [](const void* p, const void* q) {
		STRING a = *(STRING*)p;
		STRING b = *static_cast<STRING*>(const_cast<void*>(q));

		return a.getNum() - b.getNum(); });
	���� = false;

	���� = true;
	for (const STRING& s : s)		// s ��� ���ο� ������ ����� s�� �ϳ��� �����´�.		�б⸸ �Ϸ��� const &�� ���δ�.
		std::cout << s << std::endl;		// operator(os, const STRING& s)
	���� = false;

	save("01.cpp");
	// save("STRING.h");
	// save("STRING.cpp");
}