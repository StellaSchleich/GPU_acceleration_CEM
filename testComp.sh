#!/bin/bash
#PBS -P MECH1240
#PBS -q gpu_1
#PBS -l select=1:ncpus=10:ngpus=1
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
echo -----------------------------------------------------------------------

echo Complex CPU
gcc testComplex.c -o testComp
./testComp

echo -------------------------------
echo Complex GPU
pgcc -acc -Minfo=all -ta=nvidia testCompGPU.c -o testCompGPU
./testCompGPU


echo -----------------------------------------------------------------------

