#include <Wire.h>               
#include "HT_SSD1306Wire.h"

SSD1306Wire  display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr, freq, i2c group, resolution, rst

int counter = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  VextON();
  delay(100);

  // Inicializar el display
  display.init();

  // Establecer la fuente que usaremos
  display.setFont(ArialMT_Plain_10);
}

void VextON(void) {
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
}

void loop() {
  // Limpiar la pantalla
  display.clear();
  
  // Mostrar el texto en la parte superior
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Enviando paquetes:");
  
  // Cambiar la fuente para el contador
  display.setFont(ArialMT_Plain_24);
  
  // Mostrar el valor del contador más abajo
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(display.width()/2, display.height()/2 - 12, String(counter));

  // Actualizar el display
  display.display();

  // Incrementar el contador
  counter++;

  // Esperar un segundo antes de actualizar el valor
  delay(1000);
}

