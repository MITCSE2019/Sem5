#!/bin/bash

#(i)
mkdir ~/dir
cd ~/dir
mkdir sub1 sub2

#(ii)
cd sub1
echo "content1" > axy
echo "content2" > Abc
echo "content2" > xyz

#(iii)
cp xyz ../sub2

#(iv)
echo -e "Users: `who| wc -l`\nFiles: `ls -l | grep "^-" | wc -l`" > ../sub2/number

#(v)
ls -p | grep -v \ | grep -E "^[aA]"

#(vi)
echo "No of files: `ls -l | grep "^-" | wc -l`"

#(vii)
cat <<DELIMITER > hello.c
#include <stdio.h>

void main(){
printf("%s","Hello");
} 
DELIMITER
gcc hello.c -o hello && ./hello