#include <helper_3dmath.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>


const int mpuAddress = 0x68;  //Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);
int16_t ax, ay, az;
int16_t gx, gy, gz;

void printTab()
{
   Serial.print(F("\t"));
}
void printRAW()
{
   Serial.print(F("a[x y z] g[x y z]:t"));
   Serial.print(ax); printTab();
   Serial.print(ay); printTab();
   Serial.print(az); printTab();
   Serial.print(gx); printTab();
   Serial.print(gy); printTab();
   Serial.println(gz);
}
void setup()
{
   Serial.begin(9600);
   Wire.begin(4,5);
   mpu.initialize();
   Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
}
void loop()
{
   // Leer las aceleraciones y velocidades angulares
   mpu.getAcceleration(&ax, &ay, &az);
   mpu.getRotation(&gx, &gy, &gz);
   printRAW();
   
   delay(100);
}
