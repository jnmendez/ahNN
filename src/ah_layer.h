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
	int _nn;					/**< NUMBER OF NODES 	*/
	int _ni;					/**< NUMBER OF INPUTS 	*/
	t_node _node[MAX_NODE];		/**< MAX NUM NODES		*/
	float (*_act)(float);		/**< ACT FUNCTION		*/
}t_layer;

/**
 *	@brief Initialize node
 *	@param node pointer to layer
 *	@param nn number of nodes
 */
int ah_layer_init( t_layer * ly, int nn, int ni, float (*act)(float) );
void ah_layer_prediction( t_layer * ly );


#endif /* AH_LAYER_H_ */
