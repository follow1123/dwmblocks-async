#include "config.h"

#include "block.h"
#include "util.h"

#define PATH(name)                      "/home/yf/sde/scripts/dwm/blocks/"name
Block blocks[] = {
	{PATH("icon.sh"),              0,              1},
	{PATH("netspeed.sh"),          1,              8},
	{PATH("volume.sh"),            5,              2},
	{PATH("bluetooth.sh"),         15,             3},
	{PATH("battery.sh"),           60,             4},
	{PATH("time.sh"),              1,              5},
	{PATH("week.sh"),              600,           6},
	{PATH("trayer_toggle.sh"),     0,              7},
};

const unsigned short blockCount = LEN(blocks);
