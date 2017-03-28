#include <stdio.h>
#include <stdlib.h>
#include <omp.h>



int main(int argc, char* argv[]) {	

	int thread_count = strtol(argv[1], NULL, 10);
	
# pragma omp parallel for num_threads(thread_count)	
  
	for(int i= 1; i <= omp_get_num_threads(); i++){ //i is private in each thread
		int my_thread = omp_get_thread_num();
		
		printf("Hello from thread %d\n", my_thread);
	}
	
	return 0;
}
