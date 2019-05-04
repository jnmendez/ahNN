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
	float inData[128];

	re = ah_model_init( myModel );
	re = ah_model_add_input_layer(myModel,128,13,&ah_linear);
	re = ah_model_add_layer(myModel,64,&ah_sigmoid);
	re = ah_model_add_layer(myModel,32,&ah_sigmoid);
	re = ah_model_add_layer(myModel,3,&ah_linear);

	ah_model_prediction(myModel,&inData,&outData);

	printf("%d",re);
	return 0;
}
