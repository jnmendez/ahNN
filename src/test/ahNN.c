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

t_model * _el_model;

extern void activation_f_T1(void);
extern void activation_f_T2(void);
extern void node_T1(void);
extern void node_T2(void);
extern void node_T3(void);
extern void node_T4(void);
extern void node_T5(void);
extern void node_T6(void);
extern void layer_T1(void);
extern void layer_T2(void);
extern void layer_T3(void);
extern void layer_T4(void);
extern void model_T1(void);
extern void model_T2(void);
void _el_init_model(void);

int main(void) {

	_el_model = malloc(sizeof(t_model));

	/*
	int re;

	AH_NN_T outData[3];
	AH_NN_T inData[4] = {1.0,2.0,3.0,4.0};
	AH_NN_T wData[4] 	= {0.1,0.2,0.3,0.4};


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


	activation_f_T1();
	activation_f_T2();
	node_T1();
	node_T2();
	node_T3();
	node_T4();
	node_T5();
	node_T6();
	layer_T1();
	layer_T2();
	layer_T3();
	layer_T4();
	model_T1();
	model_T2();*/

	_el_init_model();
	return 0;
}
