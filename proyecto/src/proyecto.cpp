#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class clase_calculos{
	float met_calcularPorcentajeporPregunta(float saldo){
		//aqui se calcula el saldo obtenido por cada respuesta y se envia a una variable
		float saldo2 = (saldo*10)/100;
		return saldo2;
	}

	float met_calcularPorcentajeRetirarse(float saldo, int nivel){
		//aqui se calcula el saldo obtenido por retirarse del juego y se envia a una variable
		float saldo2 = 0.0;
		if (nivel==3){
			saldo2 = (saldo*25)/100;
		}
		if (nivel==6){
			saldo2 = (saldo*50)/100;
		}
		if(nivel==9){
			saldo2 = (saldo*75)/100;
		}
		return saldo2;

	}
};

//-------------------------------------------------------------------------------------------

class clase_validaciones{
public:
	//---------------------------------------------------------------------------------
	// aqui validamos las opciones que puede digitar el usuario dentro del menu de ingreso
	//siendo este ente 0 y 2, para evitar que el usuario digite otros comandos
	bool met_validarOpcionMenuingreso(int val_opcionIngreso)
	{
		if(val_opcionIngreso>=0 and val_opcionIngreso<=2)
		{
			return true;
		} else {
			return false;
		}

	}
	//---------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------
	//Aqui validamos las opciones detro del menu principal, que tiene un rango de 0 a 4
	bool met_validarOpcionMenuPrincipal(int val_opcionMenuPrincipal)
	{
		if(val_opcionMenuPrincipal>=0 and val_opcionMenuPrincipal<=4)
		{
			return true;
		} else {
			return false;
		}
	}

	//---------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------
	//Aqui validamos las opciones detro del menu de las preguntas, que tiene un rango de 0 a 4
	bool met_validarOpcionPregunta(int val_opcionPregunta)
	{
		if(val_opcionPregunta>=0 and val_opcionPregunta<=4)
		{
			return true;
		} else {
			return false;
		}
	}
	//---------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------
	//evalua la pregunta dada por el usuario y la resputa guardad en la matriz, retornando un booleano
	bool met_validarRespuesPregunta(int val_OpcionPregunta, int val_PreguntaMatriz)
	{
		if(val_OpcionPregunta == val_PreguntaMatriz)
		{
			return true;
		} else {
			return false;
		}
	}
	//---------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------
	//
	//---------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------
	bool met_validarSaldoIngresado(int val_saldoIngresado)
	{
		if(val_saldoIngresado>0){
			return true;
		} else {
			return false;
		}
	}

	bool met_validarSaldoParapartida(int val_saldoParaPartida)
	{
		if(val_saldoParaPartida>=10000){
			return true;
		} else {
			return false;
		}
	}

	bool met_validarRetirarSaldo(int val_saldoretirar, int saldo_delUsuario){
		if(val_saldoretirar>saldo_delUsuario){
			return true;
		} else {
			return false;
		}
	}

	
};




//En clase solo sirve para guardar metodos vacios que guardan solo
//string para mostrar los menus de forma ordenada
class clase_menus{
public:
	void met_menuInicial(){
		cout<<"----------Think And Win-------------"<<endl;
		cout<<"1-Comenzar Juego"<<endl;
		cout<<"2-Recargar saldo"<<endl;
		cout<<"3-Retirar saldo"<<endl;
		cout<<"0-Cerrar sesión"<<endl;
		cout<<"------------------------------------"<<endl;
	}
	void met_menuIngreso(){
		cout<<"---------Opciones de inicio---------"<<endl;
		cout<<"1-Iniciar seccion"<<endl;
		cout<<"2-Registrar nuevo jugador"<<endl;
		cout<<"0-Cerrar el juego"<<endl;
		cout<<"------------------------------------"<<endl;
	}
	void met_menu_preguntas(int nivel,  string vector[6]){
		cout<<"------------"<<nivel<<"------------"<<endl;
		cout<<vector[0];
		cout<<vector[1];
		cout<<vector[2];
		cout<<vector[3];
		cout<<vector[4];
	}

};





//en la clase login, se ingresa aL juego y se registran nuevos usarios
class clase_login{
public:
	//atributo que guarda temporalmente el usuario
	vector<string> atr_usuarios;
	//atributo que guarda temporalmente la contraseña
	vector<string> atr_contrasenas;
	//
	string atr_user;
	string atr_pass;


