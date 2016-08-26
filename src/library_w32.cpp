#include "library.hpp"
#include <windows.h>

namespace loader {
	struct LibraryData
	{
		HMODULE handle;
	};

	Library::Library(std::string const& lib):
		data(new LibraryData())
	{
		HMODULE hdl = LoadLibrary(lib.c_str());
		if (hdl != NULL) {
			data->handle = hdl;
		} else {
			delete data;
			data = nullptr;
		}
	}

	Library::~Library()
	{
		if (data != nullptr) {
			FreeLibrary(data->handle);
			delete data;
			data = nullptr;
		}
	}

	void* Library::addr(std::string const& symbol) const
	{
		void* result = nullptr;
		if (data != nullptr) {
			result = reinterpret_cast<void*>(GetProcAddress(data->handle, symbol.c_str()));
		}
		return result;
	}
}
