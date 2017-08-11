 cd $1
 rm $(ls -p -r -t| grep -v /| head -1)
