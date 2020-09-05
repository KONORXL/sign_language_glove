
#include <SoftwareSerial.h>

int Tx = 10;
int Rx = 11;
SoftwareSerial BT(Tx, Rx);
char DATO = 0;

int mod = 0;

//Registramos los pines del acelerometro 
const int xpin1 = A1;
const int ypin1 = A2;
const int zpin1 = A3;
const int xpin2 = A4;
const int ypin2 = A5;
const int zpin2 = A6;
const int xpin3 = A7;
const int ypin3 = A8;
const int zpin3 = A9;
//valores añadidos recientemente
const int xpin4 = A10;
const int ypin4 = A11;
const int zpin4 = A12;
const int xpin5 = A13;
const int ypin5 = A14;
const int zpin5 = A15;

// valor maximo = 265
// valor minimo = 402

//inicia el guante
int x1 = 0;
int y1 = 0;
int z1 = 0;
int val1 = 0;
//---------------
int x2 = 0;
int y2 = 0;
int z2 = 0;
int val2 = 0;
//---------------
int x3 = 0;
int y3 = 0;
int z3 = 0;
int val3 = 0;
//---------------
int x4 = 0;
int y4 = 0;
int z4 = 0;
int val4 = 0;
//---------------
int x5 = 0;
int y5 = 0;
int z5 = 0;
int val5 = 0;
//added recently
int val6 = 0;
int val7 = 0;
int val8 = 0;
int val9 = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  
  pinMode(xpin1, INPUT);
  pinMode(ypin1, INPUT);
  pinMode(zpin1, INPUT);
  pinMode(xpin2, INPUT);
  pinMode(ypin2, INPUT);
  pinMode(zpin2, INPUT);
  pinMode(xpin3, INPUT);
  pinMode(ypin3, INPUT);
  pinMode(zpin3, INPUT);
  
}

void loop() {
  //ejecuta el programa del guante en bucle
  if (BT.available() > 0){
    DATO = BT.read();
  }
      
      if (DATO == 'A'){    
          start();
          guanteFinal();    
          delay(1000);
      }    
      if (DATO == 'B'){    
          start();
          abecedario();    
          delay(1000);
      }
      if (DATO == 'C'){
        int mod = 0;   
      }
  }
  
void start(){
  //imprime los valores de el acelerometro
  Serial.print("Dedo 1- ");
  Serial.print("X: ");
  Serial.print(analogRead(xpin1));
  Serial.print("    Y: ");
  Serial.print(analogRead(ypin1));
  Serial.print("    Z: ");
  Serial.println(analogRead(zpin1));
  //------------------------------------
  Serial.print("Dedo 2- ");
  Serial.print("X: ");
  Serial.print(analogRead(xpin2));
  Serial.print("    Y: ");
  Serial.print(analogRead(ypin2));
  Serial.print("    Z: ");
  Serial.println(analogRead(zpin2));
  //------------------------------------
  Serial.print("Dedo 3- ");
  Serial.print("X: ");
  Serial.print(analogRead(xpin3));
  Serial.print("    Y: ");
  Serial.print(analogRead(ypin3));
  Serial.print("    Z: ");
  Serial.println(analogRead(zpin3));
  
  delay(1000);

}

