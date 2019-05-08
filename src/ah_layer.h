/*
 * ah_layer.h
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */

#ifndef AH_LAYER_H_
#define AH_LAYER_H_

#include <ah_node.h>

#define MAX_NODE 256

/**
 * Layer structure
 */
typedef struct
{
	int _id;					/**< LAYER ID			*/
	int _nn;					/**< NUMBER OF NODES 	*/
	int _ni;					/**< NUMBER OF INPUTS 	*/
	t_node _node[MAX_NODE];		/**< MAX NUM NODES		*/
	float (*_act)(float);		/**< ACT FUNCTION		*/
}t_layer;

/**
 * \brief Layer initialization
 * @param ly pointer to layer structure
 * @param id layer id
 * @param nn number of node
 * @param ni number if input
 * @param act pointer to activation fucntion
 * @return 1 in case of error
 */
int ah_layer_init( t_layer * ly, int id, int nn, int ni, float (*act)(float) );

/**
 * \brief Calculate prediction for the layer
 * @param ly pointer to layer structure
 */
void ah_layer_prediction( t_layer * ly );

/**
 * \brief set layer inputs
 * @param ly pointer to layer structure
 * @param inputs input vector
 */
void ah_layer_set_input( t_layer * ly, float inputs[] );

/**
 * \brief set layer weight
 * @param ly pointer to layer structure 
 * @param weight weight vector
 */
void ah_layer_set_weight( t_layer * ly, float weight[] );

/**
 * \brief get layer output
 * @param ly pointer to layer structure
 * @param output output vector
 */
void ah_layer_get_output( t_layer * ly, float output[] );


#endif /* AH_LAYER_H_ */
