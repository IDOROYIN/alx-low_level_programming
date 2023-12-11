#!/bin/bash
wget -P /tmp/ https://raw.github.com/Lacctoff/alx-low_level_programming/master/0x18-dynamic_libraries/myprintf.so
export LD_PRELOAD=/tmp/myprintf.so
