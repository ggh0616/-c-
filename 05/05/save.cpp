//-----------------------------------------------------------------------------
// save.cpp										2022. 10. 7
// 
// ���� �̸��� ���޹޾� �������Ͽ� �����δ�.
//-----------------------------------------------------------------------------

#include <string>
#include <fstream>
#include <chrono>

void save(std::string_view file)
{
	std::ifstream in{ file.data() };			//  {} - uniform initialization 
	std::ofstream out{ "2022 2�б� C++ ��56��56.txt", std::ios::app };

	// ����� �ð��� ���� ����Ѵ�.

	out << std::endl;
	out << "-------------------------------------------------" << std::endl;
	out << "������ �ð� - ";
	auto now = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", now) << std::endl;
	out << "-------------------------------------------------" << std::endl;

	char c;
	in >> std::noskipws;			// ������� �е��� �����Ѵ�.

	while (in >> c) {
		out << c;		// c�� ������ ���ڸ� ���Ͽ� ���
	}
}