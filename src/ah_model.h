/*
 * ah_model.h
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */

#ifndef AH_MODEL_H_
#define AH_MODEL_H_

#include <ah_layer.h>

#define MAX_LAYERS 10

/**
 * Model structure
 */
typedef struct
{
	int _nl;						/**< NUMBER OF LAYERS 	*/
	t_layer _layer[MAX_LAYERS];		/**< MAX NUM NODES		*/
}t_model;


/*# create model
modelStr="ANN_256L64S32S3L_ADA_MB64_LR001"
model = Sequential()
model.add(Dense(256, input_dim=datasetX.shape[1],activation='linear'))
model.add(Dense(64, activation='sigmoid'))
model.add(Dense(32, activation='sigmoid'))
model.add(Dense(3, activation='linear'))
*/

int ah_model_init( t_model * model );
int ah_model_add_input_layer ( t_model * model, int nn, int ni, float (*act)(float) );
int ah_model_add_layer ( t_model * model, int nn, float (*act)(float) );
void ah_model_prediction( t_model * model, float * in[],  float * out[]);

#endif /* AH_MODEL_H_ */
