#include <Esplora.h> // Incluye la biblioteca Esplora para manejar los componentes del Arduino Esplora

// Definimos el tamaño de la figura
const int size = 20;
int x = 64; // Posición inicial en X (en el centro de la pantalla)
int y = 32; // Posición inicial en Y (en el centro de la pantalla)

void setup() {
  // Inicializa la pantalla LCD
  EsploraLCD.begin();
  EsploraLCD.setCursor(0, 0);
}

void loop() {
  // Limpiar la pantalla
  EsploraLCD.clear();

  // Leer el estado de los interruptores
  int leftSwitch = Esplora.readSwitch(Esplora.LEFT);
  int rightSwitch = Esplora.readSwitch(Esplora.RIGHT);
  int upSwitch = Esplora.readSwitch(Esplora.UP);
  int downSwitch = Esplora.readSwitch(Esplora.DOWN);

  // Actualizar la posición de la figura basada en el estado de los interruptores
  if (leftSwitch == HIGH && x > 0) {
    x -= 2; // Mueve la figura a la izquierda
  }
  if (rightSwitch == HIGH && x < 128 - size) {
    x += 2; // Mueve la figura a la derecha
  }
  if (upSwitch == HIGH && y > 0) {
    y -= 2; // Mueve la figura hacia arriba
  }
  if (downSwitch == HIGH && y < 64 - size) {
    y += 2; // Mueve la figura hacia abajo
  }

  // Dibuja el cuadrado en la nueva posición
  EsploraLCD.fillRect(x, y, size, size, WHITE);

  // Pequeña pausa para hacer el movimiento más visible
  delay(50);
}
