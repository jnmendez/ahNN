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

int ah_model_add_input_layer ( t_model * model, int nn, int ni )
{
	int errVal = 1;
	if ( model->_nl < MAX_LAYERS )
	{
		ah_layer_init(&model->_layer[model->_nl], nn, ni );
		model->_nl++;
		errVal = 0;
	}
	return errVal;
}

int ah_model_add_layer ( t_model * model, int nn  )
{
	int errVal = 1;
	if ( model->_nl < MAX_LAYERS )
	{
		ah_layer_init(&model->_layer[model->_nl], nn, model->_layer[model->_nl-1]._nn );
		model->_nl++;
		errVal = 0;
	}
	return errVal;
}

