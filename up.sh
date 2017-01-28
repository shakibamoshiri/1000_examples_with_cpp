#!/bin/bash

utctime

example=$(find . -name *.cpp | perl -lne '!/temp.cpp/ && ++$c;END{printf "%04d_examples_are_here_now",$c}')
echo $example

size=$(du -sh)
echo repository_size_is_${size:0:4}

echo ........................................
