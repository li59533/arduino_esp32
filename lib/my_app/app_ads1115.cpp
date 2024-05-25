
#include "app_ads1115.h"
#include <Wire.h>
#include "Adafruit_ADS1X15.h"

#define IIC2_SDA  18
#define IIC2_SCL  16

#define ADS_COUNT 1 


static void ADS_request_all() ;

Adafruit_ADS1115 ads;     /* Use this for the 12-bit version */



void App_ads1115_init(void)
{
    Wire1.begin(IIC2_SDA, IIC2_SCL, 100000);   /* 初始化IIC连接 */

    if (!ads.begin(0x48 , &Wire1)) {
    Serial.println("Failed to initialize ADS.");
    while (1);
    }

}








void App_ads1115_test_process(void)
{
  int16_t adc0, adc1, adc2, adc3;
  float volts0, volts1, volts2, volts3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  volts0 = ads.computeVolts(adc0);
  volts1 = ads.computeVolts(adc1);
  volts2 = ads.computeVolts(adc2);
  volts3 = ads.computeVolts(adc3);

  Serial.println("-----------------------------------------------------------");
  Serial.print("AIN0: "); Serial.print(adc0); Serial.print("  "); Serial.print(volts0); Serial.println("V");
  Serial.print("AIN1: "); Serial.print(adc1); Serial.print("  "); Serial.print(volts1); Serial.println("V");
  Serial.print("AIN2: "); Serial.print(adc2); Serial.print("  "); Serial.print(volts2); Serial.println("V");
  Serial.print("AIN3: "); Serial.print(adc3); Serial.print("  "); Serial.print(volts3); Serial.println("V");

  delay(1000);
}




