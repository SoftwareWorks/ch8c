#!/bin/bash

(cd x/parser/ && bison --defines=parser.tab.h -o parser.tab.cpp parser.y)

