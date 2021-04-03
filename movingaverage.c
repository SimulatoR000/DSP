#include<stdio.h>
#include<math.h>

double * MA(double *Outputvector, double *Inputvector, size_t size, double lamda){
  for (size_t i=0; i<size; i++){
    * Outputvector = lamda * (*(Outputvector-1)) + (1-lamda) * (*Inputvector);
    //printf("%f\n",*Outputvector);
    Outputvector++;
    Inputvector++;
  }
}

int main(){
    
    size_t size =  2*256;
    double In[size];
    double out[size];
    int fc1 = 1e+3;
    int fc2 = 5e+6;
    float lamda = 0;
    for (int i=0; i<size; i++){
      In[i] = 0.2*sin(2*3.141516*fc2*i/(fc1*size)) + sin(2*3.141516*fc1*i/(fc1*size));
      //printf("%f\n",In[i]);
    }

    MA(out,In,size,lamda);
    for (int i=0;i<size;i++){
      printf("%f\n",out[i]);
    }
    return 0;
  }
