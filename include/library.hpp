#pragma once
#include <functional>
#include <string>

namespace loader
{
	struct LibraryData;

	class Library
	{
	public:
		explicit Library(std::string const& lib);
		~Library();

		template <typename Signature>
		std::function<Signature> func(std::string const& symbol) const
		{
			return static_cast<Signature*>(addr(symbol));
		}

		bool loaded() const;

	private:
		// OS-specific data container
		LibraryData* data;

		// Retrieves the address from the associated library
		void* addr(std::string const& symbol) const;
	};
}