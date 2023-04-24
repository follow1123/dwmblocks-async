#define PATH(name)                      "/home/yf/scripts/dwmblocks/"name
//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/						/*Update Interval*/	/*Update Signal*/
	{"",		PATH("get_icon.sh"),         	0,              	1},
	{"", 		PATH("get_battery.sh"),       	60,              	2},
	{"",		PATH("get_time.sh"),         	5,              	3},
	{"",		PATH("get_week.sh"),         	3600,              	4},
	// {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	// {"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
