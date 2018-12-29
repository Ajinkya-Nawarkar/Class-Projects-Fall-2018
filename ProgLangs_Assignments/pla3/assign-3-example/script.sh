#/bin/bash

make clean
make
cat program1.bc | ./parse.exe >> studentoutput/program1.out
cat program2.bc | ./parse.exe >> studentoutput/program2.out
cat program3.bc | ./parse.exe >> studentoutput/program3.out
cat program4.bc | ./parse.exe >> studentoutput/program4.out
cat program5.bc | ./parse.exe >> studentoutput/program5.out

echo "###################################### Start Testing ##################################"

echo "#######################################################################################"
diff studentoutput/program1.out program1.out
echo "#######################################################################################"
diff studentoutput/program2.out program2.out
echo "#######################################################################################"
diff studentoutput/program3.out program3.out
echo "#######################################################################################"
diff studentoutput/program4.out program4.out
echo "#######################################################################################"
diff studentoutput/program5.out program5.out
echo "#######################################################################################"

rm studentoutput/program1.out
rm studentoutput/program2.out
rm studentoutput/program3.out
rm studentoutput/program4.out
rm studentoutput/program5.out 
