#!/bin/bash/

echo "Functional testing started"
echo ""
echo "Positive tests"
echo ""

cd func_tests/

for pos_test in pos_*_args.txt
do
    ../app.exe $(cat $pos_test) > out_tmp.txt
    cmp out_tmp.txt ${pos_test//args/out} > /dev/null

    if [ $? -eq 0 ]
    then
        echo "Success"
    else
        echo "Failure"
        echo "Correct output:"
        cat ${pos_test//args/out}
        echo "Your output:"
        cat out_tmp.txt
        echo ""
    fi
done

rm out_tmp.txt

echo ""
echo "Negative tests"
echo ""

for neg_test in neg_*_args.txt
do
    ../app.exe $(cat $neg_test)
    programmer_error=$?

    if [ $programmer_error -ne 0 ]
    then
        echo "Success"
    else
        echo "Failure"
    fi
done

echo ""
echo "Functional testing completed"
