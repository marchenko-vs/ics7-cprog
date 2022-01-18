#!bin/bash/

for src_file in *.c
do
    gcc -std=c99 -Werror -Wvla -Wall -pedantic -c $src_file
done

gcc *.o

rm *.o
