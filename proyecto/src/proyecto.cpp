#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class clase_calculos{
public:
	float met_calcularPorcentajeporPregunta(float saldo){
		//aqui se calcula el saldo obtenido por cada respuesta y se envia a una variable
		float saldo2 = (saldo * 0.1);
		return saldo2;
	}

	float met_calcularPorcentajeRetirarse(float saldo, int nivel){
		//aqui se calcula el saldo obtenido por retirarse del juego y se envia a una variable
		float saldo2 = 0.0;
		if (nivel==3){
			saldo2 = (saldo*0.25);
		}
		if (nivel==6){
			saldo2 = (saldo*0.50);
		}
		if(nivel==9){
			saldo2 = (saldo*0.75);
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
	//con este metodo nos ayudamos a validar que el usuario en ningun momento ponga un numero negativo
	//al momento de ingresar algo respecto a dinero
	bool met_validarSaldoIngresado(int val_saldoIngresado)
	{
		if(val_saldoIngresado>0){
			return true;
		} else {
			return false;
		}
	}
	//Dado que cada partida requiere un saldo minimo de 10000 por partida, nos ayudamos
	//de este metodo para validar dicho valor
	bool met_validarSaldoParapartida(int val_saldoParaPartida)
	{
		if(val_saldoParaPartida>=10000){
			return true;
		} else {
			return false;
		}
	}
	//Aqui con dos variables de tipo int, logramos captura que el dinero retirado
	//nunca sea mayor al dinero que el usuario tenga en su cuenta
	bool met_validarRetirarSaldo(int val_saldoretirar, int saldo_delUsuario){
		if(val_saldoretirar<=saldo_delUsuario){
			return true;
		} else {
			return false;
		}
	}
	//Si el saldo del usuario ingresado al momento de jugar es mayor a dinero del que dispone
	//existe un error, este metodo nos ayuda a solucionar esto
	bool met_validarSaldoParajugar(int val_saldoAjugar, int saldo_delUsuario){
		if(val_saldoAjugar<=saldo_delUsuario){
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
		cout<<"4-Revisar saldo"<<endl;
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


};





//en la clase login, se ingresa aL juego y se registran nuevos usarios
class clase_login{
public:
	vector<string> atr_usuarios; // 0 1 2 3 4
	//
	vector<string> atr_contrasenas; // 0 1 2 3 4

	//---------------------------------------------------------------------------------
	//con este metodo creamos nuevos jugadores en el sisteam, asignando un usuario y una contraseña
	void met_crear_jugador(string atr_user, string atr_pass)
	{
		//Validacion

		atr_usuarios.push_back(atr_user); // 0 - daniel 1 daniel
		atr_contrasenas.push_back(atr_pass); // 0 - 123 1 456


		//Validacion
	};
	//---------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------
	//metodo para iniciar seccion para comprobar que el usuario exista
	bool met_iniciar_seccion(string atr_user, string atr_pass)
	{
	    bool val_ingresar = false;
	    //con ayuda de este variable y el comando .size de la libreria vector
	    //nos ayudamos a descubir el tamano del vector
	    int tamano = atr_usuarios.size();

	    //
	    for (int i = 0; i < tamano; i++)
	    	//con ayuda de la variable i, buscamos en la misma posicion de los 2 vectores
	    	//para que corresponda a los datos ingresados y se retorne un valor true
	    { //                 0     daniel                      0      123
	        if (atr_usuarios[i] == atr_user && atr_contrasenas[i] == atr_pass)
	        {
	            val_ingresar = true;
	            break;
	        }
	    }

	    return val_ingresar;
	}
	//---------------------------------------------------------------------------------
	// Tomando las mismas dirrectrices del metodo de arriba, sacamos el valor de i y
	//descubrimos la posicion del usuario para ayudarnos a administrar su perfil.
	int met_posicion_usuario(string atr_user)
	{
		int posicion_usuario = 0;
	    int tamano = atr_usuarios.size();
	    for (int i = 0; i < tamano; i++)
	    { //
	        if (atr_usuarios[i] == atr_user)
	        {
	        	posicion_usuario = i;
	            break;
	        }
	    }
	    return posicion_usuario;
	}


};




class clase_preguntas{
public:
	//Aqui, cada matriz dispone de una serie de preguntas para cada nivel con sus respectas opciones
	//y su respectiva respuesta, de esta forma controlamos las preguntas recibidas por el usuario
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


	//
	int met_retirarseDelJuego(int nivel)
	{
		int opc_final = 0;
		int opc = 0;
		cout<<"Deseas retirarte del juego en el nivel "<<nivel<<" de tu partida actual?"<<endl;
		cout<<"Si-1  No-Cualquier numero"<<endl;
		cin>>opc;
		//--------------------------------------------------------------------------
		switch(opc)
		{
		case 1:
			opc_final = 1;
			break;

		default:
			opc_final = 0;
			break;

		}
		return opc_final;

	}

	int met_seleccionar_vector(int nivel_juego){
		srand(time(0)); // Inicializar la semilla de generación de números aleatorios
		int columna_aleatoria = rand() % 4 + 1; // Generar un número aleatorio del 1 al 4
		//creamos variables la pregunta y opcion
		string var_pregunta;
		string var_opcion1;
		string var_opcion2;
		string var_opcion3;
		string var_opcion4;
		string var_respuesta;
		//Con ayuda de switch y una variable entera, se asigna a cada variable antes creada
		//su valor correspondiente de la pregunta dada, que sera en este caso
		//designada por la variable aleatoria
		switch(nivel_juego){
		case 1:
			//actualizamos para variable de tipo string, con datos de la pregunta de la matris
			//correspondiente y asi logramos conseguir que no se repita siempre la misma pregunta
			//en cada nivel
			var_pregunta =matriz_Nivel1[columna_aleatoria][0];
			var_opcion1=matriz_Nivel1[columna_aleatoria][1];
			var_opcion2=matriz_Nivel1[columna_aleatoria][2];
			var_opcion3=matriz_Nivel1[columna_aleatoria][3];
			var_opcion4=matriz_Nivel1[columna_aleatoria][4];
			//con esta variable guardamos la respuesta que siempre se encuentra en el ultimo valor del
			//vector de cada pregunta
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
		//Aqui creamos un nuevo vector y le asignamos un espacio de 5, que son los elementos
		//base de cada pregunta en las matrices
		//asignado de forma ordenada cada opcion
		string vector_nivel[5];
		vector_nivel[0]= var_pregunta;
		vector_nivel[1]=var_opcion1;
		vector_nivel[2]=var_opcion2;
		vector_nivel[3]=var_opcion3;
		vector_nivel[4]= var_opcion4;
		//Imprimimos el vector por pantalla, es decir la pregunta que vera el usuario
		//siempre ignorando la posicion 5 que es el valor de la respuesta y se usa despues
		for (int i = 0; i < 5; i++) {
		        cout << vector_nivel[i] << std::endl;
		    }
		int respuesta_correcta_nivel = 0;
		//con ayuda de stoi convertimos la respuesta correcta correcta de un valor string
		//a un valor entero, el cual retornamos para luego validar la respuesta.
		respuesta_correcta_nivel = stoi(var_respuesta);

        return respuesta_correcta_nivel;
	};
};
//Con esta clase iniciamos el juego y instaciamos tods los metodos y clases necesarias para
//su debido funcionamiento
class clase_juego{
public:
	//El atr de nivel indispensable y sera el cual controle el nivel en que se encuentre el jugador
	int atr_nivel = 0;
	int respuesta_jugador;
	string vectorjugando[6];
	string atr_user;
	string atr_pass;
	vector <float> atr_saldo_usuario;
	//atributo que guarda temporalmente el usuario



	////////////////////////////////////METODO PROCESO PREGUNTAS//////////////////////////////////
	float met_proceso_preguntas(int atr_nivel, bool validacion_respuestas,float saldo_jugado, bool validacion_saldo_ganado, float saldo_ganado)
	{
		int opc_retirarse = 0;

		clase_preguntas pregunta;
		clase_login login;
		clase_validaciones valida;
		clase_calculos calculos;

		int respuesta_correcta = 0;

		while(atr_nivel < 11){

			respuesta_correcta = pregunta.met_seleccionar_vector(atr_nivel);
		    cin>>respuesta_jugador;
		    validacion_respuestas = valida.met_validarRespuesPregunta(respuesta_jugador, respuesta_correcta);
		    ////////VALIDAR RESPUESTA////////////////
		    if(validacion_respuestas == false){
		    	//Si la respuesta es incorrecta el valor del nivel toma uno mayor al cierra el ciclo
		    	//y le da un valor de 0 al saldo ganado!!
		    	atr_nivel = 20;
		    	cout<<"Respuesta incorrecta!!!!!   :("<<endl;
		    	cout<<"-"<< saldo_jugado << endl;
		    	saldo_ganado = 0;
		    }
		    else{
		    	//Respuesta correcta envia un mensaje con dicho mensaje y le suma a saldo ganado un porcentaje
		    	//de 10% de su valor jugado al saldo que va a ganar, este ciclo se repite en cada respuesta
		    	//correcta!!
		    	cout<<"Respuesta correcta!!!!!     :D"<<endl;
		    	saldo_ganado += calculos.met_calcularPorcentajeporPregunta(saldo_jugado);
		    }
		    /////////FIN VALIDAR RESPUESTA//////////////////
		    /////////INICIO VALIDAR EL NIVEL PARA RETIRARSE DEL JUEGO/////////

		    if (atr_nivel == 3){
		    	//Aqui le preguntamos al usuaurio si desea reitirararse del juego
		    	//el valor dado se evalua abajo
		    	opc_retirarse = pregunta.met_retirarseDelJuego(atr_nivel);

		    	if (opc_retirarse == 1){
		    		//si la opcion es si, al saldo ganado se le suma el saldo jugado + el 25%
		    		//del saldo ganado hasta ese momento
		    		saldo_ganado = saldo_jugado +calculos.met_calcularPorcentajeRetirarse(saldo_ganado, atr_nivel);
		    		//Con esta variable rompemos el ciclo!!
		    		atr_nivel = 20;
		    	}


		    }
		    if (atr_nivel == 6){
		    	opc_retirarse = pregunta.met_retirarseDelJuego(atr_nivel);
		    	if (opc_retirarse == 1){
		    		//si la opcion es si, al saldo ganado se le suma el saldo jugado + el 50%
		    		//del saldo ganado hasta ese momento
		    		saldo_ganado = saldo_jugado +calculos.met_calcularPorcentajeRetirarse(saldo_ganado, atr_nivel);
		    		//Con esta variable rompemos el ciclo!!
		    		atr_nivel = 20;
		    			    	}

		    };

		    if(atr_nivel == 9){
		    	opc_retirarse = pregunta.met_retirarseDelJuego(atr_nivel);
		    	if (opc_retirarse == 1){
		    		//si la opcion es si, al saldo ganado se le suma el saldo jugado + el 75%
		    		//del saldo ganado hasta ese momento
		    		saldo_ganado = saldo_jugado +calculos.met_calcularPorcentajeRetirarse(saldo_ganado, atr_nivel);
		    		//Con esta variable rompemos el ciclo!!
		    		atr_nivel = 20;
		    			    	}

		    }
		    //a la variable atr nivel, se le suma 1 por cada ciclo asi aumentando el nivel
		    //y dificiltad de la pregunta al usuairo
		    atr_nivel = atr_nivel + 1;
		};
		//retornamos el valor ganado!!
		return saldo_ganado;
	}
	////////////////////////////////////FIN METODO PROCESO PREGUNTAS//////////////////////////////////
	void juego(){
		///////////////Variables usadas en el codigo, inicialidas en 0 o valores falsos///////
		bool i = true;
		bool j = true;


		int val_posicion_usuario=0;


		float saldo_usuario = 0;
		float saldo_ganado = 0;
		float saldo_jugado = 0;
		float saldo_nuevo_ingresar = 0;
		float saldo_para_retirar_del_juego = 0;
		float saldo_mostrar_saldo_ganado = 0;

		bool validacion_saldo_ganado = false;
		bool validacion_respuestas = false ;
		bool validacion_saldo_nuevo_ingresar = false;
		bool validacion_saldo_para_retirar = false;
		bool validacion_saldo_jugar_partida = false;
		bool validacion_verificar_saldo_jugado = false;

		///Intanciamos las clases usadas en el juego para su debido funcionamiento!!
		clase_juego metodos_juego;
		clase_preguntas pregunta;
		clase_login login;
		clase_menus menus;
		clase_validaciones valida;

		int opc_retirar_saldo = 0;
		int opc_principal = 0;
		int opc_inicial = 0;
		int opc_ingresar_saldo = 0;

		//Usuarios para probar el programa!!
		login.met_crear_jugador("admin","admin");
		atr_saldo_usuario.push_back(0);

		while(i == true){
			//iniciamos el programa con el primer menu!!
			menus.met_menuIngreso();
			cin>>opc_principal;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			switch(opc_principal){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1:
				//Inicio de usuario pedido por cmd!!
				cout << "Ingrese su nombre de usuario" << endl;
				cin >> atr_user;
				cout << "Ingrese contraseña" << endl;
				cin >> atr_pass;

				//la variable j que es bool, le damos el valor que retorne iniciar seccion
				//para luego usarla al ingresar al programa
				j = login.met_iniciar_seccion(atr_user, atr_pass);
				//con esta variable buscamos encontrar la posicion del usuario
				//esto nos ayudara a darle un saldo a dicho usuario y mantenerlo
				//aunque dedida cerrar seccion!!
				//diferente usuario diferentes saldo del dicho usuario
				val_posicion_usuario = login.met_posicion_usuario(atr_user);
				//Aqui asignamos el valor del saldo_usuario a la posicion del jugador
				saldo_usuario = atr_saldo_usuario[val_posicion_usuario];
				//si el valor retorna falso se mostrara el mensaje y se devolvera al menu!
				if(j == false){
					cout<<"Usuario no registrado"<<endl;
				}
				while(j == true){
					//mostramos el menu inicial, el menu del juego
					menus.met_menuInicial();
					cin>>opc_inicial;
					switch(opc_inicial){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 1:
						atr_nivel = 1;
						//Le damos unas pequeñas intrucciones del juego al usuario
						//mientras el inicia el valor a jugar!!
						cout<<"-------------------INSTRUCCIONES----------------------------------------------------------------"<<endl;
						cout<<"El saldo minimo es de 10000 para iniciar el juego!!!!"<<endl;
						cout<<"Una respuesta incorrecta sera el fin del juego"<<endl;
						cout<<"en los niveles 3,6 y 9, son comodines para retirarte del juego, usalos bien"<<endl;
						cout<<"cualquier dato ingresado de forma erronea, finaliza la partidad"<<endl;
						cout<<"Buena suerte y disfruta el juego!!"<<endl;
						cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
						cout<<"Cuando dinero deseas jugar?"<<endl;
						cin>>saldo_jugado;
						//usando el metodo de validar, validamos aqui que el saldo jugado sea
						//menor al saldo del usuario
						validacion_verificar_saldo_jugado = valida.met_validarSaldoParajugar(saldo_jugado, saldo_usuario);
						if(validacion_verificar_saldo_jugado == true)
						{
							//luego validamos que el saldo sea mayor a 10000 que el monto minimo por partida!!
							validacion_saldo_jugar_partida = valida.met_validarSaldoParapartida(saldo_jugado);

							if(validacion_saldo_jugar_partida==true)
							{
								//el saldo jugado se lo descontamos al saldo usuario una ves iniciado el juego
								saldo_usuario = saldo_usuario - saldo_jugado;
								//aqui mostramos el metodo de las preguntas que retorna un valor fool hacia la variable
								//de saldo_usuario
								saldo_usuario = saldo_usuario + metodos_juego.met_proceso_preguntas(atr_nivel, validacion_respuestas, saldo_jugado, validacion_saldo_ganado, saldo_ganado);
								saldo_mostrar_saldo_ganado = saldo_usuario-saldo_jugado;
								//aqui solo mostramos el saldo ganado, quitando el salado jugado
								cout<<"Tu saldo ganado fue "<<saldo_mostrar_saldo_ganado<<endl;

							} else {
								cout<<"SALDO INCORRECTO"<<endl;

							}
						} else {
							cout<<"SALDO INCORRECTO"<<endl;
						}
						break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////INGRESAR SALDO///////////////////////////////////////////////////////////////////////////
					case 2:
						cout<<"Desea ingresar saldo a su cuenta?"<<endl;
						cout<<"Si-1 No-Cualquier otro numero"<<endl;
						cin>>opc_ingresar_saldo;
						switch(opc_ingresar_saldo)
						{


						case 1:
							cout<<"Cuanto dinero desea ingresar?"<<endl;
							cin>>saldo_nuevo_ingresar;

							validacion_saldo_nuevo_ingresar = valida.met_validarSaldoIngresado(saldo_nuevo_ingresar);

							if(validacion_saldo_nuevo_ingresar == true)

							{
								saldo_usuario = saldo_usuario+saldo_nuevo_ingresar;
								break;
							} else {
								cout<<"La transferencia no se pudo realizar..."<<endl;
								break;
							}

						}
						continue;
////////////////////////////////////FIN INGRESAR SALDO///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 3:
						cout<<"Desea retirar saldo de su cuenta?"<<endl;
						cout<<"Si-1 No-Cualquier otro numero"<<endl;
						cin>>opc_retirar_saldo;
						switch(opc_retirar_saldo)
						{

						case 1:
							cout<<"Cuanto dinero desea retirar?"<<endl;
							cin>>saldo_para_retirar_del_juego;

							validacion_saldo_para_retirar = valida.met_validarRetirarSaldo(saldo_para_retirar_del_juego, saldo_usuario);
							if(validacion_saldo_para_retirar==true)
							{
								saldo_usuario = saldo_usuario-saldo_para_retirar_del_juego;
								break;
							} else {
								cout<<"La transferencia no se pudo realizar..."<<endl;
								break;
							}

						}


						cout<<"retirar saldo"<<endl;
						continue;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 4:
						cout<<"El saldo actual de tu cuenta es"<<endl;
						cout<<saldo_usuario<<endl;
						continue;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

					case 0:
						atr_saldo_usuario[val_posicion_usuario] = saldo_usuario;
						j = false;
						cout<<"sesion cerrada con exito"<<endl;
						continue;
					default:
						cout<<"Dato ingresado incorrecto"<<endl;
						break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					}
///////////////////CIERA EL SWITCH SECUNDARIO////////////////////////////////////////////////////////////////////////////////////////////
				};
/////////////////////CIERRA EL WHILE SECUNDARIO//////////////////////////////////////////////////////////////////////////////////////////
				break;
////////////////////////BREAK CASO 1///////////////////////////////////////////////////////////////////////////////////////
			case 2:
				cout<<"Ingrese su nombre de usuario"<<endl;
				cin>>atr_user;
				cout<<"Ingrese contraseña"<<endl;
				cin>>atr_pass;
				//con ayuda del metodo crear jugador y un vector en dicha clase, creamos un usaurio
				//aqui tambien le asignamos un valor inicial al vector saldo usuario de 0
				login.met_crear_jugador(atr_user, atr_pass);
				atr_saldo_usuario.push_back(0);
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
	//En el main solo disponemos de la clase juego y el metodo iniciar para comenzar el juego
	clase_juego iniciar;
	iniciar.juego();
	return 0;
}
