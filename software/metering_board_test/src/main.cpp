#include <Arduino.h>
#include <SPI.h>
#include <ATM90E32.h>


ATM90E32 energy_meter1{};
ATM90E32 energy_meter2{};


void setup() {
 Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

    const int CS_0_pin = 5;
    const int CS_1_pin = 4;

    const int lineFreq = 4231;
    const int pga_gain = 0;
    const int VoltageGain = 7305;
    const int CurrentGain = 27961;
    energy_meter1.begin(CS_0_pin, lineFreq, pga_gain, VoltageGain, CurrentGain, CurrentGain, CurrentGain);
    energy_meter2.begin(CS_1_pin, lineFreq, pga_gain, VoltageGain, CurrentGain, CurrentGain, CurrentGain);

 }

void loop() {
  // put your main code here, to run repeatedly:

  while (1) {
    double voltage1 = energy_meter1.GetLineVoltageA();
    double voltage1v2 = energy_meter1.GetLineVoltageA();
    double voltage2 = energy_meter1.GetLineVoltageB();
    double voltage3 = energy_meter1.GetLineVoltageC();
    Serial.printf("[1] U1: %6.2f %6.2f V  U2: %6.2f V  U3: %6.2f V\n", voltage1, voltage1v2, voltage2, voltage3);
  
    voltage1 = energy_meter2.GetLineVoltageA();
    voltage2 = energy_meter2.GetLineVoltageB();
    voltage3 = energy_meter2.GetLineVoltageC();
    Serial.printf("[2] U1: %6.2f V  U2: %6.2f V  U3: %6.2f V\n", voltage1, voltage2, voltage3);


    Serial.printf("[1] TEMP: %7.2f\n", energy_meter1.GetTemperature());
    Serial.printf("[2] TEMP: %7.2f\n", energy_meter2.GetTemperature());

#if 0
    double CT1 = energy_meter.GetLineCurrentA();
    double CT2 = energy_meter.GetLineCurrentB();
    double CT3 = energy_meter.GetLineCurrentC();
    Serial.printf("I1: %6.2f V  I2: %6.2f V  I3: %6.2f V\n", CT1, CT2, CT3);
    
    double watts1 = energy_meter.GetActivePowerA();
    double watts2 = energy_meter.GetActivePowerB();
    double watts3 = energy_meter.GetActivePowerC();
    Serial.printf("P1: %6.2f W  P2: %6.2f W  P3: %6.2f W\n", watts1, watts2, watts3);
    //double totalWatts = energy_meter.GetTotalActivePower();
#endif
    Serial.printf("---\n");

    delay(1000);
  }

}