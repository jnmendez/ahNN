/*
 * ah_layer.c
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */
#include <ah_node.h>
#include <ah_layer.h>
/*
 *	@brief Initialize node
 *	@param node pointer to layer
 *	@param nn number of nodes
 */
int ah_layer_init( t_layer * ly, int nn, int ni, float (*act)(float) )
{
	int errVal = 1;
	if ( nn < MAX_NODE )
	{
		ly->_nn = nn;
		ly->_ni = ni;
		ly->_act = act;
		for ( int i = 0; i < nn; i++ )
		{
			ah_node_init(&ly->_node[i], ni);
		}
		errVal = 0;
	}
	return errVal;
}

/**
 *
 */
void ah_layer_prediction( t_layer * ly )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		ah_node_prediction( &ly->_node[i], ly->_act );
	}
}

void ah_layer_set_input( t_layer * ly, float inputs[] )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		ah_node_set_input( &ly->_node[i], inputs );
	}
}

void ah_layer_get_output( t_layer * ly, float * output[] )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		*output[i] = ah_node_get_output( &ly->_node[i] );
	}
}
