#!/bin/bash
# File: Makefile


myprog: helloworld.o
	gcc helloworld.o -o hello

helloworld.o: helloworld.c
	gcc -c helloworld.c


# !!
# this make is expecting one main in all the .c files