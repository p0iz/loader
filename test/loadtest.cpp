#include "catch.hpp"
#include "library.hpp"
#include <functional>

namespace {
#ifdef _WIN32
	const std::string testlibname("testlib.dll");
#else
	const std::string testlibname("libtestlib.so");
#endif
}
SCENARIO("Loading a shared library")
{
	GIVEN("library is loaded successfully")
	{
		loader::Library lib(testlibname);
		REQUIRE(lib.loaded() == true);

		WHEN("symbol is loaded successfully")
		{
			auto testfunc = lib.func<int(int)>("test");

			THEN("function pointed by symbol is called successfully")
			{
				REQUIRE(testfunc(3) == 3);
			}
		}
	}
}

SCENARIO("Loading non-existent library")
{
	GIVEN("a non-existing library name")
	{
		WHEN("an attempt is made to load the library")
		{
			loader::Library lib("not there");
			THEN("library is not loaded")
			{
				REQUIRE(lib.loaded() == false);
			}
			THEN("symbol loads return null")
			{
				REQUIRE(lib.func<int(int)>("test") == nullptr);
			}
		}
	}
}
