#!/bin/bash

# Get self
echo -e
echo -e "Fetching script.c file ..."
echo -e

curl https://raw.githubusercontent.com/Justine-Njuguna/alx-low_level_programming/master/0x14-bit_manipulation/password_gen.c -o passxt.c

sed -i 's/"crack.h"/<stdio.h>/g' password_gen.c
sed -i '2i #include <stdlib.h>' password_gen.c

# Compile password file
gcc password_gen.c -o r.xt

# Generate password doc
./r.xt

echo -e
echo -e "Cleanup ..."

rm *.xt password_gen.c

# clear
echo -e "Created 101-password successfully"
ls 101-pas*

echo -e
echo -e "Run ./crackme3 \`cat 101-password\` to verify"

echo -e

