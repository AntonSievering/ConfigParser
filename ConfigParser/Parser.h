#pragma once
#include <string>
#include <vector>

namespace parser
{
	class Parser
	{
	private:
		std::string m_sContent;

	public:
		Parser()                                                                            noexcept;
		Parser(const std::string &content)                                                  noexcept;

	public:
		std::string getParsedBytes(std::size_t nBytes)                                      noexcept;
		std::string getTokenized(const char              &cToken, bool bCutOffToken = true) noexcept;
		std::string getTokenized(const std::string       &sToken, bool bCutOffToken = true) noexcept;
		std::vector<std::string> split(const char        &cToken)                           noexcept;
		std::vector<std::string> split(const std::string &sToken)                           noexcept;

	public:
		bool startsWith(const char &cToken)                                           const noexcept;
		bool startsWith(const std::string &sToken)                                    const noexcept;
		bool endsWith(const char &cToken)                                             const noexcept;
		bool endsWith(const std::string &sToken)                                      const noexcept;

	public:
		void eraseBegin(const std::size_t &nBytes)                                          noexcept;
		void eraseEnd  (const std::size_t &nBytes)                                          noexcept;
		void erase     (const std::size_t &offset, const std::size_t &nBytes)               noexcept;

	public:
		std::string getContent()                                                      const noexcept;
		void setContent(const std::string &newContent)                                      noexcept;
		void append    (const std::string &newContent)                                      noexcept;
	};
}