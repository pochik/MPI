#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <mpi.h>
#include <string>

#define MATRIX_SIZE 4
#define PROCESS_AMOUNT (MATRIX_SIZE * MATRIX_SIZE)
#define CHECK_PROC 0
#define OFFSET 13

int numtasks, rank;
short process_number;
short allgathered_data[PROCESS_AMOUNT];
short received_data_one[PROCESS_AMOUNT];
short received_data_two[PROCESS_AMOUNT];
MPI_Status status;
MPI_Status statuses[2];

void check(){
    switch (rank){
        case 0:
            FILE *fp0;
            fp0 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp0, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp0, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 1:
            FILE *fp1;
            fp1 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp1, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp1, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 2:
            FILE *fp2;
            fp2 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp2, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp2, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 3:
            FILE *fp3;
            fp3 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp3, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp3, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 4:
            FILE *fp4;
            fp4 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp4, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp4, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 5:
            FILE *fp5;
            fp5 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp5, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp5, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 6:
            FILE *fp6;
            fp6 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp6, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp6, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 7:
            FILE *fp7;
            fp7 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp7, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp7, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 8:
            FILE *fp8;
            fp8 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp8, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp8, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 9:
            FILE *fp9;
            fp9 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp9, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp9, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 10:
            FILE *fp10;
            fp10 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp10, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp10, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 11:
            FILE *fp11;
            fp11 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp11, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp11, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 12:
            FILE *fp12;
            fp12 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp12, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp12, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 13:
            FILE *fp13;
            fp13 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp13, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp13, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 14:
            FILE *fp14;
            fp14 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp14, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp14, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
        case 15:
            FILE *fp15;
            fp15 = fopen(("file_name_" + std::to_string(rank)).c_str(), "w");
            fprintf(fp15, "%d ", rank);
            for (int i = 0; i < 16; i++){
                fprintf(fp15, "%d ", allgathered_data[i]);
            }
            printf("\n");
            break;
    }
}

void GatherInfoInCenter() {
  switch (rank % 4) {
    case 0:
      //printf("%d\n", allgathered_data[rank]);
      process_number = allgathered_data[rank];
      MPI_Ssend(&process_number, 1, MPI_SHORT, rank + 1, 0, MPI_COMM_WORLD);
      break;
    case 1:
      MPI_Recv(&process_number, 1, MPI_SHORT, rank - 1, 0, MPI_COMM_WORLD, &status);
      allgathered_data[rank - 1] = process_number;
      //printf("%d\n", allgathered_data[rank - 1]);
      break;
    case 3:
      //printf("%d\n", allgathered_data[rank]);
      process_number = allgathered_data[rank];
      MPI_Ssend(&process_number, 1, MPI_SHORT, rank - 1, 0, MPI_COMM_WORLD);
      break;
    case 2:
      MPI_Recv(&process_number, 1, MPI_SHORT, rank + 1, 0, MPI_COMM_WORLD, &status);
      allgathered_data[rank + 1] = process_number;
      //printf("%d\n", allgathered_data[rank + 1]);
      break;
  }

  switch (rank) {
    case 2:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 6, 0, MPI_COMM_WORLD);
      break;
    case 6:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 2, 0, MPI_COMM_WORLD, &status);
      allgathered_data[2] = received_data_one[2];
      allgathered_data[3] = received_data_one[3];
      /*
      for (int i = 0; i < 16; i++){
          printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
    case 14:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD);
      break;
    case 10:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 14, 0, MPI_COMM_WORLD, &status);
      allgathered_data[14] = received_data_one[14];
      allgathered_data[15] = received_data_one[15];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
  }

  switch (rank) {
    case 1:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 5, 0, MPI_COMM_WORLD);
      break;
    case 5:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 1, 0, MPI_COMM_WORLD, &status);
      allgathered_data[0] = received_data_one[0];
      allgathered_data[1] = received_data_one[1];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
    case 13:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD);
      break;
    case 9:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 13, 0, MPI_COMM_WORLD, &status);
      allgathered_data[12] = received_data_one[12];
      allgathered_data[13] = received_data_one[13];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
  }
  switch (rank) {
    case 5:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD);
      break;
    case 9:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 5, 0, MPI_COMM_WORLD, &status);
      allgathered_data[0] = received_data_one[0];
      allgathered_data[1] = received_data_one[1];
      allgathered_data[4] = received_data_one[4];
      allgathered_data[5] = received_data_one[5];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
    case 6:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD);
      break;
    case 10:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 6, 0, MPI_COMM_WORLD, &status);
      allgathered_data[2] = received_data_one[2];
      allgathered_data[3] = received_data_one[3];
      allgathered_data[6] = received_data_one[6];
      allgathered_data[7] = received_data_one[7];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
  }
  switch (rank) {
    case 9:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD);
      break;
    case 10:
      MPI_Recv(&received_data_one, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD, &status);
      allgathered_data[0] = received_data_one[0];
      allgathered_data[1] = received_data_one[1];
      allgathered_data[4] = received_data_one[4];
      allgathered_data[5] = received_data_one[5];
      allgathered_data[8] = received_data_one[8];
      allgathered_data[9] = received_data_one[9];
      allgathered_data[12] = received_data_one[12];
      allgathered_data[13] = received_data_one[13];
      /*
      for (int i = 0; i < 16; ++i) {
        printf("%d ", allgathered_data[i]);
      }
      printf("\n");
      */
      break;
  }
}

