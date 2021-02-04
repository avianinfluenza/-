#include <stdio.h>
#include <cmath>
using namespace std;

int datasize;
double W = 0;
double b = 0;
const double E = 2.718281;
int epoch;
int learning_rate;
int training_data[1000];
int training_label[1000];

double sigmoid(double x){
	if(1/(1+pow(E, x)) > 0.5){
		return 1;
	}
	else{
		return 0;
	}
}

void gradient_decent(){
	for(int j = 1; j <= epoch; j++){
		if(j %(epoch/20) ==0){
			printf(" on training...[");
			for(int k = 1; k <= epoch; k += (epoch/20)){
				if(k <= j){
					printf("#");
				}
				else{
					printf("_");
				}
			}
			printf("] W : %lf\n", W);
		}
		double costup = 0;
		double costdown = 0;
		for(int i = 0; i < datasize; i++){
			costup += ((W+0.1)*training_data[i]-training_label[i])*(W*training_data[i]-training_label[i]);
		}
		for(int i = 0; i < datasize; i++){
			costdown += ((W-0.1)*training_data[i]-training_label[i])*(W*training_data[i]-training_label[i]);
		}
		if(costdown < costup){
			W -= 0.1;
		}
		else{
			W += 0.1;
		}
	}
	printf("training finish!\n");
	printf("proper W : %lf", W);
}

int main(){
	int i, p;
	printf("datasize : ");
	scanf("%d", &datasize);
	printf("traning data : ");
	for(i = 0; i < datasize; i++){
		scanf("%d", &training_data[i]);
	}
	printf("traning label : ");
	for(i = 0; i < datasize; i++){
		scanf("%d", &training_label[i]);
	}
	printf("epoch : ");
	scanf("%d", &epoch);
	printf("learning rate : ");
	scanf("%lf", &learning_rate);
	gradient_decent();
	printf("predict_data : ");
	scanf("%d", &p);
	printf("%d\n", p);
	printf("prediction : %lf", W*p);
}
