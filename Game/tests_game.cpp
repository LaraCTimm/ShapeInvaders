#include "Game.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "doctest.h"

TEST_CASE("Check files can be loaded, and exception thrown when files aren't found"){
	FileReader file("scores.txt");
	FileReader fakeFile("HeyHello.imaginary");
	CHECK_NOTHROW(file);
	CHECK_THROWS_AS(fakeFile.getHighScore(), FileCannotBeOpened);
	
	}

/*~~~~~~~~~~~~~~~~ TESTS TO ADD ~~~~~~~~~~~~~~~~
 
file reader tests:
returns correct high score
can update high score
 
  * if old score is beaten test file gets updated correctly
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

