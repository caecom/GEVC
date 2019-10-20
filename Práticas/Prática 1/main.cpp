#include "image.hpp"
int main(void)
{
	std::string nome;
	cv::Mat imagem;
	image img;
	std::string novonome;

	std::cin >> nome;
	img.read(nome,imagem);
	img.display(nome,imagem,3000);
	novonome = nome+"(Copia).jpg";
	img.store(novonome,imagem);

}



