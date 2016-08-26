#include "library.hpp"
#include <dlfcn.h>

namespace loader {
	struct LibraryData
	{
		void* handle;
	};

	Library::Library(std::string const& lib):
		data(new LibraryData())
	{
		void* hdl = dlopen(lib.c_str(), RTLD_LAZY);
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
			dlclose(data->handle);
			delete data;
			data = nullptr;
		}
	}

	void* Library::addr(std::string const& symbol) const
	{
		void* result = nullptr;
		if (data != nullptr) {
			result = reinterpret_cast<void*>(dlsym(data->handle, symbol.c_str()));
		}
		return result;
	}
}
