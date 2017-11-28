#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
using namespace std;
void readFile()
{

   string line;
   ifstream myfile("example1.pgm");

   if (myfile.is_open()){
       while (myfile.good()){
         getline (myfile,line);
         cout << line;
       }
   }
}

int main(void)
{
	readFile();
}
/*...
std::string header, magic;
int width=0, height=0, maxsample=0, samples=0, bits=0, bytes=0;

do {
   try { getline(is,magic); } catch ( const std::ios_base::failure & ) {}
   if ( !magic.empty() && magic[0] != '#' ) header += magic+" ";
   if ( !( std::stringstream(header+" 1") >> magic >> width >> height >> maxsample ).eof() ) break;
   if ( ( (magic=="P1"||magic=="P4") && maxsample==1 ) || !is.good() ) break;
   } while ( true );

samples = magic=="P1"?1:magic=="P2"?1:magic=="P3"?3:magic=="P4"?1:magic=="P5"?1:magic=="P6"?3:0;
bits = (magic=="P1"||magic=="P4")?1:maxsample<256?8:maxsample<256*256?16:0, bytes = (width*samples*bits+7)>>3;
if ( width<=0 || height<=0 || maxsample<=0 || samples<=0 || bits<=0 ) throw std::runtime_error("invalid PNM header");
*/
