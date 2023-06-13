//============================================================================
// Name        : proyecto.cpp
// Author      : oscar
// Version     : 
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class clase_perfilJugador{
public:
	float atr_saldo=0;

	float met_ingresarsaldo(){
		//con este metodo le pedimos al usuario el dinero que desea ingresar al juego
		cout<<"Cuanto dinero desea ingresar?";
		cin<<atr_saldo;
		return atr_saldo;
	}
	float met_retirarsaldo(){
		float saldoRetirado = 0;
		cout<<"Cuanto dinero desea sacar?";
		cin<<saldoRetirado;
		return atr_saldo-saldoRetirado;
	}
};



class clase_calculos{
	float met_calcularPorcentajeporPregunta(float saldo){
		//aqui se calcula el saldo obtenido por cada respuesta y se envia a una variable
		float saldo2 = (saldo*10)/100;
		return saldo2;
	}

	float met_calcularPorcentajeRetirarse(float saldo, int lvl){
		//aqui se calcula el saldo obtenido por retirarse del juego y se envia a una variable
		float saldo2 = 0;
		if (lvl==3){
			float saldo2 = (saldo*25)/100;
		}
		if (lvl==6){
			float saldo2 = (saldo*50)/100;
		}
		if(lvl==9){
			float saldo2 = (saldo*75)/100;
		}
		return saldo2;

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
	void met_menuPreguntas(string matrizPreguntas[[, int nlv, int num){
		cout<<"---------Nivel ("<<nlv<<"----------"<<endl;
		cout<<"¿¿"<<matrizPregunta[num[0<<"??"<<endl;
		cout<<"1-"<<matrizPregunta[num[1<<endl;
		cout<<"2-"<<matrizPregunta[num[2<<endl;
		cout<<"3-"<<matrizPregunta[num[2<<endl;
		cout<<"4-"<<matrizPregunta[num[2<endl;
	}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
