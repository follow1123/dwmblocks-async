#include "config.h"

#include "block.h"
#include "util.h"

#define PATH(name)                      "dwmblocks/"name
Block blocks[] = {
    {PATH("icon.sh"),              0,              1},
    {PATH("netspeed.sh"),          1,              8},
    {PATH("volume.sh"),            5,              2},
    {PATH("battery.sh"),           60,             4},
    {PATH("datetime.sh"),          1,              5},
    {PATH("trayer.sh"),            0,              7},
};

const unsigned short blockCount = LEN(blocks);
