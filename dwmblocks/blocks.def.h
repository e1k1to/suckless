//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Cpu: ",	"checkcpu",			5,			8},
	{"Mem: ", 	"checkram",			5,			9},
	{"Upd: ", 	"checkupd",			5,			9},
	{"Vol: ",	"checkvol",			0,			10},
	{"Bat: ", 	"checkbat",			5,			11},
	{"",		"date '+%d/%m/%Y'",		15,		12},
	{"",		"date '+%R'",			5,		13},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
