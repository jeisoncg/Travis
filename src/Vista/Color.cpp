#include "Color.hpp"

Color::Color(){
	
	this-> RESET =  "\033[0m";
	this-> BLACK  = "\033[30m"      /* Black */;
	this-> RED    = "\033[31m"      /* Red */;
	this-> GREEN  = "\033[32m"      /* Green */;
	this-> YELLOW = "\033[33m"      /* Yellow */;
	this-> BLUE   = "\033[34m"      /* Blue */;
	this-> MAGENTA ="\033[35m"      /* Magenta */;
	this-> CYAN    ="\033[36m"      /* Cyan */;
	this-> WHITE   ="\033[37m"      /* White */;
	this-> BOLDBLACK =  "\033[1m\033[30m"      /* Bold Black */;
	this-> BOLDRED   =  "\033[1m\033[31m"      /* Bold Red */;
	this-> BOLDGREEN =  "\033[1m\033[32m"      /* Bold Green */;
	this-> BOLDYELLOW = "\033[1m\033[33m"      /* Bold Yellow */;
	this-> BOLDBLUE   = "\033[1m\033[34m"      /* Bold Blue */;
	this-> BOLDMAGENTA= "\033[1m\033[35m"      /* Bold Magenta */;
	this-> BOLDCYAN   = "\033[1m\033[36m"      /* Bold Cyan */;
	this-> BOLDWHITE  = "\033[1m\033[37m"      /* Bold White */;
	
	
	};
Color::~Color(){};
