// ---------------------------------------------------------------------------- -
// save.cpp										2022. 11. 7 
// ���� �̸��� ���޹޾� �������Ͽ� �����δ�.
//-----------------------------------------------------------------------------									9���� 2��

#include <string>
#include <fstream>
#include <chrono>

void save(std::string_view file)
{
	std::ifstream in{ file.data() }; // {} -> uniform initialization 
	std::ofstream out{ "01.txt", std::ios::app }; //ios::app -> 

	//����� �ð��� ����Ѵ�.
	out << std::endl;
	out << "-------------------------------------------------------" << std::endl;
	out << "������ �ð� - ";
	auto now = std::chrono::system_clock::now();
	out << std::chrono::zoned_time("Asia/Seoul", now) << std::endl; //zoned_time -> ������ �ð� ����� ���
	out << "-------------------------------------------------------" << std::endl;

	char c;
	in >> std::noskipws; //������� �е��� ����

	while (in >> c) {
		out << c; // c�� ������ ���ڸ� ���Ͽ� ���
	}
}