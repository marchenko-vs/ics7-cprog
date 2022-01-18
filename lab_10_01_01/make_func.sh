#!/bin/bash/

echo "Functional testing started"
echo ""
echo "Positive tests"
echo ""

cd func_tests/

let i=0
let success_pos=0

for pos_test in pos_*_args.txt
do
    let i+=1

    ../app.exe $(cat $pos_test) > out_tmp.txt
    diff out_tmp.txt ${pos_test//args/out}

    if [ $? -eq 0 ]
    then
        echo "Test #${i}: success"
        let success_pos+=1
    else
        echo "Test #${i}: failure"
    fi
done

rm out_tmp.txt

echo ""
echo "Negative tests"
echo ""

let j=0
let success_neg=0

for neg_test in neg_*_args.txt
do
    let j+=1

    ../app.exe $(cat $neg_test)
    programmer_error=$?

    if [ $programmer_error -ne 0 ]
    then
        echo "Test #${j}: success"
        let success_neg+=1
    else
        echo "Test #${j}: failure"
    fi
done

echo ""
echo "Positive tests: correct ${success_pos} of ${i}"
echo "Negative tests: correct ${success_neg} of ${j}"
echo ""
echo "Functional testing finished"
