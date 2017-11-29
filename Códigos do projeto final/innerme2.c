#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>          
#include <lcd.h> 

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  21              //Register select pin
#define LCD_E   22              //Enable Pin
#define LCD_D4  26               //Data pin 4
#define LCD_D5  23              //Data pin 5
#define LCD_D6  24              //Data pin 6
#define LCD_D7  27               //Data pin 7
#define GPIO_ECHO    3 
#define GPIO_TRIGGER  6

int lcd;
 
void display(char *s)
{	
	lcdClear(lcd);
	sleep(2); 
	lcdPuts(lcd, s); 
	lcdPosition(lcd, 0, 1) ; 

} 

// scanButton:

int scanButton (int button)
{
	if (digitalRead(button) == LOW){
		printf("O botão %d foi pressionado", button);
		//debounce
		while (digitalRead (button) == HIGH)
		{delay (10) ;}
		return 1;
	}
	return 0;
}

//Funcao para mostrar o menu:
void selecao_menu()
{
	int botao, i, button_state=0;
	sleep(1);
	display("Deseja bebida?");
	sleep(2);
	display("1:agua 2:refri");
	sleep(1);
	printf("\nBem vindo! Deseja uma bebida?\nMENU:\nAperte 1: para água;\nAperte 2: para cerveja.\n");

	while(!button_state){
		for (i = 0 ; i < 3 ; ++i)
			if(button_state = scanButton (i)) break;
		delay (1);
	}
	caso_botao(i);
	return;
}

//Funcao de selecao do menu:

void caso_botao(int b){
	switch(b){
		case 0:
			display("Insira um copo");
			printf("\nVocê escolheu água.\nInsira um copo e aguarde.\n");
			sleep(6);
			ultra(0);
			break;
		case 1: 
			display("Insira um copo");
			printf("\nVocê escolheu cerveja.\nInsira um copo e aguarde.\n");
			sleep(6);
			ultra(1);
			break;
		case 2:
			display("Escolha bebida!");
			printf("Escolha uma bebida primeiro!!!\n");
			sleep(2);
			break;
	}
}

//Funcao aciona sensor: 
void ultra(int button){
	double distancia_do_pulso=0, distancia_certa=9.0;
	distancia_do_pulso = leitura_sensor(); //fazer proporcionalidade com velocidade do som.
	if (distancia_do_pulso<=distancia_certa){
		acionabomba(button);
	}
	else{
		display("Peca novamente!");
	sleep(1);
		printf("\nPeça novamente.");
	}
	return;
}

//Ler gpio do sensor:
int leitura_sensor(){
//Compensate distance from edge to sensor
int COMP_SENSOR=0;

//Variables used by gettimeofday
struct timeval start, stop ; 

// Set pins as output and input
wiringPiSetup () ;
  pinMode (GPIO_TRIGGER, OUTPUT) ;
  pinMode (GPIO_ECHO, INPUT) ;

//Set trigger to False (Low)
digitalWrite (GPIO_TRIGGER,  0) ;

//200 ms delay to start 
delay (200) ;

//Send 10us pulse to trigger
digitalWrite (GPIO_TRIGGER,  1) ;
delayMicroseconds (10) ;
digitalWrite (GPIO_TRIGGER,  0) ;
gettimeofday(&start, NULL) ;
while (digitalRead (GPIO_ECHO)==0) 
{
gettimeofday(&start, NULL) ;
} 
while (digitalRead (GPIO_ECHO)==1) 
{
gettimeofday(&stop, NULL) ;
} 

// Calculate pulse length
double TIME_DELTA, DISTANCE ;
TIME_DELTA=((stop.tv_sec + stop.tv_usec) / 1000000.0) - ((start.tv_sec +start.tv_usec) / 1000000.0);

// Distance pulse travelled in that time is time multiplied by the speed of sound (cm/s)
DISTANCE=TIME_DELTA * 34000 ;

// That was the distance there and back so halve the value
DISTANCE=DISTANCE / 2 ;

// Add compensation
DISTANCE=DISTANCE + COMP_SENSOR ;

return DISTANCE;
}

//Acionar a bomba:

void acionabomba(cup){
	if(cup == 0){
		printf("acionando bomba 1...\n");
		system("gpio mode 4 out");
		sleep(6);
		system("gpio mode 4 in");}
	else if(cup == 1){
		printf("acionando bomba 2...\n");
		system("gpio mode 5 out");
		sleep(6);
		system("gpio mode 5 in");
	}
	else {
		display("Pronto!");
	}
	sleep(1);
	display("Deseja fotos?");
	sleep(1);
	display("Aperte 3");
	sleep(1);
	printf("Sua bebida está pronta. \nDeseja tirar uma foto?\n Se sim aperte 3\n");
	int botao, i, button_state=0;
       	while(!button_state){
		for (i = 0 ; i < 3 ; ++i)
			if(button_state = scanButton (i)) break;
		delay (1);
	}
		printf("lendo botao\n");
	sleep(5);
	switch(i){
		case 0:
			display("Ciao!");
			sleep(1);
			break;
		case 1: 
			display("Ciao!");
			sleep(1);
			break;
		case 2:
			display("Diga xiiis!");
			sleep(3);
			system("raspistill -o a%04d.jpg -t 3000 -tl 1000");
			system("mogrify -resize 640x480 a0000.jpg");
			system("mogrify -resize 640x480 a0001.jpg");
			system("mogrify -resize 640x480 a0002.jpg");
			system("mogrify -resize 640x480 a0003.jpg");
			system("convert -delay 40 -loop 0 a0000.jpg a0001.jpg a0002.jpg a0003.jpg animation.gif");
			system("python testanimation.py");
			break;
	}
	return;
}

void setup(void){
	wiringPiSetup () ;
	lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);           
	// Setup the inputs
	for (int i = 0 ; i < 3 ; ++i){
		pinMode(i, INPUT) ;
		//   pullUpDnControl (i, PUD_UP) ;
	}
}

int main(){
	setup();
	while(1){
		selecao_menu();
	}
	return 0;
}
