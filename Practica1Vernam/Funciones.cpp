// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Seguridad en Sistemas Informáticos
// Curso: 3º
// Práctica 1 Cifrado de Vernam
// Autor: María Candelaria Fariña Rodríguez
// Correo: alu0101029801@ull.edu.es
// Fecha: 11/02/2020
// Archivo: Funciones.cpp
// Referencias:
// 		Enunciado de la práctica
//
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

// Pasa cada letra de una cadena a su número equivalente en código ascii y lo mete dentro de un vector
vector<int> StringToAscii(string message) {
  
	vector<int> ascii;

	for (int i = 0; i < message.size(); i++) {
		ascii.push_back((int)message[i]);
	}
	return ascii;
}

// Convierte cada número ascii a su equivalente en binario en 8 bits
vector<string> AsciiToBinary(vector<int> ascii) {  
	
  	vector<string> binary;
	
  	for (int i = 0; i < ascii.size(); ++i) {
		string aux;
		aux = bitset<8>(ascii[i]).to_string();     // Lo que devuelva el constructor lo pasa a caracteres
		binary.push_back(aux);
	}
	
  	return binary;
}

// Pasa de binario a su equivalente número en la tabla ascii
vector<int> BinaryToAscii(vector<string> binary) { 
	
 	vector<int> ascii;
	
  	for (int i = 0; i < binary.size(); i++) {
		int entero;
		string bin = binary[i];
		bitset<8> num(bin);
		entero = (int)num.to_ulong();   // Con esto lo pasamos a un numero entero
		ascii.push_back(entero);
	}
	
  	return ascii;
}


// Convierte números de la tabla ascii a sus equivalentes carácteres
string AsciiToString(vector<int> bin_ascii){       // Se usa para el descifrado
	string message;
	
  	for (int i = 0; i < bin_ascii.size(); i++) {
		char W = static_cast<char>(bin_ascii[i]); // Transformamos un tipo de dato en otro, aqui de int a char.
		message.push_back(W);
	}
	
 	return message;
}

// Divide el número binario en tres partes iguales.
vector<string> Split(string binary) {

	string tmp1, tmp2, tmp3;
	vector<string> splitted;

	if (binary.size() == 24) {

		tmp1 = binary.substr(0, 8);
		splitted.push_back(tmp1);
		tmp2 = binary.substr(8, 8);
		splitted.push_back(tmp2);
		tmp3 = binary.substr(16, 8);
		splitted.push_back(tmp3);
	}
	
    	else if (binary.size() == 16) {

		tmp1 = binary.substr(0, 8);
		splitted.push_back(tmp1);
		tmp2 = binary.substr(8, 8);
		splitted.push_back(tmp2);
	}
	return splitted;
}

// Cifrado de Vernam. Consiste en operar bit a bit, mediante la operación XOR entre el mensaje y la key (clave).
string Vernam(string message, string key) {
	
	string cipher;
	if (message.size() != key.size()) {

		cout << "Los tamaños son distintos y no se puede cifrar." << endl;
  	}
  	else {
		for (int i = 0; i < message.size(); i++) {
			if (message[i] == key[i])
				cipher.push_back('0');
			else
				cipher.push_back('1');
		}
	}
	return cipher;
}