	//---------------------------------------------------------------------------------
	//con este metodo creamos nuevos jugadores en el sisteam, asignando un usuario y una contraseña
	void met_crear_jugador()
	{
		cout<<"Ingrese su nombre de usuario"<<endl;
		cin>>atr_user;
		cout<<"Ingrese contraseña"<<endl;
		cin>>atr_pass;
		//Validacion
		atr_usuarios.push_back(atr_user);
		atr_contrasenas.push_back(atr_pass);


		//Validacion
	};
	//---------------------------------------------------------------------------------




	//---------------------------------------------------------------------------------
	//metodo para iniciar la seccion
	bool met_iniciar_seccion()
	{
	    bool val_ingresar = false;
	    cout << "Ingrese su nombre de usuario" << endl;
	    cin >> atr_user;
	    cout << "Ingrese contraseña" << endl;
	    cin >> atr_pass;
	    int tamano = atr_usuarios.size();


	    for (int i = 0; i < tamano; i++)
	    {
	        if (atr_usuarios[i] == atr_user && atr_contrasenas[i] == atr_pass)
	        {
	            val_ingresar = true;
	            break;
	        }
	    }

	    return val_ingresar;
	}

	//---------------------------------------------------------------------------------
};



class clase_perfilJugador{
public:
	float atr_saldo=0;
	//---------------------------------------------------------------------------------
	float met_ingresarsaldo(){
		//con este metodo le pedimos al usuario el dinero que desea ingresar al juego
		cout<<"Cuanto dinero desea ingresar?"<<endl;
		cin>>atr_saldo;
		return atr_saldo;
	}
	//---------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------
	float met_retirarsaldo(){
		//creamos una variable que guardara el saldo a retirar
		float saldoRetirado = 0;
		cout<<"Cuanto dinero desea sacar?"<<endl;
		//ingresamos el saldo para retirar
		cin>>saldoRetirado;
		return atr_saldo-saldoRetirado; //restamos el valor ingresado al saldo original
	}
	//---------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------
	//mostramos el saldo por pantalla
	void met_revisarSaldo(){
		cout<<"Saldo disponible"<<endl;
		cout<<atr_saldo<<endl;
	}
	//---------------------------------------------------------------------------------
};




class clase_preguntas{
public:
	string matriz_Nivel1[4][6] = {{"¿Cuál es el planeta más cercano al Sol?","1. Venus","2. Marte","3. Mercurio","4. Júpiter","3"},
			                      {"¿Quién pintó la Mona Lisa?","1. Leonardo da Vinci","2. Pablo Picasso","3. Vincent van Gogh","4. Salvador Dalí","1"},
								  {"¿Cuál es la capital de Colombia?","1. Bogotá","2. Medellín","3. Cali","4. Cartagena","1"},
								  {"¿En qué año se independizó Colombia de España?","1. 1810","2. 1819","3. 1821","4. 1830","3"}};

	string matriz_Nivel2[4][6] = {{"¿Cuál es la unidad básica de la estructura de los seres vivos?","1. Célula","2. Molécula","3. Átomo","4. Tejido","1"},
			                      {"¿Cuál de estos artistas es conocido por sus pinturas de girasoles?","1. Claude Monet","2. Michelangelo","3. Frida Kahlo","4. Vincent van Gogh","4"},
			                      {"¿En qué continente se encuentra Colombia?","1. América del Norte","2. América Central","3. América del Sur","4. Europa","3"},
			                      {"¿Cuál fue el nombre del movimiento político y militar liderado por Simón Bolívar que buscaba la independencia de varios países sudamericanos, incluyendo Colombia?","1. La Gran Colombia","2. La Confederación de los Andes","3. La Liga de los Pueblos Libres","4. El Virreinato de la Nueva Granada","1"}};

	string matriz_Nivel3[4][6] = {{"¿Cuál es el proceso mediante el cual las plantas fabrican su alimento?","1. Fotosíntesis","2. Respiración","3. Digestión","4. Transpiración","1"},
			                      {"¿Qué movimiento artístico se caracteriza por el uso de líneas rectas, formas geométricas y colores primarios?","1. Renacimiento","2. Barroco","3. Cubismo","4. Impresionismo","3"},
			                      {"¿Cuál es el océano que baña las costas de Colombia?","1. Océano Atlántico","2. Océano Pacífico","3. Océano Índico","4. Océano Ártico","1"},
			                      {"¿Cuál fue la primera civilización precolombina en habitar el territorio que hoy es Colombia?","1. Muiscas","2. Taironas","3. Quimbayas","4. Zenúes","1"}};