//varible donde esta toda la programacion del guante
void guanteFinal(){
  //Parte de la programacion donde se lee los gestos de la mano 
  
  //dedo 1
  //x1
  int mod=1;
  if (analogRead(xpin1) >=200 && analogRead(xpin1) <=201){
    x1=x1+2;
  } else if (analogRead(xpin1) >=202 && analogRead(xpin1) <=500){
    x1=x1+3;
  } else if (analogRead(xpin1) >='numero' && analogRead(xpin1) <='numero') {
    x1=x1+4;
  }
  
  //y1
  if (analogRead(ypin1) >=200 && analogRead(ypin1) <=201){
    y1=y1+2;
  }else if (analogRead(ypin1) >=202 && analogRead(ypin1) <=500){
    y1=y1+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    y1=y1+4;
  }
  
  //z1
  if (analogRead(zpin1) >=200 && analogRead(zpin1) <=201){
    z1=z1+2;
  }else if (analogRead(zpin1) >=202 && analogRead(zpin1) <=500){
    z1=z1+3;
  }else if (analogRead(zpin1) >= 'numero' && analogRead(zpin1) <= 'numero'){
    z1=z1+4;
  }
//----------------------------------------------------------------------------------------------
  
  //dedo 2
  //x2
  if (analogRead(xpin2) >=200 && analogRead(xpin2) <=201){
    x2=x2+2;
  } else if (analogRead(xpin2) >=202 && analogRead(xpin2) <=500){
    x2=x2+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    x2=x2+4;
  }
  
  //y2
  if (analogRead(ypin2) >=200 && analogRead(ypin2) <=201){
    y2=y2+2;
  }else if (analogRead(ypin2) >=202 && analogRead(ypin2) <=500){
    y2=y2+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    y2=y2+4;
  }
  
  //z2
  if (analogRead(zpin2) >=200 && analogRead(zpin2) <=201){
    z2=z2+2;
  }else if (analogRead(zpin2) >=202 && analogRead(zpin2) <=500){
    z2=z2+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    z2=z2+4;
  }
//----------------------------------------------------------------------------------------------
  
  //dedo 3
  //x3
  if (analogRead(xpin3) >=200 && analogRead(xpin3) <=201){
    x3=x3+2;
  } else if (analogRead(xpin3) >=202 && analogRead(xpin3) <=500){
    x3=x3+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    x3=x3+4;
  }
  
  //y3
  if (analogRead(ypin3) >=200 && analogRead(ypin3) <=201){
    y3=y3+2;
  }else if (analogRead(ypin3) >=202 && analogRead(ypin3) <=500){
    y3=y3+3;
  }else if (analogRead(ypin1) >= 'numero' && analogRead(ypin1) <= 'numero'){
    y3=y3+4;
  }
  
  //z3
  if (analogRead(zpin3) >=200 && analogRead(zpin3) <=201){
    z3=z3+2;
  }else if (analogRead(zpin3) >=202 && analogRead(zpin3) <=500){
    z3=z3+3;
  }else if (analogRead(zpin3) >= 'numero' && analogRead(zpin3) <= 'numero'){
    z3=z3+4;
  }
//----------------------------------------------------------------------------------------------

  //dedo 4
  //x4
  if(analogRead(xpin4) >=200 && analogRead(xpin4) <=201){
    x4=x4+2;
  }else if(analogRead(xpin4)<='numero' && analogRead(xpin4) <='numero'){
    x4=x4+3; 
  }else if(analogRead(xpin4)<-'numero' && analogRead(xpin4) <='numero'){
    x4=x4+4;
  }

  //y4
  if (analogRead(ypin4) >=200 && analogRead(ypin4) <=201){
    y4=y4+2;
  }else if (analogRead(ypin4) >='numero' && analogRead(ypin4) <='numero'){
    y4=y4+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    y4=y4+4;
  }

  //z4
  if (analogRead(zpin4) >=200 && analogRead(zpin4) <=201){
    z4=z4+2;
  }else if (analogRead(zpin4) >='numero'&& analogRead(zpin4) <='numero'){
    z4=z4+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    z4=z4+4;
  }
//----------------------------------------------------------------------------------------------

  //dedo 5
  //5
  if (analogRead(xpin5) >=200 && analogRead(xpin5) <=201){
    x5=x5+2;
  }else if(analogRead(xpin5)<='numero' && analogRead(xpin5) <='numero'){
    x5=x5+3; 
  }else if(analogRead(xpin5)<-'numero' && analogRead(xpin5) <='numero'){
    x5=x5+4;
  }

  //y5
  if (analogRead(ypin4) >=200 && analogRead(ypin4) <=201){
    y5=y5+2;
  }else if (analogRead(ypin5) >='numero' && analogRead(ypin5) <='numero'){
    y4=y4+3;
  }else if (analogRead(ypin5) >= 'numero' && analogRead(ypin5) <= 'numero'){
    y4=y4+4;
  }

  //z5
  if (analogRead(zpin5) >=200 && analogRead(zpin5) <=201){
    z5=z5+2;
  }else if (analogRead(zpin4) >='numero' && analogRead(zpin4) <='numero'){
    z5=z5+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    z5=z5+4;
  }
//----------------------------------------------------------------------------------------------

  //final
  if (x1 == 2 && y1 == 2 && z1 == 2){
    val1 = val1+2;
    Serial.println(val1);
    }else if (x1==3 && y1==3 && z1 ==3){
      val1 = val1+3;
      Serial.println(val1);
    }else if (x1==4 && y1==4 && z1==4){
      val1 = val1+4;
      Serial.println(val1);
    }
  //add more words
  
  if (x2 == 2 && y2 == 2 && z2 == 2){
    val2 = val2+2;
    Serial.println(val2);
    }else if (x2==3 && y2==3 && z2 ==3){
      val2 = val2+3;
      Serial.println(val2);
    }else if (x2==4 && y2==4 && z2==4){
      val2 = val2+4;
      Serial.println(val2);
    }
  //add more words
  
  if (x3 == 2 && y3 == 2 && z3 == 2){
    val3 = val3+2;
    Serial.println(val3);
    }else if (x3==3 && y3==3 && z3 ==3){
      val3 = val3+3;
      Serial.println(val3);
    }else if (x3==4 && y3==4 && z3==4){
      val3=val3+4;
      Serial.println(val4);
    }
  //add more words 

  if (x4 == 2 && y4 == 2 && z4 == 2){
      val4=val4+2;
      Serial.println(val4);
    }else if(x4==3 && y4==3 && z4==3){
      val4=val4+3;
      Serial.println(val4);
    }else if(x4==4 && y4==4 && z4==4){
      val4=val4+4;
      Serial.println(val4);
    }
  //add more words

   if (x5 == 2 && y5 == 2 && z5 == 2){
      val5=val5+2;
      Serial.println(val5);
    }else if(x5==3 && y5==3 && z5==3){
      val5=val5+3;
      Serial.println(val5);
    }else if(x5==4 && y5==4 && z5==4){
      val5=val5+4;
      Serial.println(val5);
    }
  //add more words
  
  
//las palabras que dice el guante
  if (val1 == 2 && val2 == 2 && val3 == 2 && val4 == 2 && val5 == 2){
    Serial.println("holaaa");
    }else if (val1 == 3 && val2 == 3 && val3 ==3 && val4 == 3 && val5 == 3){
      Serial.println("no");
    }else if (val1==4 && val2==4 && val3==4 && val4 == 4 && val5 == 4){
      Serial.println("ejemplo");
    }
}

