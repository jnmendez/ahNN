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
int ah_layer_init( t_layer * ly, int nn, int ni )
{
	int errVal = 1;
	if ( nn < MAX_NODE )
	{
		ly->_nn = nn;
		ly->_ni = ni;
		for ( int i = 0; i < nn; i++ )
		{
			ah_node_init(&ly->_node[i], ni);
		}
		errVal = 0;
	}
	return errVal;
}
