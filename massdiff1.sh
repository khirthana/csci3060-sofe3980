filename = $1
dir = $(dirname $0)
filename = dir/filename
for f in ls
do
    cf = dir/f
    difference = diff cf filename
    if [difference == 0]
    then
        echo "$f and $filename are the same"
    else
        difference > dir/log.txt
    fi
done
