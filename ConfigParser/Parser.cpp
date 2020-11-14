#include "Parser.h"

namespace parser
{
	Parser::Parser() noexcept
	{
		m_sContent = std::string();
	}

	Parser::Parser(const std::string &content) noexcept
	{
		m_sContent = content;
	}

	std::string Parser::getParsedBytes(std::size_t nBytes) noexcept
	{
		std::string parsed = m_sContent.substr(0, std::min(nBytes, m_sContent.size()));

		if (m_sContent.size() > nBytes)
			m_sContent = m_sContent.substr(std::min(nBytes, m_sContent.size()));
		else
			m_sContent.clear();

		return parsed;
	}

	std::string Parser::getTokenized(const char &cToken, bool bCutOffToken) noexcept
	{
		std::string sTokenized;

		for (const char &c : m_sContent)
		{
			if (c != cToken)
			{
				sTokenized += c;
			}
			else
			{
				eraseBegin(sTokenized.size() + bCutOffToken);
				return sTokenized;
			}
		}

		m_sContent.clear();
		return sTokenized;
	}

	std::string Parser::getTokenized(const std::string &sToken, bool bCutOffToken) noexcept
	{
		std::string sTokenized;
		std::size_t nStreak = 0;

		for (const char &c : m_sContent)
		{
			sTokenized += c;

			if (nStreak < sToken.size())
			{
				if (c == sToken[nStreak])
					nStreak++;
				else
					nStreak = 0;
			}
			else
			{
				sTokenized = sTokenized.substr(0, sTokenized.size() - sToken.size() - 1);
				eraseBegin(sTokenized.size() + bCutOffToken * sToken.size());

				return sTokenized;
			}
		}

		m_sContent.clear();
		return sTokenized;
	}

	std::vector<std::string> Parser::split(const char &cToken) noexcept
	{
		std::vector<std::string> vStrings;
		std::string sResult = std::string(), oldContent = m_sContent;

		while (m_sContent.size() > 0)
		{
			sResult = getTokenized(cToken, true);

			if (sResult.size() > 0)
				vStrings.push_back(sResult);
		}

		if (m_sContent.size() > 0)
			vStrings.push_back(m_sContent);
		m_sContent = oldContent;

		return vStrings;
	}

	std::vector<std::string> Parser::split(const std::string &sToken) noexcept
	{
		std::vector<std::string> vStrings;
		std::string sResult = std::string(), oldContent = m_sContent;

		while (m_sContent.size() > 0)
		{
			sResult = getTokenized(sToken, true);

			if (sResult.size() > 0)
				vStrings.push_back(sResult);
		}

		if (m_sContent.size() > 0)
			vStrings.push_back(m_sContent);
		m_sContent = oldContent;

		return vStrings;
	}

	bool Parser::startsWith(const char &cToken) const noexcept
	{
		return m_sContent.size() > 0 && m_sContent.at(0) == cToken;
	}

	bool Parser::startsWith(const std::string &sToken) const noexcept
	{
		if (m_sContent.size() >= sToken.size())
		{
			for (std::size_t i = 0; i < sToken.size(); i++)
				if (sToken.at(i) != m_sContent.at(i))
					return false;
			
			return true;
		}

		return false;
	}

	bool Parser::endsWith(const char &cToken) const noexcept
	{
		return m_sContent.size() > 0 && m_sContent.at(m_sContent.size() - 1) == cToken;
	}

	bool Parser::endsWith(const std::string &sToken) const noexcept
	{
		if (m_sContent.size() >= sToken.size())
		{
			for (std::size_t i = 0; i < sToken.size(); i++)
				if (sToken.at(i) != m_sContent.at(m_sContent.size() - sToken.size() + i))
					return false;
			
			return true;
		}

		return false;
	}

	void Parser::eraseBegin(const std::size_t &nBytes) noexcept
	{
		m_sContent.erase(0, nBytes);
	}

	void Parser::eraseEnd(const std::size_t &nBytes) noexcept
	{
		std::size_t start = std::max((int32_t)m_sContent.size() - (int32_t)nBytes, 0);
		m_sContent.erase(start, nBytes);
	}

	void Parser::erase(const std::size_t &offset, const std::size_t &nBytes) noexcept
	{
		m_sContent.erase(offset, nBytes);
	}

	std::string Parser::getContent() const noexcept
	{
		return m_sContent;
	}

	void Parser::setContent(const std::string &newContent) noexcept
	{
		m_sContent = newContent;
	}

	void Parser::append(const std::string &newContent) noexcept
	{
		m_sContent.append(newContent);
	}
}