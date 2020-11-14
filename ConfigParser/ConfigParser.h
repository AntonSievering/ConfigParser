#pragma once
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "Parser.h"

namespace parser
{
	class ConfigParser
	{
	private:
		std::map<std::string, std::string> m_mapConfigs;

	public:
		ConfigParser()                                        noexcept;
		ConfigParser(const std::string &sFilename)            noexcept;

	public:
		void        addConfig  (const std::string &sFilename) noexcept;
		
		std::string queryString(const std::string &key) const noexcept;
		int         queryInt   (const std::string &key) const noexcept;
		float       queryFloat (const std::string &key) const noexcept;
		bool        queryBool  (const std::string &key) const noexcept;

		bool        contains   (const std::string &key) const noexcept;
	};
}