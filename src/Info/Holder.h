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
		struct VoidGuard
		{
			static T* Generate(const std::string& index)
			{
				return G()(index);
			}
		};

		template<typename T>
		struct VoidGuard<T, void>
		{
			static T* Generate(const std::string& index)
			{
				throw new std::logic_error("NO GENERATE TYPE");
			}
		};

		template<typename T, typename G>
		class Holder final
		{
		public:
			const T& operator [](const std::string& index)
			{
				auto found = resources.find(index);

				if (found == resources.end())
					return Add(index, VoidGuard<T, G>().Generate(index));
				else
					return *found->second;
			}

			const T& Add(const std::string& index, T *resource)
			{
				const T& result = *resource;
				resources.insert(std::make_pair(index, std::unique_ptr<T>(resource)));
				return result;
			}
		private:
			std::map<std::string, std::unique_ptr<T>> resources;
		};
	}
}