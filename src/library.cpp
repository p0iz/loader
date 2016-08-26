#include "library.hpp"

namespace loader {
	bool Library::loaded() const
	{
		return data != nullptr;
	}
}
