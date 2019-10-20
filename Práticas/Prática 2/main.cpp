#include "image.hpp"
#include "video.hpp"
#include "utilities.hpp"
int main(void)
{
	image img;
	std::string name = "imagem.jpg";
	//std::string folder = "resultados/";
	//std::string directory = getCurrentPath(folder);
	//std::cout<<directory<<std::endl;
	cv::Mat mat,matBlue,matGreen,matRed,matCyan,matMagenta,matYellow,matY,matU,matV,matHue,matLuminance,matSaturation;


	img.read(name,mat);
	img.extractChannel(mat,matBlue,img.ChannelBlue);
	img.extractChannel(mat,matGreen,img.ChannelGreen);
	img.extractChannel(mat,matRed,img.ChannelRed);
	img.extractChannel(mat,matCyan,img.ChannelCyan);
	img.extractChannel(mat,matMagenta,img.ChannelMagenta);
	img.extractChannel(mat,matYellow,img.ChannelYellow);
	img.extractChannel(mat,matV,img.ChannelV);
	img.extractChannel(mat,matU,img.ChannelU);
	img.extractChannel(mat,matY,img.ChannelY);
	img.extractChannel(mat,matHue,img.ChannelHue);
	img.extractChannel(mat,matLuminance,img.ChannelLuminance);
	img.extractChannel(mat,matSaturation,img.ChannelSaturation);




	name = "ChannelBlue.jpg";
	img.display(name,matBlue,30,false);
	//name = directory+name;
	img.store(name,matBlue);
	name = "ChannelGreen.jpg";
	img.display(name,matGreen,30,false);
	//name = directory+name;
	img.store(name,matGreen);
	name = "ChannelRed.jpg";
	img.display(name,matRed,30,false);
	//name = directory+name;
	img.store(name,matRed);
	name = "Channel Cyan.jpg";
	img.display(name,matCyan,30,false);
	//name = directory+name;
	img.store(name,matCyan);
	name = "ChannelMagenta.jpg";
	img.display(name,matMagenta,30,false);
	//name = directory+name;
	img.store(name,matMagenta);
	name = "ChannelYellow.jpg";
	img.display(name,matYellow,30,false);
	//name = directory+name;
	img.store(name,matYellow);
	name = "ChannelY.jpg";
	img.display(name,matY,30,false);
	//name = directory+name;
	img.store(name,matY);
	name = "ChannelU.jpg";
	img.display(name,matU,30,false);
	//name = directory+name;
	img.store(name,matU);
	name = "ChannelV.jpg";
	img.display(name,matV,30,false);
	//name = directory+name;
	img.store(name,matV);
	name = "ChannelHue.jpg";
	img.display(name,matHue,30,false);
	//name = directory+name;
	img.store(name,matHue);
	name = "ChannelLuminance.jpg";
	img.display(name,matLuminance,30,false);
	//name = directory+name;
	img.store(name,matLuminance);
	name = "ChannelSaturation.jpg";
	img.display(name,matSaturation,30,false);
	//name = directory+name;
	img.store(name,matSaturation);


	name = "imagem.jpg";
	img.display(name,mat,30,false);



	waitForKey();



}



