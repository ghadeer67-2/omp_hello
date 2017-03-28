#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);

int main(int argc, char* argv[]) {

	int thread_count = strtol(argv[1], NULL, 10);

	//double start = omp_get_wtime();
	
# pragma omp parallel num_threads(thread_count)
	Hello();
	
	return 0;
}

void Hello(void) {
	int my_rank = omp_get_thread_num(); //Thread rank
	int thread_count = omp_get_num_threads(); //number of threads
	
	printf("Hello from thread %d of %d\n", my_rank, thread_count);
	
	

}