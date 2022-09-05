//------------------------------------------------------------------
// 2022�� 9�� 5�� c++										1���� 2��
// �ڷ���(data type)
//------------------------------------------------------------------

#include <iostream>
#include <random>
#include "save.h"
using namespace std;

default_random_engine dre;

int main()
{
	int n[10000];		// n�� STACK�� �����ȴ�.
	//new int;	// int�� free store�� �����ȴ�.
	
	uniform_int_distribution<> uid;
	// n�� ���� ���ڴ�� �Է�
	for (int&n : n)
		n = uid(dre);
	// n�� ���� ���� ū ���� ã�� ����Ͻÿ�
	int max{n[0]};
	for (int num : n) {
		if (max < num)
			max = num;
	}
	cout << "�ִ���: " << max << endl;
	/*for (int n : n)
		cout << n << "\t";
	cout << endl;*/
	save("0905.cpp");
}	