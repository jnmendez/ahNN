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
#include <ah_model.h>


int main(void) {
	int re;
	t_model * myModel = malloc(sizeof(t_model));
	re = ah_model_init( myModel );
	re = ah_model_add_input_layer(myModel,128,13);
	re = ah_model_add_layer(myModel,64);
	re = ah_model_add_layer(myModel,32);
	re = ah_model_add_layer(myModel,3);

	printf("%d",re);
	return 0;
}
