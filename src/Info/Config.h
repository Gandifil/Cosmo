#pragma once
#include <fstream>
#include <string>

//
//Left trim
//
static std::string trim_left(const std::string& str)
{
	const std::string pattern = " \f\n\r\t\v";
	return str.substr(str.find_first_not_of(pattern));
}

//
//Right trim
//
static std::string trim_right(const std::string& str)
{
	const std::string pattern = " \f\n\r\t\v";
	return str.substr(0, str.find_last_not_of(pattern) + 1);
}

//
//Left and Right trim
//
static std::string trim(const std::string& str)
{
	return trim_left(trim_right(str));
}

namespace Cosmo
{
	namespace Info
	{
		class Config
		{
		public:
			// don't use _size!! only for inside algorthms
			enum ConfigParam { WWindow, HWindow, isFullScreen, _size };

			static Config& Instance()
			{
				static Config s;
				return s;
			}

			int getParam(ConfigParam index) const
			{
				return values[index];
			}

			Config(Config const&) = delete;

			Config& operator= (Config const&) = delete;

		private:
			int values[ConfigParam::_size];

			Config()
			{
				std::string optionsName[ConfigParam::_size] = { "WWindow", "HWindow", "isFullScreen" };
				std::string fileName = "options.txt";

				std::ifstream file(fileName);
				if (!file)
					throw ("Can't open file " + fileName);

				std::string buf;
				while (getline(file, buf))
				{
					if (buf.substr(0, 2) == "//" || buf.empty()) continue;
					size_t k = buf.find("=");
					std::string name = trim(buf.substr(0, k));
					std::string value = buf.substr(k + 1, buf.length() - k + 1);

					for (size_t i = 0; i < ConfigParam::_size; i++)
						if (name == optionsName[i])
						{
							values[i] = std::stoi(value);
							break;
						}
				}
				file.close();
			}

			~Config() {  }
		};
	}
}