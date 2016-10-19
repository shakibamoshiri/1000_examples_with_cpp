du -sh > size_of_the_whole_examples.txt
tree -d > list_tree.txt
tree -sh > list_full_tree.txt

touch $(find . -name *.cpp | perl -lne '!/temp.cpp/ && ++$c;END{printf "%04d_examples_are_here_now",$c}')
perl -le 'print scalar localtime' > ????_examples_are_here_now
find . -name *.cpp | perl -lne '!/temp.cpp/ && printf "%04d%s%s%s\n", ++$c," ",$_' > full_list_in_order.txt
