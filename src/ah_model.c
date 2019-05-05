/*
 * ah_model.c
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */
#include <ah_model.h>

int ah_model_init( t_model * mod )
{
	mod->_nl = 0 ; /* Num layers */
	return 0;
}

int ah_model_add_input_layer ( t_model * model, int nn, int ni, float (*act)(float) )
{
	int errVal = 1;
	if ( model->_nl < MAX_LAYERS )
	{
		ah_layer_init( &model->_layer[model->_nl], model->_nl, nn, ni, act );
		model->_nl++;
		errVal = 0;
	}
	return errVal;
}

int ah_model_add_layer ( t_model * model, int nn, float (*act)(float)  )
{
	int errVal = 1;
	if ( model->_nl < MAX_LAYERS )
	{
		ah_layer_init(&model->_layer[model->_nl], model->_nl, nn, model->_layer[model->_nl-1]._nn, act );
		model->_nl++;
		errVal = 0;
	}
	return errVal;
}

void ah_model_prediction( t_model * model, float in[], float out[] )
{
	/* In is the input for the first layer.   */
	/* Out is the output for last layer       */
	/* For hidden layer in and out have to be */
	/* calculated                             */
	int numLayers = model->_nl;

	ah_layer_set_input(&model->_layer[0],in);
	ah_layer_prediction( &model->_layer[0] );

	for ( int i = 1; i < numLayers-1; i++ )
	{
		ah_layer_get_output	(&model->_layer[i-1],model->_transfer);
		ah_layer_set_input	(&model->_layer[i],model->_transfer);
		ah_layer_prediction	(&model->_layer[i] );
	}

	ah_layer_get_output	(&model->_layer[numLayers-2],model->_transfer);
	ah_layer_set_input	(&model->_layer[numLayers-1],model->_transfer);
	ah_layer_prediction	(&model->_layer[numLayers-1] );
	ah_layer_get_output	(&model->_layer[numLayers-1], out );
}

int ah_model_set_weight( t_model * model, int ly ,float weight[])
{
	ah_layer_set_weight(&model->_layer[ly], weight);
}
