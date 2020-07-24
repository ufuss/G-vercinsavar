//Servo kütüphanesini ekleyelim:

#include <Servo.h>                

//Pinlerimizi ve değişkenlerimizi tanımlıyoruz:

int pirPin = 8;       //Hareket Sensörünün pinini 8 olarak belirlemiş olduk.
int servoPin = 9;     //Servoyunun sinyal kablosunu 9 numaralı pine takacağız.
int ledPin = 2;       //Ledimizin artı bacağının 2 numaralı pinden sinyal almasını sağladık.
int buzzerPin = 3;    //Buzzer'ın artı bacağını 3 numaralı pine bağlayarak sinyal almasını sağladık.
int hareket;          //Hareket sensöründen gelen veri.
Servo motor;          //Servo motor değişkeni.


void setup() {
  motor.attach(servoPin);        //Servo motorunu yukarıda tanımladığımız 9. pin ile ilişkilendirdik.
  pinMode(pirPin,INPUT);         //Hareket Sensör pinini giriş pini olarak ayarladık.
  pinMode(ledPin,OUTPUT);        //Ledimizin pinini çıkış pini olarak ayarladık (Böylece hareket algılanırsa aşağıda tanımlayacağımız aralıklarla yanacak).
  pinMode(buzzerPin,OUTPUT);     //Buzzer pinimizi de çıkış pini olarak ayarladık (Böylece hareket algılanırsa aşağıda tanımlayacağımız aralıklarla ötecek).
}

void loop() {
  hareket = digitalRead(pirPin);      //Hareket sensöründen okuma yapıyoruz.
  
  if(hareket == HIGH){                //Hareketlilik var ise if'in içindeki komutlar uygulanır.
    motor.write(150);                 //Servo motorun açısını 150 derece yaptık (Siz motoru yerleştirdiğiniz konuma göre farklı açılar deneyebilirsiniz)
    digitalWrite(ledPin,HIGH);        //Ledi yaktık
    digitalWrite(buzzerPin,HIGH);     //Buzzerın ötmesini sağladık
    delay(450);                       //450 milisaniye bekledik (Siz farklı bekleme aralıkları kullanabilirsiniz)
    digitalWrite(ledPin,LOW);         //Ledi söndürdük
    digitalWrite(buzzerPin,LOW);      //Buzzerı susturduk
    motor.write(30);                  //Servo motorun açısını 30 derece yaptık ve aşağıda da farklı açılar kullanarak devam ettik.
    delay(450);
    motor.write(150);
    delay(450);
    motor.write(30);
    delay(450);
    motor.write(150);
    delay(450);
    motor.write(30);
    delay(450);
    motor.write(90);
  }
  else{                           //Hareketlilik yok ise else'in içindeki komutlar uygulanır.
    motor.write(90);              // Servo motorumuzun açısını dik olacak şekilde ayarladık
    digitalWrite(ledPin,LOW);     //Ledimiz yanmıyor.
    digitalWrite(buzzerPin,LOW);  //Buzzerımız ötmüyor.
    
  }
}
