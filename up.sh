du -sh > size_of_the_whole_examples.txt
tree -d > list_tree.txt
tree -sh > list_full_tree.txt
size=$(ls -R | ack -c '.cpp$')
mv -f *_c++_examples_are_here_now $size\_c++_examples_are_here_now
perl -le 'print scalar localtime' > $size\_c++_examples_are_here_now
