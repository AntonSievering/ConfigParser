#include "ConfigParser.h"

namespace parser
{
	ConfigParser::ConfigParser() noexcept
	{
	}

	ConfigParser::ConfigParser(const std::string &sFilename) noexcept
	{
		addConfig(sFilename);
	}

	void ConfigParser::addConfig(const std::string &sFilename) noexcept
	{
		// load the file
		std::ifstream file = std::ifstream(sFilename);

		if (file.is_open())
		{
			std::string sLine;
			parser::Parser parser = parser::Parser();

			while (std::getline(file, sLine))
			{
				parser.setContent(sLine);
				std::vector<std::string> vEntries = parser.split('=');

				if (vEntries.size() == 2)
					m_mapConfigs.insert({ vEntries.at(0), vEntries.at(1) });
			}

			file.close();
		}
	}

	std::string ConfigParser::queryString(const std::string &key) const noexcept
	{
		return m_mapConfigs.at(key);
	}

	int ConfigParser::queryInt(const std::string &key) const noexcept
	{
		return atoi(m_mapConfigs.at(key).c_str());
	}

	float ConfigParser::queryFloat(const std::string &key) const noexcept
	{
		return atof(m_mapConfigs.at(key).c_str());
	}

	bool ConfigParser::queryBool(const std::string &key) const noexcept
	{
		return m_mapConfigs.at(key) == "true";
	}

	bool ConfigParser::contains(const std::string &key) const noexcept
	{
		return m_mapConfigs.find(key) != m_mapConfigs.end();
	}
}