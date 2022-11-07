// ---------------------------------------------------------------------------- -
// save.cpp										2022. 11. 7 
// 파일 이름을 전달받아 저장파일에 덧붙인다.
//-----------------------------------------------------------------------------									9주차 2일

#include <string>
#include <fstream>
#include <chrono>

void save(std::string_view file)
{
	std::ifstream in{ file.data() }; // {} -> uniform initialization 
	std::ofstream out{ "01.txt", std::ios::app }; //ios::app -> 

	//저장된 시간을 기록한다.
	out << std::endl;
	out << "-------------------------------------------------------" << std::endl;
	out << "저장한 시간 - ";
	auto now = std::chrono::system_clock::now();
	out << std::chrono::zoned_time("Asia/Seoul", now) << std::endl; //zoned_time -> 지역별 시간 변경시 사용
	out << "-------------------------------------------------------" << std::endl;

	char c;
	in >> std::noskipws; //공백까지 읽도록 지시

	while (in >> c) {
		out << c; // c에 저장한 글자를 파일에 출력
	}
}