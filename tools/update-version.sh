#!/bin/bash
old=0.52;
new=0.6;
dateold=2008;
datenew=2009;
perl -p -i.bak -e 's/'$old'/'$new'/g' src/*.cpp 
perl -p -i.bak -e 's/'$old'/'$new'/g' src/*.h
perl -p -i.bak -e 's/'$old'/'$new'/g' configure.ac


perl -p -i.bak -e 's/'$dateold'/'$datenew'/g' src/*.cpp
perl -p -i.bak -e 's/'$dateold'/'$datenew'/g' src/*.h
mkdir ../temp
mv src/*.bak ../temp

