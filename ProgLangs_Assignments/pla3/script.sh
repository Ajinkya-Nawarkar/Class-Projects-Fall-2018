#!/bin/bash

make clean
make
cat sample.in | ./lex.exe >> studentoutput/sample.out
cat sample2.in | ./lex.exe >> studentoutput/sample2.out
cat sample3.in | ./lex.exe >> studentoutput/sample3.out
cat sample4.in | ./lex.exe >> studentoutput/sample4.out

echo "###################################### Start Testing ##################################"

echo "#######################################################################################"
diff studentoutput/sample.out profout/sample.out
echo "#######################################################################################"
diff studentoutput/sample2.out profout/sample2.out
echo "#######################################################################################"
diff studentoutput/sample3.out profout/sample3.out
echo "#######################################################################################"
diff studentoutput/sample4.out profout/sample4.out
echo "#######################################################################################"

rm studentoutput/sample.out
rm studentoutput/sample2.out
rm studentoutput/sample3.out
rm studentoutput/sample4.out
 
