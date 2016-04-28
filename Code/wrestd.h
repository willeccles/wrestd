/*----------COPYRIGHT-------------------------
(c) Copyright Will Eccles, 2016
----------------------------------------------*/

/*----------LICENSE---------------------------
This software is licensed under the Apache license. See LICENSE file to learn more.
----------------------------------------------*/

/*----------DESCRIPTION-----------------------
This is a collection of my frequently used classes and methods. They can be selected below.
----------------------------------------------*/

/*----------INSTRUCTIONS----------------------
Comment out the classes you don't want - I recommend this instead of removing the #include for the file.
It's easier to drop the file back in if you want to later on.
----------------------------------------------*/

#define IOMANAGER

/* Common imports, or things required for the classes to work. */
#include <stdio.h>
#include <string>

// include classes, as selected above
#ifdef IOMANAGER
#include "IOManager.h"
#endif

// used to detect things later on
#ifdef _WIN32
#define ISWINDOWS 1
#else
#define ISWINDOWS 0
#endif

// define some colors, these are for use with the IOManager class.
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKTEAL 3
#define DARKRED 4
#define DARKMAGENTA 5
#define DARKYELLOW 6
#define DARKWHITE 7
#define DARKGREY 8
#define BLUE 9
#define GREEN 10
#define TEAL 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

// My namespace, which contains helpful methods and such.
namespace wrestd {
	int substr_count(std::string, std::string, bool);
	std::string substr_replace(std::string&, std::string, std::string, bool, bool);
	
	/* Handles IO functions, such as console printing, colors, waiting, etc. and file existance checks.
	This is a class now, but will in the future be a namespace within the namespace. */
	namespace iofuncs {
		void printc(std::string, int);
		void printlc(std::string, int);
		void clear();
		void wait();
		void wait(std::string);
		void setColor(int);
		int DEFAULT;
		bool fileExists(char[]);
	};
}