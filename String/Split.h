#pragma once

#include <string>
#include <vector>
namespace spp{
	std::vector<std::string> split(std::string& string,std::string s_operator) {
		std::vector<std::string> result;
		int start(0);
		std::string tmp;
		std::string stmp(string);
		while (true)
		{
			tmp = "";
			for (int i = 0; i < static_cast<int>(stmp.find_first_of(s_operator)); i++) {
				tmp += stmp[i];
			}
			result.insert(result.end(), tmp);		

			stmp = stmp.replace(0, stmp.find_first_of(s_operator)+1, "");

			if (stmp.find_first_of(s_operator) == 0 || stmp.find(s_operator) == std::string::npos) { break; }
		}
		result.insert(result.end(), stmp);
		return result;
	}
}


