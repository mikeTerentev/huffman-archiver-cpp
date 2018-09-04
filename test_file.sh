#!/bin/sh
set -e

echo "$1"
./huffman -e "$1" /tmp/1 > /dev/null
./huffman -d /tmp/1 /tmp/2 > /dev/null
diff "$1" /tmp/2
