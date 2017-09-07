#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::cout;
using std::endl;

void descripcion();
int tiraDados();
void resultado(int);
char continua();

int main()
{
	int suma;

	srand( time(0) );
	system("color c");
	system("cls");
	descripcion();

	do
	{
		system("cls");

		suma = tiraDados();

		resultado( suma );
	}
	while( continua() == 'y' );

	return 0;
}

int tiraDados()
{
	int dado1;
	int dado2;
	int sumaTrabajo;

	dado1 = 1 + rand() % 6;
	dado2 = 1 + rand() % 6;
	sumaTrabajo = dado1 + dado2;

	cout << "El jugador tiro " << dado1 << " + " << dado2 << " = " << sumaTrabajo << endl << endl;

	return sumaTrabajo;
}

void resultado( int suma)
{
	enum Status { CONTINUA, GANA, PIERDE };

	int miPunto;

	Status estadoJuego;

	switch( suma )
	{
		case 7:
		case 11:
			estadoJuego = GANA;
			break;

		case 2:
		case 3:
		case 12:
			estadoJuego = PIERDE;
			break;

		default:
			estadoJuego = CONTINUA;
			miPunto = suma;
			cout << "La puntuacion es: " << miPunto << endl << endl;
			break;
	}

	while( estadoJuego == CONTINUA )
	{
		suma = tiraDados();

		if( suma == miPunto )
			estadoJuego = GANA;
		else
			if( suma == 7 )
				estadoJuego = PIERDE;
	}

	if( estadoJuego == GANA )
		cout << "El jugador gana" << endl;
	else
		cout << "El jugador pierde" << endl;
}


char continua()
{
	char ans;
	do
	{
		cout << "Desea continuar?...(Y/N)";
		std::cin >> ans;

		if( tolower(ans) != 'y' && tolower(ans) != 'n' )
		cout << "\aPresione Y or N !" << endl;
	}
	while( tolower(ans) != 'y' && tolower(ans) != 'n' );

	return tolower(ans);
}

void descripcion()
{
	cout << std::setw(45) << "INSTRUCCIONES\n";
    cout << "============================================================================\n";
    cout << " Un jugador lanza 2 dados. Una vez que los dados caen, se calcula la suma\n"
    	 <<	" de los puntos de las caras superiores de ambos dados. Si la suma es 7 u\n"
    	 << " 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el \n"
    	 << " primer tiro (llamado 'craps'), el jugador pierde (es decir la 'casa' gana).\n"
    	 << " Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, entonces esta se \n"
    	 << " convierte en 'punto' del jugador. Para ganar, usted debe continuar tirando\n"
    	 << " los dados hasta que 'logre su punto'. El jugador pierde si tira 7 antes de\n"
    	 << " hacer su punto.\n";

    cout << "============================================================================\n";

	system("pause");
}