	string matriz_Nivel4[4][6] = {{"¿Cuál es el ácido presente en el jugo gástrico del estómago?","1. Ácido sulfúrico","2. Ácido clorhídrico","3. Ácido acético","4. Ácido cítrico","2"},
                                  {"¿Quién pintó (La noche estrellada)?","1. Vincent van Gogh","2. Pablo Picasso","3. Salvador Dalí","4. Gustav Klimt","1"},
                                  {"¿Cuál es el pico más alto de Colombia?","1. Pico Cristóbal Colón","2. Nevado del Ruiz","3. Pico Simón Bolívar","4. Cerro Pan de Azúcar","1"},
                                  {"¿Cuál de los siguientes presidentes de Colombia fue conocido como (El Libertador)?","1. Simón Bolívar","2. Rafael Núñez","3. Francisco de Paula Santander","4. Alfonso López Pumarejo","1"}};

	string matriz_Nivel5[4][6] = {{"¿Cuál es el componente principal de la capa de ozono?","1. Oxígeno","2. Nitrógeno","3. Ozono","4. Dióxido de carbono","3"},
                                  {"¿Cuál de estos artistas es conocido por su técnica de puntillismo?","1. Georges Seurat","2. Jackson Pollock","3. Piet Mondrian","4. Wassily Kandinsky","1"},
                                  {"¿Cuál es el río más largo de Colombia?","1. Río Magdalena","2. Río Cauca","3. Río Amazonas","4. Río Guaviare","1"},
                                  {"¿En qué año se firmó el acuerdo de paz entre el gobierno colombiano y las FARC (Fuerzas Armadas Revolucionarias de Colombia)?","1. 2016","2. 2017","3. 2018","4. 2019","2"}};

	string matriz_Nivel6[4][6] = {{"¿Cuál es la fórmula química del agua?","1. H2O","2. CO2","3. NaCl","4. C6H12O6","1"},
                                  {"¿Quién es el autor de la escultura (El Pensador)?","1. Auguste Rodin","2. Antonio Canova","3. Donatello","4. Michelangelo","1"},
                                  {"¿Cuál es el departamento más poblado de Colombia?","1. Antioquia","2. Bogotá","3. Valle del Cauca","4. Atlántico","2"},
                                  {"¿Cuál fue la primera ciudad fundada por los españoles en el territorio que hoy es Colombia?","1. Santa Marta","2. Cartagena","3. Bogotá","4. Popayán","2"}};

	string matriz_Nivel7[4][6] = {{"¿Cuál es el proceso mediante el cual ocurre la división celular en las células somáticas?","1. Meiosis","2. Mitosis","3. Fertilización","4. Replicación","2"},
                                  {"¿Cuál de estas obras es una creación de Salvador Dalí?","1. La persistencia de la memoria","2. El nacimiento de Venus","3. La última cena","4. Las señoritas de Avignon","1"},
                                  {"¿Cuál es la isla más grande de Colombia?","1. Isla de San Andrés","2. Isla Gorgona","3. Isla Malpelo","4. Isla Fuerte","1"},
                                  {"¿Quién fue el líder del movimiento de independencia en Colombia conocido como (El Florero de Llorente)?","1. Antonio Nariño","2. José María Córdova","3. Policarpa Salavarrieta","4. Camilo Torres","1"}};


	string matriz_Nivel8[4][6] = {{"¿Cuál es la ley de la física que establece que la energía no se crea ni se destruye, solo se transforma?","1. Ley de Ohm","2. Ley de la gravitación universal","3. Ley de la conservación de la energía","4. Ley de la termodinámica","3"},
                                  {"¿Cuál de estos movimientos artísticos se caracteriza por su uso de formas abstractas y colores brillantes?","1. Expresionismo","2. Renacimiento","3. Realismo","4. Arte pop","4"},
                                  {"¿Cuál es la ciudad colombiana conocida como (La Ciudad de la Eterna Primavera)?","1. Medellín","2. Cartagena","3. Barranquilla","4. Cali","1"},
                                  {"¿Cuál de los siguientes eventos históricos en Colombia tuvo lugar el 9 de abril de 1948?","1. El Bogotazo","2. La firma del Acuerdo de Paz de La Habana","3. El asesinato de Jorge Eliécer Gaitán","4. La fundación de la Universidad Nacional de Colombia","3"}};


