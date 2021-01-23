//****Functions***
//  SR04_read();
//  mlx_read();
//  buzz_1sec();
//  buzz_5sec();
//

#include <Adafruit_MLX90614.h>

#define buzzer D5
#define camTrigger D4

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

double ambientTemp,objectTemp,mlx_avg=0, temperature = 0;
float spo2=0, hrv=0, hb=29, oxi_temp=0, hb_time = 0;

void buzz_1sec(void) {
 digitalWrite(buzzer,HIGH);
 delay(150);
 digitalWrite(buzzer,LOW);
}

void buzz_5sec(void) {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(5000);        // ...for 1 sec
  noTone(buzzer);
}

double read_avg(double value1) {
  double avg = 0;
  for(int i=5;i>=0;i--){
    avg = (value1 + avg);
  }
  return avg/5;
}

double mlx_read(void) {
    ambientTemp = mlx.readAmbientTempC();
    objectTemp = read_avg(mlx.readObjectTempC());
    objectTemp=objectTemp-5.5;
//  if(objectTemp<37.7){
//   display_okay(String(objectTemp,1)); 
//  }
//  else if(objectTemp>37.7 && objectTemp<120)
//  {
//   //display_sick(String(objectTemp,1));
//  }
  return objectTemp;
}