//modo abecedario
void abecedario(){
  int mod = 1;

  //dedo 1
  //x1
  if (analogRead(xpin1) >=200 && analogRead(xpin1) <=201){
    x1=x1+2;
  } else if (analogRead(xpin1) >=202 && analogRead(xpin1) <=500){
    x1=x1+3;
  }
  
  //y1
  if (analogRead(ypin1) >=200 && analogRead(ypin1) <=201){
    y1=y1+2;
  }else if (analogRead(ypin1) >=202 && analogRead(ypin1) <=500){
    y1=y1+3;
  }

  //z1
  if (analogRead(zpin1) >=200 && analogRead(zpin1) <=201){
    z1=z1+2;
  }else if (analogRead(zpin1) >=202 && analogRead(zpin1) <=500){
    z1=z1+3;
  }
//----------------------------------------------------------------------------------------------

  //dedo 2
  //x2
  if (analogRead(xpin2) >=200 && analogRead(xpin2) <=201){
    x2=x2+2;
  } else if (analogRead(xpin2) >=202 && analogRead(xpin2) <=500){
    x2=x2+3;
  }
  //y2
  if (analogRead(ypin2) >=200 && analogRead(ypin2) <=201){
    y2=y2+2;
  }else if (analogRead(ypin2) >=202 && analogRead(ypin2) <=500){
    y2=y2+3;
  }
  //z2
  if (analogRead(zpin2) >=200 && analogRead(zpin2) <=201){
    z2=z2+2;
  }else if (analogRead(zpin2) >=202 && analogRead(zpin2) <=500){
    z2=z2+3;
  }
//----------------------------------------------------------------------------------------------

  //dedo 3
  //x3
  if (analogRead(xpin3) >=200 && analogRead(xpin3) <=201){
    x3=x3+2;
  } else if (analogRead(xpin3) >=202 && analogRead(xpin3) <=500){
    x3=x3+3;
  }
  //y3
  if (analogRead(ypin3) >=200 && analogRead(ypin3) <=201){
    y3=y3+2;
  }else if (analogRead(ypin3) >=202 && analogRead(ypin3) <=500){
    y3=y3+3;
  }
  //z3
  if (analogRead(zpin3) >=200 && analogRead(zpin3) <=201){
    z3=z3+2;
  }else if (analogRead(zpin3) >=202 && analogRead(zpin3) <=500){
    z3=z3+3;
  }
//----------------------------------------------------------------------------------------------

  //dedo 4
  // x4
  if(analogRead(xpin4) >=200 && analogRead(xpin4) <=201){
    x4=x4+2;
  }else if(analogRead(xpin4)<='numero' && analogRead(xpin4) <='numero'){
    x4=x4+3; 
  }else if(analogRead(xpin4)<-'numero' && analogRead(xpin4) <='numero'){
    x4=x4+4;
  }

  //y4
  if (analogRead(ypin4) >=200 && analogRead(ypin4) <=201){
    y4=y4+2;
  }else if (analogRead(ypin4) >='numero' && analogRead(ypin4) <='numero'){
    y4=y4+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    y4=y4+4;
  }

  //z4
  if (analogRead(zpin4) >=200 && analogRead(zpin4) <=201){
    z4=z4+2;
  }else if (analogRead(zpin4) >='numero'&& analogRead(zpin4) <='numero'){
    z4=z4+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    z4=z4+4;
  }
//----------------------------------------------------------------------------------------------

  //dedo 5
  //5
  if (analogRead(xpin5) >=200 && analogRead(xpin5) <=201){
    x5=x5+2;
  }else if(analogRead(xpin5)<='numero' && analogRead(xpin5) <='numero'){
    x5=x5+3; 
  }else if(analogRead(xpin5)<-'numero' && analogRead(xpin5) <='numero'){
    x5=x5+4;
  }

  //y5
  if (analogRead(ypin4) >=200 && analogRead(ypin4) <=201){
    y5=y5+2;
  }else if (analogRead(ypin5) >='numero' && analogRead(ypin5) <='numero'){
    y4=y4+3;
  }else if (analogRead(ypin5) >= 'numero' && analogRead(ypin5) <= 'numero'){
    y4=y4+4;
  }

  //z5
  if (analogRead(zpin5) >=200 && analogRead(zpin5) <=201){
    z5=z5+2;
  }else if (analogRead(zpin4) >='numero' && analogRead(zpin4) <='numero'){
    z5=z5+3;
  }else if (analogRead(ypin4) >= 'numero' && analogRead(ypin4) <= 'numero'){
    z5=z5+4;
  }
//----------------------------------------------------------------------------------------------

  //final
  if (x1 == 2 && y1 == 2 && z1 == 2){
    val1 = val1+2;
    Serial.println(val1);
    }else if (x1==3 && y1==3 && z1 ==3){
      val1 = val1+3;
      Serial.println(val1);
    }else if (x1==4 && y1==4 && z1==4){
      val1 = val1+4;
      Serial.println(val1);
    }
  //add more words
  
  if (x2 == 2 && y2 == 2 && z2 == 2){
    val2 = val2+2;
    Serial.println(val2);
    }else if (x2==3 && y2==3 && z2 ==3){
      val2 = val2+3;
      Serial.println(val2);
    }else if (x2==4 && y2==4 && z2==4){
      val2 = val2+4;
      Serial.println(val2);
    }
  //add more words
  
  if (x3 == 2 && y3 == 2 && z3 == 2){
    val3 = val3+2;
    Serial.println(val3);
    }else if (x3==3 && y3==3 && z3 ==3){
      val3 = val3+3;
      Serial.println(val3);
    }else if (x3==4 && y3==4 && z3==4){
      val3=val3+4;
      Serial.println(val4);
    }
  //add more words 

  if (x4 == 2 && y4 == 2 && z4 == 2){
      val4=val4+2;
      Serial.println(val4);
    }else if(x4==3 && y4==3 && z4==3){
      val4=val4+3;
      Serial.println(val4);
    }else if(x4==4 && y4==4 && z4==4){
      val4=val4+4;
      Serial.println(val4);
    }
  //add more words

   if (x5 == 2 && y5 == 2 && z5 == 2){
      val5=val5+2;
      Serial.println(val5);
    }else if(x5==3 && y5==3 && z5==3){
      val5=val5+3;
      Serial.println(val5);
    }else if(x5==4 && y5==4 && z5==4){
      val5=val5+4;
      Serial.println(val5);
    }
  //add more words
  
  
//las palabras que dice el guante
  if (val1 == 2 && val2 == 2 && val3 == 2 && val4 == 2 && val5 == 2){
    Serial.println("a");
    }else if (val1 == 3 && val2 == 3 && val3 ==3 && val4 == 3 && val5 == 3){
      Serial.println("e");
    }else if (val1==4 && val2==4 && val3==4 && val4 == 4 && val5 == 4){
      Serial.println("i");
    }else if (val1==5 && val2==5 && val3==5 && val4 == 5 && val5 == 5){
      Serial.println("o");
    }else if (val1==6 && val2==6 && val3==6 && val4 == 6 && val5 == 6){
      Serial.println("u");//end of the vouls
    }else if (val1==7 && val2==7 && val3==7 && val4 == 7 && val5 == 7){
      Serial.println("t");
    }else if (val1==8 && val2==8 && val3==8 && val4 == 8 && val5 == 8){
      Serial.println("d");
    }else if (val1==9 && val2==9 && val3==9 && val4 == 9 && val5 == 9){
      Serial.println("r");
    }else if (val1==10 && val2==10 && val3==10 && val4 == 10 && val5 == 10){
      Serial.println("k");
    }
}
