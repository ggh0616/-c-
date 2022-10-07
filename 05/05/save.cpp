//-----------------------------------------------------------------------------
// save.cpp										2022. 10. 7
// 
// 파일 이름을 전달받아 저장파일에 덧붙인다.
//-----------------------------------------------------------------------------

#include <string>
#include <fstream>
#include <chrono>

void save(std::string_view file)
{
	std::ifstream in{ file.data() };			//  {} - uniform initialization 
	std::ofstream out{ "2022 2학기 C++ 월56금56.txt", std::ios::app };

	// 저장된 시간을 먼저 기록한다.

	out << std::endl;
	out << "-------------------------------------------------" << std::endl;
	out << "저장한 시간 - ";
	auto now = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", now) << std::endl;
	out << "-------------------------------------------------" << std::endl;

	char c;
	in >> std::noskipws;			// 공백까지 읽도록 지시한다.

	while (in >> c) {
		out << c;		// c에 저장한 글자를 파일에 출력
	}
}