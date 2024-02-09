#!/bin/bash
#SBATCH -t00:05:00 --mem=2G

module load intel/2021.3.0
module load impi/2021.3.0


mpiicc -O0 -o pimc pimc.c
srun ./pimc       