	string matriz_Nivel9[4][6] = {{"¿Cuál es el proceso mediante el cual los organismos vivos obtienen energía de los alimentos?","1. Digestión","2. Respiración","3. Fermentación","4. Fotosíntesis","2"},
                                  {"¿Quién es el autor de la escultura (El David)?","1. Donatello","2. Auguste Rodin","3. Michelangelo","4. Antonio Canova","3"},
                                  {"¿Cuál es el desierto ubicado en la Guajira colombiana?","1. Desierto de la Tatacoa","2. Desierto de la Candelaria","3. Desierto de la Macarena","4. Desierto de la Guajira","3"},
                                  {"¿Quién fue el presidente de Colombia durante la construcción del Canal de Panamá?","1. José Manuel Marroquín","2. Rafael Reyes","3. Enrique Olaya Herrera","4. Carlos Eugenio Restrepo","2"}};

	string matriz_Nivel10[4][6] ={{"¿Cuál es la partícula subatómica con carga positiva en el núcleo de un átomo?","1. Electrón","2. Neutrón","3. Protón","4. Quark","3"},
                                  {"¿Cuál de estos artistas es conocido por sus pinturas de la serie (Campbell's Soup Cans)?","1. Andy Warhol","2. Jackson Pollock","3. Frida Kahlo","4. Henri Matisse","1"},
                                  {"¿Cuál es el archipiélago colombiano declarado Patrimonio de la Humanidad por la UNESCO?","1. Islas del Rosario","2. Islas de San Bernardo","3. Islas del Pacífico","4. Islas de San Andrés y Providencia","4"},
                                  {"¿Cuál de los siguientes líderes indígenas fue el último en resistir la colonización española en el territorio que hoy es Colombia?","1. Túpac Amaru","2. Atahualpa","3. Túpac Yupanqui","4. Gaitana","4"}};



	string met_seleccionar_vector(int nivel_juego){
		srand(time(0)); // Inicializar la semilla de generación de números aleatorios
		int columna_aleatoria = rand() % 4 + 1; // Generar un número aleatorio del 1 al 4
		string var_pregunta;
		string var_opcion1;
		string var_opcion2;
		string var_opcion3;
		string var_opcion4;
		string var_respuesta;

		switch(nivel_juego){
		case 1:
			var_pregunta =matriz_Nivel1[columna_aleatoria][0];
			var_opcion1=matriz_Nivel1[columna_aleatoria][1];
			var_opcion2=matriz_Nivel1[columna_aleatoria][2];
			var_opcion3=matriz_Nivel1[columna_aleatoria][3];
			var_opcion4=matriz_Nivel1[columna_aleatoria][4];
			var_respuesta=matriz_Nivel1[columna_aleatoria][5];
			break;

		case 2:
			var_pregunta =matriz_Nivel2[columna_aleatoria][0];
			var_opcion1=matriz_Nivel2[columna_aleatoria][1];
			var_opcion2=matriz_Nivel2[columna_aleatoria][2];
			var_opcion3=matriz_Nivel2[columna_aleatoria][3];
			var_opcion4=matriz_Nivel2[columna_aleatoria][4];
			var_respuesta=matriz_Nivel2[columna_aleatoria][5];
			break;

		case 3:
			var_pregunta =matriz_Nivel3[columna_aleatoria][0];
			var_opcion1=matriz_Nivel3[columna_aleatoria][1];
			var_opcion2=matriz_Nivel3[columna_aleatoria][2];
			var_opcion3=matriz_Nivel3[columna_aleatoria][3];
			var_opcion4=matriz_Nivel3[columna_aleatoria][4];
			var_respuesta=matriz_Nivel3[columna_aleatoria][5];
			break;

		case 4:
			var_pregunta =matriz_Nivel4[columna_aleatoria][0];
			var_opcion1=matriz_Nivel4[columna_aleatoria][1];
			var_opcion2=matriz_Nivel4[columna_aleatoria][2];
			var_opcion3=matriz_Nivel4[columna_aleatoria][3];
			var_opcion4=matriz_Nivel4[columna_aleatoria][4];
			var_respuesta=matriz_Nivel4[columna_aleatoria][5];
			break;

		case 5:
			var_pregunta =matriz_Nivel5[columna_aleatoria][0];
			var_opcion1=matriz_Nivel5[columna_aleatoria][1];
			var_opcion2=matriz_Nivel5[columna_aleatoria][2];
			var_opcion3=matriz_Nivel5[columna_aleatoria][3];
			var_opcion4=matriz_Nivel5[columna_aleatoria][4];
			var_respuesta=matriz_Nivel5[columna_aleatoria][5];
			break;

		case 6:
			var_pregunta =matriz_Nivel6[columna_aleatoria][0];
			var_opcion1=matriz_Nivel6[columna_aleatoria][1];
			var_opcion2=matriz_Nivel6[columna_aleatoria][2];
			var_opcion3=matriz_Nivel6[columna_aleatoria][3];
			var_opcion4=matriz_Nivel6[columna_aleatoria][4];
			var_respuesta=matriz_Nivel6[columna_aleatoria][5];
			break;
		case 7:
			var_pregunta =matriz_Nivel7[columna_aleatoria][0];
			var_opcion1=matriz_Nivel7[columna_aleatoria][1];
			var_opcion2=matriz_Nivel7[columna_aleatoria][2];
			var_opcion3=matriz_Nivel7[columna_aleatoria][3];
			var_opcion4=matriz_Nivel7[columna_aleatoria][4];
			var_respuesta=matriz_Nivel7[columna_aleatoria][5];
			break;
		case 8:
			var_pregunta =matriz_Nivel8[columna_aleatoria][0];
			var_opcion1=matriz_Nivel8[columna_aleatoria][1];
			var_opcion2=matriz_Nivel8[columna_aleatoria][2];
			var_opcion3=matriz_Nivel8[columna_aleatoria][3];
			var_opcion4=matriz_Nivel8[columna_aleatoria][4];
			var_respuesta=matriz_Nivel8[columna_aleatoria][5];
			break;
		case 9:

			var_pregunta =matriz_Nivel9[columna_aleatoria][0];
			var_opcion1=matriz_Nivel9[columna_aleatoria][1];
			var_opcion2=matriz_Nivel9[columna_aleatoria][2];
			var_opcion3=matriz_Nivel9[columna_aleatoria][3];
			var_opcion4=matriz_Nivel9[columna_aleatoria][4];
			var_respuesta=matriz_Nivel9[columna_aleatoria][5];
			break;
		case 10:
			var_pregunta =matriz_Nivel10[columna_aleatoria][0];
			var_opcion1=matriz_Nivel10[columna_aleatoria][1];
			var_opcion2=matriz_Nivel10[columna_aleatoria][2];
			var_opcion3=matriz_Nivel10[columna_aleatoria][3];
			var_opcion4=matriz_Nivel10[columna_aleatoria][4];
			var_respuesta=matriz_Nivel10[columna_aleatoria][5];
			break;
		default:
			cout<<"error de nivel"<<endl;
			break;
		};

		string vector_nivel[6];
		vector_nivel[0]= var_pregunta;
		vector_nivel[1]=var_opcion1;
		vector_nivel[2]=var_opcion2;
		vector_nivel[3]=var_opcion3;
		vector_nivel[4]= var_opcion4;
		vector_nivel[5]=var_respuesta;

		for (int i = 0; i < 6; i++) {
		        cout << vector_nivel[i] << std::endl;
		    }

        return vector_nivel[6];
	};
};

