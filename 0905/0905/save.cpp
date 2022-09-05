#include <string>
#include <fstream>
#include <chrono>

void save(std::string_view file)
{
	std::ifstream in{ file.data() }; // {} -> uniform initialization 
	std::ofstream out{ "02.txt", std::ios::app }; //ios::app -> 

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