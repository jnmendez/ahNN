/*
 * ah_layer.c
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */
#include <ah_node.h>
#include <ah_layer.h>

/**
 * \brief Layer initialization
 * @param ly pointer to layer structure
 * @param id layer id
 * @param nn number of node
 * @param ni number if input
 * @param act pointer to activation fucntion
 * @return 1 in case of error
 */
int ah_layer_init( t_layer * ly, int id, int nn, int ni, AH_NN_T (*act)(AH_NN_T) )
{
	int errVal = 1;
	if (( nn > 0 ) && ( nn <= MAX_NODE ))
	{
		ly->_nn = nn;
		ly->_id = id;
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
 * \brief Calculate prediction for the layer
 * @param ly pointer to layer structure
 */
void ah_layer_prediction( t_layer * ly )
{
	AH_NN_T * plo = &ly->_lo[0];
	t_node  * pni = &ly->_node[0];

	for ( int i = 0; i < ly->_nn; i++ )
	{
		*plo++ = ah_node_prediction( pni++, ly->_act );
	}
}

/**
 * \brief set layer inputs
 * @param ly pointer to layer structure
 * @param inputs input vector
 */
void ah_layer_set_input( t_layer * ly, AH_NN_T * inputs )
{
	t_node  * pni = &ly->_node[0];

	for ( int i = 0; i < ly->_nn; i++ )
	{
		ah_node_set_input( pni++, inputs );
	}
}

/**
 * \brief set layer weight
 * @param ly pointer to layer structure 
 * @param weight weight vector
 */
void ah_layer_set_weight( t_layer * ly, AH_NN_T * weight )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		ah_node_set_weight( &(ly->_node[i]), weight+(i*ly->_ni) );
	}
}


/**
 * \brief set layer bias
 * @param ly pointer to layer structure 
 * @param bias bias vector
 */
void ah_layer_set_bias( t_layer * ly, AH_NN_T * bias )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		ah_node_set_bias( &ly->_node[i], bias[i] );
	}
}

/**
 * \brief get layer output
 * @param ly pointer to layer structure
 * @param output output vector
 */
void ah_layer_get_output( t_layer * ly, AH_NN_T * output )
{
	for ( int i = 0; i < ly->_nn; i++ )
	{
		output[i] = ah_node_get_output( &ly->_node[i] );
	}
}
