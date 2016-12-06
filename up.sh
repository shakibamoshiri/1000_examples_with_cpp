#!/bin/bash

tree -d > list_tree.txt
tree -sh > list_full_tree.txt

rm -f *_examples_are_here_now*
touch $(find . -name *.cpp | perl -lne '!/temp.cpp/ && ++$c;END{printf "%04d_examples_are_here_now",$c}')
perl -le 'print scalar localtime' > *_examples_are_here_now*

size=$(du -sh)
rm -f repository_size_is*
perl -le 'print scalar localtime' > repository_size_is_${size:0:4}

find . -name *.cpp | perl -lne '!/temp.cpp/ && printf "%04d%s%s%s\n", ++$c," ",$_' > full_list_in_order.txt
