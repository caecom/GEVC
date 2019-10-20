#include "utilities.hpp"
void waitForKey()
{
	getchar();
}

void error(bool status,std::string message, int code)
{
	if(status)
	{
		std::cout<<message<<'\n';
		//exit(code);
	}
}
unsigned char max(unsigned char A,unsigned char B,unsigned char C)
{
	unsigned char aux;
	aux= A>B?A:B;
	aux =aux>C?aux:C;
	return aux;
}
unsigned char min(unsigned char A,unsigned char B,unsigned char C)
{
	unsigned char aux;
	aux= A<B?A:B;
	aux =aux<C?aux:C;
	return aux;
}
std::string getCurrentPath(std::string adendo)
{
	char cCurrentPath[FILENAME_MAX];

	if(!GetCurrentDir(cCurrentPath,sizeof(cCurrentPath)))
		return NULL;

	cCurrentPath[sizeof(cCurrentPath)-1] = '\0';

	std::string out(cCurrentPath);
	out+="/"+adendo;
	return out;
}
