#pragma once
#include <map>
#include <string>
#include <memory>
#include <SFML\Graphics.hpp>

namespace Cosmo
{
	namespace Info
	{
		template<typename T, typename G>
		class Holder final
		{
		public:
			const T& operator [](const std::string& index)
			{
				auto found = resources.find(index);

				if (found == resources.end())
					return Add(index, std::unique_ptr<T>(G()(index)));
				else
					return *found->second;
			}

			const T& Add(const std::string& index, std::unique_ptr<T> resource)
			{
				const T& result = *resource;
				resources.insert(std::make_pair(index, std::move(resource)));
				return result;
			}
		private:
			std::map<std::string, std::unique_ptr<T>> resources;
		};
	}
}