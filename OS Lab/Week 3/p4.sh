cat f1.txt f2.txt > "sort.txt"
x=`sort ./sort.txt -u -n`
echo $x>sort.txt
 
