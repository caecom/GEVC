/* Biblioteca destinada a leitura e escrita de imagens utilizando a biblioteca OpenCV
 *
 *
 * Autor: Ricardo Medeiros
 * discente de Engenharia da Computão na Universidade Federal do Vale do São Francisco - UNIVASF
 *
 * Curso: "Visão Computacional: tópicos selecionados e aplicações com a biblioteca OpenCV"
 *
 * */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include "utilities.hpp"
class image
{
	public:
		void read(std::string& name, cv::Mat& imageOut);
		void display(std::string& name,cv::Mat& image, int delay = 0, bool destroy = true);
		bool store(std::string& name,cv::Mat& image);
		void extractChannel(cv::Mat& imageIn, cv::Mat& imageOut,int ChannelCode);
		enum ChannelTypes {
			ChannelRed=1,
			ChannelGreen=2,
			ChannelBlue=3,
			ChannelCyan=4,
			ChannelMagenta=5,
			ChannelYellow=6,
			ChannelY=7,
			ChannelU=8,
			ChannelV=9,
			ChannelHue=10,
			ChannelLuminance=11,
			ChannelSaturation=12,
		};

	private:
		void extractChannelRed(cv::Mat& imageIn, cv::Mat& imageOut);//1
		void extractChannelGreen(cv::Mat& imageIn, cv::Mat& imageOut);//2
		void extractChannelBlue(cv::Mat& imageIn, cv::Mat& imageOut);//3
		void extractChannelCian(cv::Mat& imageIn, cv::Mat& imageOut);//4
		void extractChannelMagenta(cv::Mat& imageIn, cv::Mat& imageOut);//5
		void extractChannelYellow(cv::Mat& imageIn, cv::Mat& imageOut);//6
		void extractChannelY(cv::Mat& imageIn, cv::Mat& imageOut);//7
		void extractChannelU(cv::Mat& imageIn, cv::Mat& imageOut);//8
		void extractChannelV(cv::Mat& imageIn, cv::Mat& imageOut);//9
		void extractChannelHue(cv::Mat& imageIn, cv::Mat& imageOut);//10
		void extractChannelLuminance(cv::Mat& imageIn, cv::Mat& imageOut);//11
		void extractChannelSaturation(cv::Mat& imageIn, cv::Mat& imageOut);//12





};
#endif /* IMAGE_HPP_ */
