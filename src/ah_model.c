/*
 * ah_model.c
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */
#include <ah_model.h>

/*
 * \brief Initialize ANN model
 * @param mod pointer to model structure
 * @return 
 */
int ah_model_init( t_model * mod )
{
	mod->_nl = 0 ; /* Num layers */
	return 0;
}

/*
 * \brief Add input layer for a model.
 * @param model pointer to model structure.
 * @param nn number of nodes.
 * @param ni number of inputs.
 * @param act pointer to activation function.
 * @return 1 in case of error
 */
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

/*
 * \brief Add layer for a model.
 * @param model pointer to model structure.
 * @param nn number of nodes.
 * @param act pointer to activation function.
 * @return 1 in case of error
 */
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

/*
 * \brief Calcalute predictions for a set of inputs
 * @param model pointer to model structure.
 * @param in input data vector
 * @param out calculated predictions.vector 
 */
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

/*
 * \brief Set weight for a specific layer
 * @param model pointer to model structure. 
 * @param ly layer ID
 * @param weight weight vector
 * @return
 */
int ah_model_set_weight( t_model * model, int ly ,float weight[])
{
	ah_layer_set_weight(&model->_layer[ly], weight);
	return 0;
}

/*
 * \brief Set bias for a specific layer
 * @param model pointer to model structure.
 * @param ly layer ID
 * @param bias bias vector
 * @return
 */
int ah_model_set_bias( t_model * model, int ly ,float bias[])
{
	ah_layer_set_bias(&model->_layer[ly], bias);
	return 0;
}
