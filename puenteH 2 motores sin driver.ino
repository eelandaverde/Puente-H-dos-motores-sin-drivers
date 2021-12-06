// C++ code
//
int contador = 4, contador2 = 4;
const int porcentajeTotal = 100;
const int valorAnalogTotal = 255;
int valorAnalogReq;


void setup()
{
  //entradas
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  //salidas
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop()
{
  int pulsadorUno = digitalRead(4);
  int pulsadorDos = digitalRead(7);
  
  int pulsadorTres = digitalRead(3);
  int pulsadorCuatro = digitalRead(2);
  
  	if (pulsadorUno == HIGH)
    {
    	contador +=1;
      	control(contador, 9 ,10);
    }
    if (pulsadorDos == HIGH)
    {
    	contador -=1;
      	control(contador , 9 , 10);
    }
  
  	if (pulsadorTres == HIGH)
    {
    	contador2 +=1;
      	control(contador2 , 5 , 6);
    }
    if (pulsadorCuatro == HIGH)
    {
    	contador2 -=1;
      	control(contador2, 5 , 6);
    }
    
}

void control(int conteo, int pin1, int pin2){
  
  delay(100);
  switch (conteo)
  {
  	case 0:
    	Vizquierda(100, pin1, pin2);
    break;
    case 1:
    	Vizquierda(75 , pin1, pin2);
    break;
    case 2:
    	Vizquierda(50, pin1, pin2);
    break;
    case 3:
    	Vizquierda(25, pin1, pin2);
    break;
    case 4:
    	paro();
    break;
    case 5:
    	Vderecha(25, pin1, pin2);
    break;
    case 6:
    	Vderecha(50, pin1, pin2);
    break;
    case 7:
    	Vderecha(75, pin1, pin2);
    break;
    case 8:
    	Vderecha(100, pin1, pin2);
    break;
    default:
    	if (contador > 8)
        {
        	contador = 8;
        }
    	if (contador < 0)
        {
        	contador = 0;
        }
    break;
  }
  delay(100);
  
}

void paro()
{
	digitalWrite(9,LOW);
  	digitalWrite(10,LOW);
  	digitalWrite(5,LOW);
  	digitalWrite(6,LOW);
}

void Vderecha(int porcentaje, int pin1, int pin2)
{
	digitalWrite(pin1,LOW);
  	valorAnalogReq = valorAnalogWrite(porcentaje);
  	analogWrite(pin2,valorAnalogReq);
}

void Vizquierda (int porcentaje, int pin1, int pin2)
{
	digitalWrite(pin2,LOW);
  	valorAnalogReq = valorAnalogWrite(porcentaje);
    analogWrite(pin1,valorAnalogReq);
  	
}

int valorAnalogWrite(int porcentaje)
{
	// 100 -> 255
    //  %  -> aw
   int aw = (porcentaje*valorAnalogTotal)/porcentajeTotal;
   return aw;
}