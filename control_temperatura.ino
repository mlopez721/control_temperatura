/*
Control de temperatura para impresoras 3D. 

Este proyecto está pensado para controlar la temperatura de la cama caliente y el extrusor de impresión de una impresora de tipo ANET A8, 
pero se puede adaptar a cualquier otro tipo de impresora.

La idea es definir los parámetros máximos de temperatura y en caso de que se superen, cortar la corriente de alimentación del extrusor o la cama caliente.

Base:
	Arduino UNO
	Extra: NodeMCU con conexión a internet

Entrada:
	Sensor para cama: máximo 100º
	Sensor para extrusor: más de 220º

	Extra: Sensores para las placas electrónicas, y evitar sobrecalentamientos
	Extra: Sensores para los relés de control de las resistencias

Salida:
	Alarma acústica
	Relé que corte la alimentación correspondiente a la resistencia del extrusor
	Relé que corte la alimentación correspondiente a la resistencia de la cama
	LCD con info de la Tª actual y máxima para extrusor y cama

	Extra: Aviso mediante Telegram o similar
	Extra: Que avise por incremento de Tª
	Extra: Que avise en caso de que salte la alarma
	
*/

// definir parámetros  

// Pines entrada
const int pinSensorCama		= 9;	// ToDo: verificar
const int pinSensorExtrusor = 10;	// ToDo: verificar

// Pines salida
const int pinReleCama		= 11;	// ToDo: verificar
const int pinReleExtrusor	= 12;	// ToDo: verificar

// temperaturas máximas expresadas en grados centígrados
int tempMaxCama		= 60;
int tempMaxExtrusor = 220;

int tempCamaActual		= 0;
int tempExtrusorActual	= 0;

// parámetro que guarda el estado de la alarma
boolean alarmaActivada = false;
 
void setup() {
	// definimos los pines de los sensores como de entrada
	pinMode(pinSensorCama, INPUT);
	pinMode(pinSensorExtrusor, INPUT);

	// definimos los pines de los relés como de salida
	pinMode(pinReleCama, OUTPUT);
	pinMode(pinReleExtrusor, OUTPUT);

	// activamos los reles para que suministren corriente a las resistencias
	activarReleCama();
	activarReleExtrusor();
}

void loop() {
  
	// leer sensor cama
	tempCamaActual = leerSensorCama();

	// si la temperatura es superior a la marcada
	if (tempCamaActual >= tempMaxCama) {
		// desactivar rele cama
		desactivarReleCama();
		// activar la alarma
		alarmaActivada = true;
	}

	// leer sensor extrusor
	tempExtrusorActual = leerSensorExtrusor();
	// si la temperatura es superior a la marcada
	if(tempExtrusorActual >= tempMaxExtrusor){
		// desactivar rele cama
		desactivarReleExtrusor();
		// activar la alarma
		alarmaActivada = true;
	}

}

// Relé cama
void activarReleCama(){
	digitalWrite(pinReleCama, HIGH);
}

void desactivarReleCama() {
	digitalWrite(pinReleCama, LOW);
}

// Relé extrusor
void activarReleExtrusor() {
	digitalWrite(pinReleExtrusor, HIGH);
}

void desactivarReleExtrusor() {
	digitalWrite(pinReleExtrusor, LOW);
}

int leerSensorCama() {
	// leer y convertir los datos a grados centígrados

	// devolver la lectura del sensor

}

int leerSensorExtrusor() {
	// leer y convertir los datos a grados centígrados

	// devolver la lectura del sensor

}
