/*
 * ah_model.h
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */

#ifndef AH_MODEL_H_
#define AH_MODEL_H_

#include <ah_model_arc.h>

#include <ah_layer.h>


/**
 * Model structure
 */
typedef struct
{
	int 	_nl;					/**< NUMBER OF LAYERS 	*/
	t_layer _layer[MAX_LAYERS];		/**< MAX NUM LAYERS		*/
	AH_NN_T _transfer[MAX_NODE];
}t_model;

/**
 * \brief Initialize ANN model
 * @param mod pointer to model structure
 * @return 
 */
int ah_model_init( t_model * mod );

/**
 * \brief Add input layer for a model.
 * @param model pointer to model structure.
 * @param nn number of nodes.
 * @param ni number of inputs.
 * @param act pointer to activation function.
 * @return 1 in case of error
 */
int ah_model_add_input_layer ( t_model * model, int nn, int ni, AH_NN_T (*act)(AH_NN_T) );

/**
 * \brief Add layer for a model.
 * @param model pointer to model structure.
 * @param nn number of nodes.
 * @param act pointer to activation function.
 * @return 1 in case of error
 */
int ah_model_add_layer ( t_model * model, int nn, AH_NN_T (*act)(AH_NN_T)  );

/**
 * \brief Calcalute predictions for a set of inputs
 * @param model pointer to model structure.
 * @param in input data vector
 * @param out calculated predictions.vector 
 */
void ah_model_prediction( t_model * model, AH_NN_T * in, AH_NN_T * out );

/**
 * \brief Set weight for a specific layer
 * @param model pointer to model structure. 
 * @param ly layer ID
 * @param weight weight vector
 * @return
 */
int ah_model_set_weight( t_model * model, int ly ,AH_NN_T * weight);

/*
 * \brief Set bias for a specific layer
 * @param model pointer to model structure.
 * @param ly layer ID
 * @param bias bias vector
 * @return
 */
int ah_model_set_bias( t_model * model, int ly ,AH_NN_T * bias);

#endif /* AH_MODEL_H_ */
