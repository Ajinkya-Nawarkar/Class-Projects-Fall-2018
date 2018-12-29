#/bin/bash

make clean
make

cat program1.bc | ./parse.exe > StudentOutput/program1.out
cat program2.bc | ./parse.exe > StudentOutput/program2.out
cat program3.bc | ./parse.exe > StudentOutput/program3.out
cat program4.bc | ./parse.exe > StudentOutput/program4.out
cat program5.bc | ./parse.exe > StudentOutput/program5.out
cat program6.bc | ./parse.exe > StudentOutput/program6.out
cat program7.bc | ./parse.exe > StudentOutput/program7.out
cat program8.bc | ./parse.exe > StudentOutput/program8.out
cat program9.bc | ./parse.exe > StudentOutput/program9.out
cat program10.bc | ./parse.exe > StudentOutput/program10.out
cat program11.bc | ./parse.exe > StudentOutput/program11.out
cat program12.bc | ./parse.exe > StudentOutput/program12.out

diff StudentOutput/program1.out ProfOutput/program1.out
diff StudentOutput/program2.out ProfOutput/program2.out
diff StudentOutput/program3.out ProfOutput/program3.out
diff StudentOutput/program4.out ProfOutput/program4.out
diff StudentOutput/program5.out ProfOutput/program5.out
diff StudentOutput/program6.out ProfOutput/program6.out
diff StudentOutput/program7.out ProfOutput/program7.out
diff StudentOutput/program8.out ProfOutput/program8.out
diff StudentOutput/program9.out ProfOutput/program9.out
diff StudentOutput/program10.out ProfOutput/program10.out
diff StudentOutput/program11.out ProfOutput/program11.out
diff StudentOutput/program12.out ProfOutput/program12.out