class clase_juego{
public:
	int atr_nivel;
	void juego(){
		bool i = true;
		bool j = true;
		clase_preguntas pregunta;
		clase_perfilJugador jugador;
		clase_login login;
		clase_menus menus;

		int opc_principal = 0;
		int opc_inicial = 0;

		while(i == true){
			menus.met_menuIngreso();
			cin>>opc_principal;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			switch(opc_principal){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1:
				menus.met_menuInicial();
				cin>>opc_inicial;
				while(j == true){
					switch(opc_inicial){
					case 1:
						cout<<"usuario registrado con exito"<<endl;
						continue;
					case 2:
						cout<<"recargar saldo"<<endl;
						continue;
					case 3:
						cout<<"retirar saldo"<<endl;
						continue;
					case 0:
						j = false;
						cout<<"sesion cerrada con exito"<<endl;
						continue;

					}
///////////////////CIERA EL SWITCH SECUNDARIO////////////////////////////////////////////////////////////////////////////////////////////
				};
/////////////////////CIERRA EL WHILE SECUNDARIO//////////////////////////////////////////////////////////////////////////////////////////
				break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 2:
				cout<<"usuario registrado con exito"<<endl;
				continue;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 0:
				i = false;
				cout<<"el programa ha sido cerrado con exito"<<endl;
				break;

			}
/////////////////////////CIERRA SWITCH//////////////////////////////////////////////////////////////////////////////////////
		}
/////////CIERRA WHILE INICIAL//////////////////////////////////////////////////////////////////////////////////////////////////////
	};
//////////CIERRA EL METODO/////////////////////////////////////////////////////////////////////////////////////////////////////
};
///////////CIERRA LA CLASE////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	clase_juego iniciar;
	iniciar.juego();
	return 0;
}
