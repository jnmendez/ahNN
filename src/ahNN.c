/*
 ============================================================================
 Name        : ahNN.c
 Author      : Nicolas Mendez
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ah_activation_f.h>
#include <ah_model.h>


int main(void) {
	int re;
	t_model * myModel = malloc(sizeof(t_model));
	float outData[3];
	float inData[4] = {1.0,2.0,3.0,4.0};
	float wData[4] 	= {0.1,0.2,0.3,0.4};


	re = ah_model_init( myModel );
	re = ah_model_add_input_layer(myModel,4,3,&ah_linear);
	re = ah_model_set_weight(myModel,0,wData);

	re = ah_model_add_layer(myModel,4,&ah_sigmoid);
	re = ah_model_set_weight(myModel,1,wData);

	re = ah_model_add_layer(myModel,2,&ah_sigmoid);
	re = ah_model_set_weight(myModel,2,wData);

	re = ah_model_add_layer(myModel,3,&ah_linear);
	re = ah_model_set_weight(myModel,3,wData);

	ah_model_prediction(myModel,inData,outData);

	return 0;
}
