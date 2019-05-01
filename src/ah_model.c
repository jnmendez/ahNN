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
		ah_layer_init(&model->_layer[model->_nl], nn, ni, act );
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
		ah_layer_init(&model->_layer[model->_nl], nn, model->_layer[model->_nl-1]._nn, act );
		model->_nl++;
		errVal = 0;
	}
	return errVal;
}

void ah_model_calc( t_model * model )
{
	for ( int i = 0; i < model->_nl; i++ )
	{
		ah_layer_calc(&model->_layer[i]);
	}
}
