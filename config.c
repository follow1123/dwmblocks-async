#include "config.h"

#include "block.h"
#include "util.h"

#define PATH(name)                      "/home/yf/sde/scripts/dwmblocks/"name
Block blocks[] = {
	{PATH("icon.sh"),              0,              1},
	{PATH("volume.sh"),            0,              2},
	{PATH("bluetooth.sh"),         15,             3},
	{PATH("battery.sh"),           60,             4},
	{PATH("time.sh"),              1,              5},
	{PATH("week.sh"),              3600,           6},
	{PATH("trayer_toggle.sh"),     0,              7},
};

const unsigned short blockCount = LEN(blocks);
