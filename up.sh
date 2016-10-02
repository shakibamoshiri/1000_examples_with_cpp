du -sh > size_of_the_whole_examples.txt
tree -d > list_tree.txt
tree -sh > list_full_tree.txt
size=$(ls -R | ack -c '.cpp$')
echo $size > $size\_c++_file_are_here_now
