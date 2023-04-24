#include "config.h"

#include "block.h"
#include "util.h"

#define PATH(name)                      "/home/yf/scripts/dwmblocks/"name
Block blocks[] = {
    {PATH("get_icon.sh"),         	0,              	1},
    {PATH("get_volume.sh"),        	0,              	2},
	{PATH("get_battery.sh"),       	60,              	3},
	{PATH("get_time.sh"),         	1,              	4},
	{PATH("get_week.sh"),         	3600,              	5},
	{PATH("trayer_toggle.sh"),     	0,              	6},
};

const unsigned short blockCount = LEN(blocks);
