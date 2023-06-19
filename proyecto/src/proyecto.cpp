
#include <iostream>
using namespace std;
//En clase solo sirve para guardar metodos vacios que guardan solo
//string para mostrar los menus de forma ordenada
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
	//este es el unico que recibe una matriz y 2 variables, para definir la pregunta
	void met_menuPreguntas(string matrizPreguntas[], int nlv, int num){
		cout<<"---------Nivel ("<<nlv<<"----------"<<endl;
		cout<<"¿¿"<<matrizPreguntas[num][0]<<"??"<<endl;
		cout<<"1-"<<matrizPreguntas[num][1]<<endl;
		cout<<"2-"<<matrizPreguntas[num][2]<<endl;
		cout<<"3-"<<matrizPreguntas[num][3]<<endl;
		cout<<"4-"<<matrizPreguntas[num][4]<<endl;
	};

};




//en la clase login, se ingresa aL juego y se registran nuevos usarios
class clase_login{
public:
	//atributo que guarda temporalmente el usuario
	string atr_usuario;
	//atributo que guarda temporalmente la contraseña
	string atr_contraseña;
	//matroz que solo tiene 2 columnas, donde una se le asignan los usuarios y la otra a las contraseñas
	string atr_usuarios[][];

	//con este metodo creamos nuevos jugadores en el sisteam, asignando un usuario y una contraseña
	void met_crear_jugador(){
		cout<<"Ingrese su nombre de usuario"<<endl;
		cin>>atr_usuario;
		cout<<"Ingrese contraseña"<<endl;
		cin>>atr_contraseña;

		//Validacion

		//Validacion

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				atr_usuario = atr_usuarios[i][j];
				atr_contraseña = atr_usuarios[i][j];
			}
		}
	}
};


class clase_perfilJugador{
public:
	float atr_saldo=0;

	float met_ingresarsaldo(){
		//con este metodo le pedimos al usuario el dinero que desea ingresar al juego
		cout<<"Cuanto dinero desea ingresar?"<<endl;
		cin<<atr_saldo;
		return atr_saldo;
	}
	float met_retirarsaldo(){
		//creamos una variable que guardara el saldo a retirar
		float saldoRetirado = 0;
		cout<<"Cuanto dinero desea sacar?"<<endl;
		//ingresamos el saldo para retirar
		cin<<saldoRetirado;
		return atr_saldo-saldoRetirado; //restamos el valor ingresado al saldo original
	}
	//mostramos el saldo por pantalla
	void met_revisarSaldo(){
		cout<<"Saldo disponible"<<endl;
		cout<<atr_saldo<<endl;
	}
};



class clase_calculos{
	float met_calcularPorcentajeporPregunta(float saldo){
		//aqui se calcula el saldo obtenido por cada respuesta y se envia a una variable
		float saldo2 = (saldo*10)/100;
		return saldo2;
	}

	float met_calcularPorcentajeRetirarse(float saldo, int nivel){
		//aqui se calcula el saldo obtenido por retirarse del juego y se envia a una variable
		float saldo2 = 0;
		if (nivel==3){
			float saldo2 = (saldo*25)/100;
		}
		if (nivel==6){
			float saldo2 = (saldo*50)/100;
		}
		if(nivel==9){
			float saldo2 = (saldo*75)/100;
		}
		return saldo2;

	}
};





int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
