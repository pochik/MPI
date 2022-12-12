all:
	mpic++ allgather.c -o task.out
	mpirun -n 16 ./task.out

