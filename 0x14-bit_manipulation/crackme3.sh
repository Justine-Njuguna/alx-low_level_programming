#!/bin/bash

# Get pass script
echo -e
echo -e "Fetching start file ..."
echo -e

curl -o start.xt https://raw.githubusercontent.com/Justine-Njuguna/alx-low_level_programming/master/0x14-bit_manipulation/101.sh

chmod u+x start.xt

./start.xt

