#include "my_lib.h"
	Mat contours (Mat frame) 
{
	Mat out,in_gray;
	cvtColor(frame,in_gray,CV_BGR2GRAY);
	out.create(frame.rows,frame.cols,CV_8UC1);
		for (int i=1;i<frame.rows;i++)                 //detection de contours
		{
			for (int j=1;j<frame.cols;j++)
			{
				short temp;
				temp = (-1)*in_gray.at<uchar>(i,j-1)+(-1)*in_gray.at<uchar>(i-1,j)+(-1)*in_gray.at<uchar>(i,j+1)+(-1)*in_gray.at<uchar>(i+1,j)+4*in_gray.at<uchar>(i,j);
out.at<uchar>(i,j)=(uchar)abs(temp);
		if(out.at<uchar>(i,j)>23) out.at<uchar>(i,j)=255;
		else { out.at<uchar>(i,j)=0;
		     }
			}
		}
return(out);
}
Mat bnw (Mat frame){
float nr;
for (int i=0;i<frame.rows;i++){
			for (int j=0;j<frame.cols;j++){
				uchar r,v,b;
				b=frame.at<Vec3b>(i,j)[0];
				v=frame.at<Vec3b>(i,j)[0];
				r=frame.at<Vec3b>(i,j)[0];
				nr=r/sqrt((r*r)+(b*b)+(v*v));
		if(nr>0.8)
			{
				frame.at<Vec3b>(i,j)[0]=0;
				frame.at<Vec3b>(i,j)[1]=0;             //transforme l'image en noir et blanc
				frame.at<Vec3b>(i,j)[2]=0;
			}
		else{
			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
		}
	
			}
		}
return (frame);
}
Mat seuillage (Mat frame)
{
float nr;
for (int i=0;i<frame.rows;i++){
			for (int j=0;j<frame.cols;j++){
				uchar r,v,b;
				b=frame.at<Vec3b>(i,j)[0];
				v=frame.at<Vec3b>(i,j)[1];
				r=frame.at<Vec3b>(i,j)[2];
				nr=r/sqrt((r*r)+(b*b)+(v*v)); //seuillage rouge
		if(nr>0.8)
			{
				frame.at<Vec3b>(i,j)[0]=0;    
				frame.at<Vec3b>(i,j)[1]=r;    //transforme le rouge en jaune
				frame.at<Vec3b>(i,j)[2]=r;
			}
		else{
			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
		}
	
			}
		}
return (frame);
}
Mat mirroir(Mat frame)
{Mat frame_out;

float n=1;
	
		for (int i=1;i<frame.rows;i++)
		{
			for (int j=1;j<frame.cols;j++)
			{uchar r,v,b;
				
				b=frame.at<Vec3b>(i,j)[0];
				v=frame.at<Vec3b>(i,j)[1];
				r=frame.at<Vec3b>(i,j)[2];

if(n>0.0)
{frame.at<Vec3b>(i,640-j)[0]=b;
			frame.at<Vec3b>(i,640-j)[1]=v;
			frame.at<Vec3b>(i,640-j)[2]=r;
}
}
			}
		
return(frame);

}
