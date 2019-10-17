#include  "softposit.h"
#include <stdio.h>
#include <stdlib.h>


// Variáveis Globais
int menu;		//seleciona neuronio a ser simulado
double v;
double u;
double I;		//Corrente 
double a,b,c,d;		//Parâmetros
posit32_t pV;
posit32_t pU;

//Funções

void calculapV(double c, double I){
	if(convertP32ToDouble(pV) >=30){
		pV = convertDoubleToP32(c);
	}
	else{
		posit32_t paux = p32_mulAdd(convertDoubleToP32(5), pV, convertDoubleToP32(140)); //5*V+140
		posit32_t paux2 = p32_add(paux, convertDoubleToP32(I)); //5*V+140+I
		posit32_t paux3 = p32_sub(paux2,pU);//5*V+140+I-u
		posit32_t paux4 = p32_mul(convertDoubleToP32(0.04),p32_mul(pV,pV));//0.04*v*v
		posit32_t paux5 = p32_add(paux3,paux4);//0.04*v*v+5*V+140+I-u
		pV = p32_mulAdd(paux5,convertDoubleToP32(0.5),pV);//(0.04*v*v+5*V+140+I-u)*0.5 +v
	}
}

void calculapU(double a, double b, double c, double d){
	if(convertP32ToDouble(pV) >= 30){
		pU = p32_add(pU,convertDoubleToP32(d));
	}
	else{
		posit32_t paux1 = p32_mul(convertDoubleToP32(b),pV); //b*u
		posit32_t paux2 = p32_sub(paux1,pU); //(b*u-u)
		posit32_t paux3 = p32_mul(convertDoubleToP32(a),paux2); // a*(b*u-u)
		pU = p32_mulAdd(convertDoubleToP32(0.5),paux3,pU); //0.5*a*(b*u-u)+u
	}	
	
}

/*void geraGrafico(double a, double b, double c, double d, double I){
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(0); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
	}
}
*/
//////////////
/*void calculaV()
void calculaU()*/

void NeuTonicSpiking(){
	I = 10;
	a = 0.02;
	b = 0.2;
	c = -65;
	d = 8;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(0); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
	}
}
void NeuPhasicSpinking(){
	I = 0.5;
	a = 0.02;
	b = 0.25;
	c = -65;
	d = 6;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(-18); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
		
	}
}
void NeuTonicBursting(){
	I = 15;
	a = 0.02;
	b = 0.2;
	c = -50;
	d = 2;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(0); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
	}	
}

void NeuPhasicBursting(){
	I = 0.6;
	a = 0.02;
	b = 0.25;
	c = -55;
	d = 0.05;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(-19); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
	}
}
void NeuMixedMode(){
    I = 10;
	a = 0.02;
	b = 0.2;
	c = -55;
	d = 4;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(-19); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
   }    
}
void NeuSpikeFrequenci(){
    I = 30;
	a = 0.01;
	b = 0.2;
	c = -65;
	d = 8;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(-18); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
    }
}

void NeuClasseOneExcitable(){
    I = 0;
	a = 0.01;
	b = 0.2;
	c = -65;
	d = 8;
	pV = convertDoubleToP32(c);
	pU = convertDoubleToP32(-18); //Condições Iniciais
	v = convertP32ToDouble(pV);
	u = convertP32ToDouble(pU);
	printf("\n0 %lf %lf",v,u);
	int n;
	for (n=1;n<=2000;n++){
        I = n*0.1;
		calculapU(a,b,c,d);
		calculapV(c,I);
		v = convertP32ToDouble(pV);
		u = convertP32ToDouble(pU);
		printf("\n%d %lf %lf",n,v,u);
    }
}


int main(){
	while(1){
		
		printf("\nPrograma Simulador de neurônios de Izhikevich");
		printf("\n1-Tonic Spiking \t 2-phasic spiking\n3-Tonic Bursting \t 4-Phasic Bursting\n5-Mixed Mode \t 6-Spike Frequenci adap.\n7-Class 1 Excitable");
		if (scanf("%i",&menu)==1);{
		switch (menu){
			case 1:
				printf("\nsimula o tonic spiking\n");
				NeuTonicSpiking();
				break;
			case 2:
				printf("\nsimula o phasic spiking\n");
				NeuPhasicSpinking();
				break;
			case 3:
				printf("\nsimula o Tonic Bursting\n");
				NeuTonicBursting();
				break;
			case 4:
				printf("\nsimula o Phasic Bursting\n");
				NeuPhasicBursting();
				break;
			case 5:
				printf("\nsimula o Mixed Mode\n");
				NeuMixedMode();
				break;
			case 6:
				printf("\nsimula o Spike Frequenci adap\n");	
				NeuSpikeFrequenci();
				break;
            		case 7:
                		printf("\nsimula o Class 1 excitable\n");
                		NeuClasseOneExcitable();
                		break;
			default:
				printf("\nneurônio inválido\n");
		}
	      }
	}
}
