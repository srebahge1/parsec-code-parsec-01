#include "my_lib.h"
int main(int, char**)
{
	cudaError_t error;
	float msecTotal = 0.0f;

	cudaEvent_t start,stop,start_compute,stop_compute;
	error = cudaEventCreate(&start);
	error = cudaEventCreate(&stop);
	error = cudaEventCreate(&start_compute);
	error = cudaEventCreate(&stop_compute);
	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
		/*int num_devices,num_procs,num_threads;
		omp_set_num_threads(4);
		num_procs=omp_get_num_procs();
		printf("nombre de procs accessibles par OPENMP : %d\n",num_procs);


#pragma omp parallel for
	for (int i=0;i<100;i++){
		printf("it�ration %d traité par le thread numéro : %d\n",i,omp_get_thread_num());
	}

	waitKey(0);
*/
int a=0;
	while(1){ 	char l_clavier=(char)waitKey(25);
	    
		Mat frame,frame_out;
		// Record the start event
		error = cudaEventRecord(start, NULL);
		cap >> frame; // get a new frame from camera
frame_out.create(frame.rows,frame.cols,frame.type());
		imshow("input", frame);
		// Record the start_compute event
if(l_clavier==99 || a==111)//appui sur la touche c
{a=111;

  frame_out=contours(frame);               
}
if(l_clavier==115||a==222)//appui sur la touche s
{
	a=222;
	
	frame_out=seuillage(frame);						
}

if(l_clavier==98||a==121)//appui sur la touche b
{
	a=121;
	frame_out=bnw(frame);
	
}  
if(l_clavier==109||a==100)//appui sur la touche m
{a=100;
frame_out=mirroir(frame);
}
            
// Record the stop_compute event
error = cudaEventRecord(stop_compute, NULL);
//	// Wait for the stop event to complete
error = cudaEventSynchronize(stop_compute);
error = cudaEventElapsedTime(&msecTotal, start_compute, stop_compute);
//printf("Compute Time : %f msec\n",msecTotal);


imshow("output", frame_out);

// Record the stop event
error = cudaEventRecord(stop, NULL);
//	// Wait for the stop event to complete
error = cudaEventSynchronize(stop);

error = cudaEventElapsedTime(&msecTotal, start, stop);
//printf("Total Time : %f msec\n",msecTotal);

if(l_clavier==27)
	      break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;




	
}