void SpreadInfoToEveryProcess() {
  switch (rank) {
    case 10:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 6, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 11, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 14, 0, MPI_COMM_WORLD);
      break;
    case 6:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD, &status);
      break;
    case 9:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD, &status);
      break;
    case 11:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD, &status);
      break;
    case 14:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 10, 0, MPI_COMM_WORLD, &status);
      break;
  }
  switch (rank) {
    case 6:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 2, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 7, 0, MPI_COMM_WORLD);
      break;
    case 9:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 5, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 8, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 13, 0, MPI_COMM_WORLD);
      break;
    case 11:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 15, 0, MPI_COMM_WORLD);
      break;
    case 2:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 6, 0, MPI_COMM_WORLD, &status);
      break;
    case 7:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 6, 0, MPI_COMM_WORLD, &status);
      break;
    case 5:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD, &status);
      break;
    case 8:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD, &status);
      break;
    case 13:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 9, 0, MPI_COMM_WORLD, &status);
      break;
    case 15:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 11, 0, MPI_COMM_WORLD, &status);
      break;
  }
  switch (rank) {
    case 8:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 12, 0, MPI_COMM_WORLD);
      break;
    case 5:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 1, 0, MPI_COMM_WORLD);
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 4, 0, MPI_COMM_WORLD);
      break;
      break;
    case 12:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 8, 0, MPI_COMM_WORLD, &status);
      break;
    case 1:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 5, 0, MPI_COMM_WORLD, &status);
      break;
    case 4:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 5, 0, MPI_COMM_WORLD, &status);
      break;
  }
  switch (rank) {
    case 1:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 0, 0, MPI_COMM_WORLD);
      break;
    case 2:
      MPI_Ssend(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 3, 0, MPI_COMM_WORLD);
      break;
    case 0:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 1, 0, MPI_COMM_WORLD, &status);
      break;
    case 3:
      MPI_Recv(&allgathered_data, PROCESS_AMOUNT, MPI_SHORT, 2, 0, MPI_COMM_WORLD, &status);
      break;
  }
}

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (numtasks != PROCESS_AMOUNT) {
    printf("Process amount is not equal to %d\n", PROCESS_AMOUNT);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  MPI_Barrier(MPI_COMM_WORLD);

  double start_time = MPI_Wtime();

  allgathered_data[rank] = rank + OFFSET;

  GatherInfoInCenter();
  SpreadInfoToEveryProcess();
  //check();
  MPI_Barrier(MPI_COMM_WORLD);

  double end_time = MPI_Wtime();
  double duration = end_time - start_time;
  if (rank == CHECK_PROC) {
    printf("Total execution time of the program: %f\n", duration);
  }
  /*
  for (short i = 0; i < 25; ++i) {
    assert(allgathered_data[i] == i + OFFSET);
  }
  */

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
}
