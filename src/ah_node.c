/**
 ============================================================================
 @Name        : ahNN.c
 @Author      : Nicolas Mendez
 @Version     :
 @Copyright   :
 @Description :
 ============================================================================
 */
#include <string.h>
#include <ah_node.h>

/*
 *	@brief Initialize node
 *	@param node pointer to node
 *	@param ni number of inputs
 *	@param bi bias
 *	@param we weight vector
 *
 */
int ah_node_init( t_node * node, int ni, float bi, float we[] )
{
	int retErr = 1;
	if ( ni < MAX_INPUTS_NODE )
	{
		node->_b = bi;
		node->_o = 0;
		memcpy(node->_w,we,sizeof(float)*ni);
		retErr = 0;
	}
	return retErr;
}
