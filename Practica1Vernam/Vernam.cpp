// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Seguridad en Sistemas Informáticos
// Curso: 3º
// Práctica 1 Cifrado de Vernam
// Autor: María Candelaria Fariña Rodríguez
// Correo: alu0101029801@ull.edu.es
// Fecha: 11/02/2020
// Archivo: Vernam.cpp
// Referencias:
// 		Enunciado de la práctica
//
#include "Funciones.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main(void) {
  
	string message, cipher, key;             // Mensaje original, mensaje cifrado y clave
	vector<int> ascii;			    // Vector en el que cada celda tiene valor en ascii de cada letra del mensaje introducido
	vector<string> binary;	    // Vector que contiene en cada celda el equivalente en binario al valor ascii previo
	string message_binary;				  // Mensaje original en binario
  
	string tmp;						        // Temporal usado para mover datos
	vector<string> split_cipher;     // Vector con el mensaje cifrado en binario y separado
	vector<int> ascii_cipher;			  // Vector en el que está el equivalente ascii del mensaje cifrada en binario
	string cipher_character;				    // String que contiene el mensaje cifrado representado con caracteres

	/*Para descifrar uso el cifrado de Vernam nuevamente, luego ese número binario lo paso a la tabla ascii y de ascii a caracteres del alfabeto */
  
	string decipher, decipher_character;    // Mensaje cifrado y mensaje descifrado
	vector<string> split_decipher;       // Vector con el mensaje descifrado en binario y separado
	vector<int> ascii_decipher;        // Vector en el que está el equivalente ascii del mensaje cifrada en binario

	int option;

	cout << "Introduzca una opcion:" << endl;
	cout << "0. Salir del programa" << endl;
	cout << "1. Insertar un mensaje de longitud 2" << endl;
	cout << "2. Insertar un mensaje de longitud 3" << endl;
	cin >> option;
	cout << endl;

	
	switch (option) {
	    case 0:
		        cout << "Saliendo del programa." << endl;
		        break;
	
      case 1:
      
            cout << "Introduzca el mensaje a cifrar:" << endl;
	          cin >> message;
            cout << endl;
           
            cout << "Introduzca la clave:" << endl;
            cin >> key;
            cout << endl;
      
            ascii = StringToAscii(message);  	// Meto dentro de este vector cada el valor en ascii de la cada letra de la frase
          	binary = AsciiToBinary(ascii); 	// Meto dentro de este vector un string con el valor en binario del valor ascii

	/* Con esto de aqui accedemos a cada uno de los strings del vector y los metemos dentro de otro string, lo uso para luego poder hacer la operacion XOR más comodamente */
          	for (int i = 0; i < binary.size(); ++i) {
	              tmp = binary[i];
		            for (int j = 0; j < tmp.size(); ++j) {
			              message_binary.push_back(tmp.at(j));
		            }
            }
      
		        cipher = Vernam(message_binary, key);			// Aqui ya tenemos la frase en binario cifrada
            
            split_cipher = Split(cipher);					// Aqui separo otra vez la cadena binaria cifrada en grupos de 8 bits, es para poder trabajar mejor
		        ascii_cipher = BinaryToAscii(split_cipher);  	// Paso de binario a ascii
		        cipher_character = AsciiToString(ascii_cipher); 	// Paso de valor ascii a su simbolo
      
		        decipher = Vernam(cipher, key);				  // Descifro volviendo a realizar la operacion XOR
		       
            
            split_decipher = Split(decipher);			  	  // Lo separo dentro de un vector de strings
		        
            ascii_decipher = BinaryToAscii(split_decipher);  	  // Paso los valores del los strings a ascii
		        
            decipher_character = AsciiToString(ascii_decipher);	  // Paso de valor ascii a caracter

		   	    cout << "Mensaje original: " << message << endl;
		        cout << "Mensaje original en binario: " << message_binary << endl;
		        cout << "Tamaño de la frase en binario: " << message_binary.size() << endl;
		        cout << "Clave Aleatoria: " << key << endl;
		        cout << "Mensaje Cifrado en Binario: " << cipher << endl;
		        cout << "Mensaje Cifrado: " << cipher_character << endl;
		        cout << "Mensaje Descifrado: " << decipher_character << endl;
		        break;

	    case 2:

            cout << "Introduzca el mensaje a cifrar: " << endl;
	          cin >> message;
            cout << endl;
      
            cout << "Introduzca la clave:" << endl;
            cin >> key;
            cout << endl;
      
            ascii = StringToAscii(message);  	// Meto dentro de este vector cada valor en ascii de cada letra del mensaje
	          
            binary = AsciiToBinary(ascii); 	// Meto dentro de este vector un string con el valor en binario del valor ascii

	          /* Accedo a cada uno de los strings del vector y los metemos dentro de otro string, lo uso poder hacer la operacion XOR */
	          for (int i = 0; i < binary.size(); ++i) {
	              tmp = binary[i];
		            
                for (int j = 0; j < tmp.size(); ++j) {
			              message_binary.push_back(tmp.at(j));
		            }
            }
		        
            cipher = Vernam(message_binary, key);			// Aqui ya tenemos la frase en binario cifrada
		        split_cipher = Split(cipher);					// Aqui separo otra vez la cadena binaria cifrada en grupos de 8 bits, es para poder trabajar mejor
		        ascii_cipher = BinaryToAscii(split_cipher);  	// Paso de binario a ascii
		        cipher_character = AsciiToString(ascii_cipher); 	// Paso de valor ascii a su simbolo

		        decipher = Vernam(cipher, key);			  	// Descifro volviendo a realizar la operacion XOR
		        split_decipher = Split(decipher);			  	// Lo separo dentro de un vector de strings
		        ascii_decipher = BinaryToAscii(split_decipher);  	// Paso los valores del los strings a ascii
		        decipher_character = AsciiToString(ascii_decipher); 	// Paso de valor ascii a caracter

		        cout << "Mensaje original: " << message << endl;
		        cout << "Mensaje original en binario: " << message_binary << endl;
		        cout << "Tamaño de la frase en binario: " << message_binary.size() << endl;
		        cout << "Clave Aleatoria: " << key << endl;
		        cout << "Mensaje Cifrado en Binario: " << cipher << endl;
		        cout << "Mensaje Cifrado: " << cipher_character << endl;
		        cout << "Mensaje Descifrado: " << decipher_character << endl;
		        break;

	    default:
		    
	   		    cout << "Valor no válido." << endl;
		        break;
    	}
}