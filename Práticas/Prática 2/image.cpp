/* Biblioteca destinada a leitura e escrita de imagens utilizando a biblioteca OpencCV

 *
 *
 * Autor: Ricardo Medeiros
 * discente de Engenharia da Computão na Universidade Federal do Vale do São Francisco - UNIVASF
 *
 * Curso: "Visão Computacional: tópicos selecionados e aplicações com a biblioteca OpenCV"
 *
 * */
#include "image.hpp"

void image::read(std::string& name, cv::Mat& imageOut)
{
	imageOut = cv::imread(name,CV_32S);
}
void image::display(std::string& name,cv::Mat& image, int delay, bool destroy)
{
	cv::namedWindow(name,cv::WINDOW_AUTOSIZE);
	cv::imshow(name,image);
	cv::waitKey(delay);
	if(destroy)
		cv::destroyWindow(name);
}
bool image::store(std::string& name,cv::Mat& image)
{
	return cv::imwrite(name,image);
}
void image::extractChannel(cv::Mat& imageIn, cv::Mat& imageOut,int ChannelCode)
{
	switch(ChannelCode)
	{
		case ChannelRed:
			extractChannelRed(imageIn,imageOut);
			return;
		case ChannelGreen:
			extractChannelGreen(imageIn,imageOut);
			return;
		case ChannelBlue:
			extractChannelBlue(imageIn,imageOut);
			return;
		case ChannelCyan:
			extractChannelCian(imageIn,imageOut);
			return;
		case ChannelMagenta:
			extractChannelMagenta(imageIn,imageOut);
			return;
		case ChannelYellow:
			extractChannelYellow(imageIn,imageOut);
			return;
		case ChannelY:
			extractChannelY(imageIn,imageOut);
			return;
		case ChannelU:
			extractChannelU(imageIn,imageOut);
			return;
		case ChannelV:
			extractChannelV(imageIn,imageOut);
			return;
		case ChannelHue:
			extractChannelHue(imageIn,imageOut);
			return;
		case ChannelLuminance:
			extractChannelLuminance(imageIn,imageOut);
			return;
		case ChannelSaturation:
			extractChannelSaturation(imageIn,imageOut);
			return;
		default :
			std::cout<<"Chanel Code invalido:"<<ChannelCode<<std::endl;
			return;

	}

}
void image::extractChannelRed(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
	imageIn.convertTo(imageIn,CV_8UC3);

	for(int rows=0;rows<imageIn.rows;rows++)
		for(int cols=0;cols<imageIn.cols;cols++)
			imageTarget->at<unsigned char>(rows,cols) = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];//A opencv armazena as imagens em BGR

	imageOut = *imageTarget;


}
void image::extractChannelGreen(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
		imageIn.convertTo(imageIn,CV_8UC3);

		for(int rows=0;rows<imageIn.rows;rows++)
			for(int cols=0;cols<imageIn.cols;cols++)
				imageTarget->at<unsigned char>(rows,cols) = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];//A opencv armazena as imagens em BGR

		imageOut = *imageTarget;

}
void image::extractChannelBlue(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
		imageIn.convertTo(imageIn,CV_8UC3);

		for(int rows=0;rows<imageIn.rows;rows++)
			for(int cols=0;cols<imageIn.cols;cols++)
				imageTarget->at<unsigned char>(rows,cols) = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];//A opencv armazena as imagens em BGR

		imageOut = *imageTarget;
}
void image::extractChannelCian(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
	imageIn.convertTo(imageIn,CV_8UC3);

	for(int rows=0;rows<imageIn.rows;rows++)
				for(int cols=0;cols<imageIn.cols;cols++)
					imageTarget->at<unsigned char>(rows,cols) = (255 - (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2]);//A opencv armazena as imagens em BGR -> C = 255-R
	imageOut = *imageTarget;
}
void image::extractChannelMagenta(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
		imageIn.convertTo(imageIn,CV_8UC3);

		for(int rows=0;rows<imageIn.rows;rows++)
					for(int cols=0;cols<imageIn.cols;cols++)
						imageTarget->at<unsigned char>(rows,cols) = (255 - (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1]);//A opencv armazena as imagens em BGR -> M = 255-G
		imageOut = *imageTarget;
}
void image::extractChannelYellow(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
		imageIn.convertTo(imageIn,CV_8UC3);

		for(int rows=0;rows<imageIn.rows;rows++)
					for(int cols=0;cols<imageIn.cols;cols++)
						imageTarget->at<unsigned char>(rows,cols) = (255 - (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0]);//A opencv armazena as imagens em BGR -> Y = 255-B
		imageOut = *imageTarget;
}
void image::extractChannelY(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
			imageIn.convertTo(imageIn,CV_8UC3);

			for(int rows=0;rows<imageIn.rows;rows++)
						for(int cols=0;cols<imageIn.cols;cols++)
						{
							unsigned char B = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];
							unsigned char G = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];
							unsigned char R = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];
							unsigned char Y = (unsigned char)(0.229*R+0.587*G+0.114*B);

							imageTarget->at<unsigned char>(rows,cols) = Y;

						}
						imageOut = *imageTarget;
}
void image::extractChannelU(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
				imageIn.convertTo(imageIn,CV_8UC3);

				for(int rows=0;rows<imageIn.rows;rows++)
							for(int cols=0;cols<imageIn.cols;cols++)
							{
								unsigned char B = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];
								unsigned char G = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];
								unsigned char R = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];
								unsigned char Y = (unsigned char)(0.229*R+0.587*G+0.114*B);

								imageTarget->at<unsigned char>(rows,cols) = (unsigned char)(0.492*(B-Y));

							}
							imageOut = *imageTarget;
}
void image::extractChannelV(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
				imageIn.convertTo(imageIn,CV_8UC3);

				for(int rows=0;rows<imageIn.rows;rows++)
							for(int cols=0;cols<imageIn.cols;cols++)
							{
								unsigned char B = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];
								unsigned char G = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];
								unsigned char R = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];
								unsigned char Y = (unsigned char)(0.229*R+0.587*G+0.114*B);

								imageTarget->at<unsigned char>(rows,cols) = (unsigned char)(0.877*(R-Y));

							}
							imageOut = *imageTarget;
}
void image::extractChannelHue(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
					imageIn.convertTo(imageIn,CV_8UC3);

					for(int rows=0;rows<imageIn.rows;rows++)
								for(int cols=0;cols<imageIn.cols;cols++)
								{
									double B = imageIn.at<cv::Vec3b>(rows,cols)[0]/255.0;
									double G = imageIn.at<cv::Vec3b>(rows,cols)[1]/255.0;
									double R = imageIn.at<cv::Vec3b>(rows,cols)[2]/255.0;
									double MAX = max(R,B,G);
									double MIN = min(R,G,B);
									double L = (MAX+MIN)/2;
									double S = L>0.5?(MAX-MIN)/(MAX+MIN):(MAX-MIN)/2 -(MAX+MIN);
									double H;

									if(MAX == R)
										H = 60*(G-B)/S;
									else
									if(MAX == G)
										H=120+60*(B-R)/S;
									else
									if(MAX == B)
										H=240+60*(R-G)/S;

									if(H<0)
										H+=360;
									else
									if(H>=360)
										H-=360;

									H*=(255.0/360);//Mudando a escala para 0 255 (originalmente de 0 360)


									imageTarget->at<unsigned char>(rows,cols) = (unsigned char)H;

								}
								imageOut = *imageTarget;
}
void image::extractChannelLuminance(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
					imageIn.convertTo(imageIn,CV_8UC3);

					for(int rows=0;rows<imageIn.rows;rows++)
								for(int cols=0;cols<imageIn.cols;cols++)
								{
									unsigned char B = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];
									unsigned char G = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];
									unsigned char R = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];
									unsigned char MAX = max(R,B,G);
									unsigned char MIN = min(R,G,B);
									unsigned char L = (MAX+MIN)/2;

									imageTarget->at<unsigned char>(rows,cols) = L;

								}
								imageOut = *imageTarget;
}
void image::extractChannelSaturation(cv::Mat& imageIn, cv::Mat& imageOut)
{
	cv::Mat *imageTarget = new cv::Mat(cv::Size2d(imageIn.cols,imageIn.rows),CV_8UC1);
						imageIn.convertTo(imageIn,CV_8UC3);

						for(int rows=0;rows<imageIn.rows;rows++)
									for(int cols=0;cols<imageIn.cols;cols++)
									{
										unsigned char B = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[0];
										unsigned char G = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[1];
										unsigned char R = (unsigned char)imageIn.at<cv::Vec3b>(rows,cols)[2];
										unsigned char MAX = max(R,B,G);
										unsigned char MIN = min(R,G,B);
										unsigned char L = (MAX+MIN)/2;
										unsigned char S = L>255/2?(MAX-MIN)/(MAX+MIN):(MAX-MIN)/2 -(MAX+MIN);

										imageTarget->at<unsigned char>(rows,cols) = S;

									}
									imageOut = *imageTarget;
}
