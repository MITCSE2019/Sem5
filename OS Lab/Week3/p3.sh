for files in $1*
do
    t=0
    while read input
    do
        if [ "$input" == "$files" ]
        then
            t=1
        fi
    done <"TOC.txt"
    if [ $t -eq 0 ]
    then
        echo $files>>"TOC.txt"
    fi
done


#contributed by Ayush Garg
