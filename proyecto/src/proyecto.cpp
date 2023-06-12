//============================================================================
// Name        : proyecto.cpp
// Author      : oscar
// Version     : 
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;


class clase_calculos{
	float met_calcularPorcentajeporPregunta(float saldo){
		
	}
};


class clase_menus{
public:
	void met_menuInicial(){
		cout<<"----------Think And Win-------------"<<endl;
		cout<<"		1-Comenzar Juego"<<endl;
		cout<<"		2-Recargar saldo"<<endl;
		cout<<"		4-Retirar saldo"<<endl;
		cout<<"		0-Cerrar seccion"<<endl;
		cout<<"------------------------------------"<<endl;
	}
	void met_menuIngreso(){
		cout<<"---------Opciones de inicio---------"<<endl;
		cout<<"		1-Iniciar seccion"<<endl;
		cout<<"		2-Registrar nuevo jugador"<<endl;
		cout<<"		0-Cerrar el juego"<<endl;
		cout<<"------------------------------------"<<endl;
	}
	void met_menuPreguntas(string pregunta,string res1, string res2,string res3,string res4, int nlv){
		cout<<"---------Nivel ("<<nlv<<"----------"<<endl;
		cout<<"¿¿"<<pregunta<<"??"<<endl;
		cout<<"1-"<<res1<<endl;
		cout<<"2-"<<res2<<endl;
		cout<<"3-"<<res3<<endl;
		cout<<"4-"<<res4<<endl;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
