#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

ofstream archivo;
archivo.open("LogNums.txt", ios::out); //Abrimos el archivo (Si el archio existe lo reemplaza, si no existe lo crea)

void Escribir(int num);

int main()
{
	unsigned t0, t1;

	t0 = clock();

	int numFib = 0;
  	int aux = 1;
  	int aux2 = 0;

	for(int i = 0; i < 10; i++)
	{

		aux2 = numFib + aux;
		numFib = aux;
		aux = aux2;

		Escribir(aux2);
	}

	t1 = clock();

	double time = ((double)t1 - t0) / CLOCKS_PER_SEC;

	cout<<"Se ha tardado: "<<time<<" en ejecutar el programa"<<endl;
}

void Escribir(int num)
{

  if(archivo.fail()) //Capturamos posibles errores
  {
    cout<<"No se pudo abrir el archivo"<<endl;
    exit(1);
  }
  archivo<<"Fib: " <<num;

  archivo.close();
}
