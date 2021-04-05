#pragma once

#include <string>

namespace spp {
	std::string replace(std::string& str, std::string from, std::string to) {
		if (str.empty()) { return str; }
		std::string tmp = str;
		size_t start = 0;
		while ((start = tmp.find(from, start)) != std::string::npos) {
			tmp.replace(start, from.length(), to);
			start += to.length();
		}
		return tmp;
	}
	
}