#include <fstream>
#include <iostream>
#include <string>


using namespace std;


void actividadUnoEscritura();
void actividadUnoLectura();
void repeticion();


char respuesta;
bool repetir;

class Empleado {
private:
	string m_nombre;
	string m_apellido;
	string m_edad;
	string m_salario;
public:
	Empleado(string nombre, string apellido, string edad, string salario)
		: m_nombre(nombre), m_apellido(apellido), m_edad(edad), m_salario(salario) {}

	void mostrarInfo() const {
		cout << "Nombre: " << m_nombre << endl;
		cout << "Apellido: " << m_apellido << endl;
		cout << "Edad: " << m_edad << endl;
		cout << "Salario: " << m_salario << endl;
	}

	void enviarArchivo() {
		ofstream archivo("C:/Users/pseba/Desktop/SegundoParcial/empleados.txt", ios::app);
		if (!archivo) {
			cout << "No se pudo abrir el archivo";
			return;
		}

		archivo << "Nombre: " << m_nombre << endl;
		archivo << "Apellido: " << m_apellido << endl;
		archivo << "Edad: " << m_edad << endl;
		archivo << "Salario: " << m_salario << endl << endl;

		archivo.close();

		cout << "Se ha guardado exitosamente los datos";
		system("pause");

	}
};

void consulta() {
	ifstream archivo("C:/Users/pseba/Desktop/SegundoParcial/empleados.txt");
	string texto, nombre;
	
	cout << "Ingrese nombre: ";
	cin >> nombre;

	while (!archivo.eof()) {
		getline(archivo, texto);
		if (texto == nombre) {
			cout << "Se ha encontrado un trabajor con ese nombre, haz una lectura al archivo para confirmar";
			return;
		}
	}
	cout << "No se ha encontrado a ningun trabajador";
}


void actividadUnoEscritura() {
	int n;
	string nombre;
	string apellido;
	string edad;
	string salario;


	cout << "Ingrese la cantidad de empleados que desea ingresar: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "\tDatos empleado #" << i + 1 << endl << endl;
		cout << "Ingrese unicamente los nombres: ";
		getline(cin, nombre);

		cout << "Ingrese el apellido: ";
		getline(cin, apellido);

		cout << "Ingrese la edad: ";
		getline(cin, edad);

		cout << "Ingrese el salario: ";
		getline(cin, salario);

		//cin.ignore();
		Empleado empleado1(nombre, apellido, edad, salario);

		empleado1.enviarArchivo();

	}
}

void actividadUnoLectura() {
	ifstream archivo("C:/Users/pseba/Desktop/SegundoParcial/empleados.txt");
	string texto;

	if (!archivo) {
		cout << "No se pudo abrir el archivo";
		system("pause");
		return;
	}

	while (!archivo.eof()) {
		getline(archivo, texto);
		cout << texto << endl;
	}
	system("pause");
}


int main() {

	do {
		system("cls");
		int opcion;
		cout << "\tMenu:\n\n";
		cout << "1. Registrar trabajadores\n";
		cout << "2. Leer archivo\n";
		cout << "3. Consulta\n";
		cout << "4. Salir del menu\n\n";
		cout << "Opcion a elegir: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			actividadUnoEscritura();
			repeticion();
			break;
		case 2:
			actividadUnoLectura();
			repeticion();
			break;
		case 3:
			consulta();
			break;
		case 4:
			repetir = false;
		default:
			repetir = true;
		}
	} while (repetir == true);


	return 0;
}

void repeticion() {
	do {
		system("cls");
		cout << "Desea regresar al menu? S/N: ";
		cin >> respuesta;
	} while (respuesta != 'n' and respuesta != 'N' and respuesta != 'S' and respuesta != 's');

	if (respuesta == 's' or respuesta == 'S') {
		repetir = true;
	}
	else if (respuesta == 'n' or respuesta == 'N') {
		repetir = false;
	}
}
