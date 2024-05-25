#include "app_dac8411.h"
#include "SPI.h"

#include "DAC8551.h"

#define CUR_DAC_SCK_PIN 12
#define CUR_DAC_MISO_PIN 13
#define CUR_DAC_MOSI_PIN 11
#define CUR_DAC_CS_PIN  37

// DAC8551 mydac(46, &SPI);  //  explicit SPI

 SPIClass spi_cur_dac;
//SPIClass * spi_cur_dac = new SPIClass(FSPI);  //  HSPI

// uint8_t select, uint8_t spiData, uint8_t spiClock
 
// DAC8551  mydac(CUR_DAC_CS_PIN , &spi_cur_dac);
DAC8551  mydac(CUR_DAC_CS_PIN , &spi_cur_dac);

void App_dac8411_init(void)
{
        /* 设置SD卡的SPI用到的引脚 */ 
    // spi_cur_dac.setClockDivider(SPI_CLOCK_DIV16);
    // spi_cur_dac.setBitOrder(SPI_MSBFIRST);
    // spi_cur_dac.setDataMode(SPI_MODE1);
    spi_cur_dac.begin(CUR_DAC_SCK_PIN, CUR_DAC_MISO_PIN, CUR_DAC_MOSI_PIN, CUR_DAC_CS_PIN);
    spi_cur_dac.setFrequency(10000000);
    //spiAttachSS(spi_cur_dac->bus() , 0 ,CUR_DAC_CS_PIN); 
    //pinMode(CUR_DAC_CS_PIN, OUTPUT);                 /* 片选引脚设置为输出 */
 
    mydac.begin();
    // mydac.setSPIspeed(20000000);
}


void App_dac8411_test_process(void)
{
    uint16_t val = 55535;
    //  minimal sawtooth
    while(1)
    {

        val += 1000;

        if (val > 60535)
        {
            val = 0;
            /* code */
        }
        

        mydac.setValue(val);
        //int av = analogRead(A0);

        Serial.print(val);
        //Serial.print("\t ==> \t");
        //Serial.print(av);

        delay(500);

    }

}
