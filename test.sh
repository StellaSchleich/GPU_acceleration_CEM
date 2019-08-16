#!/bin/bash
#PBS -l select=1:ncpus=10:ngpus=1
#PBS -P MECH1240
#PBS -q gpu_1
#PBS -l walltime=1:00:00
#PBS -o /mnt/lustre/users/sschleich/example_2
#PBS -e /mnt/lustre/users/sschleich/example_2
#PBS -m abe
#PBS -M 19909586@sun.ac.za


ulimit -s unlimited   #to run in parallel with compiler
source /etc/profile.d/modules.sh

export LM_LICENSE_FILE=/apps/compilers/pgi/linux86-64/2019/license.dat
module add chpc/pgi/19.4
#module load chpc/pgi/19.4

cd /mnt/lustre/users/sschleich/example_2

#echo just prints
echo -----------------------------------------------------------------------
#run in current directory ./
echo -------------------------------
echo Normal cpu
gcc testCPU.c -o testCPU
./testCPU

echo -------------------------------
echo Normal gpu 
pgcc -acc testGPU.c -o testGPU
./testGPU

echo -------------------------------
echo Normal gpu with -fast, which optimizes
pgcc -acc -fast testGPU.c -o testGPU_fast
./testGPU_fast

echo -------------------------------
echo Normal gpu with -fast, and -ta=tesla:managed (managed memory)
pgcc -acc -fast -ta=tesla:managed testGPU.c -o testGPU_fast_tes
./testGPU_fast_tes


echo ------------- CLAUSES ------------------

echo -------------------------------
echo independent clause 
pgcc -acc independentTest.c -o indepTest
./indepTest

echo -------------------------------
echo tile clause 
pgcc -acc tileTest.c -o tileTest
./tileTest

echo -------------------------------
echo collapse clause 
pgcc -acc collapsedTest.c -o colTest
./colTest



echo -----------------------------------------------------------------------
