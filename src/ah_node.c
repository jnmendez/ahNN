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
#include <ah_node.h>

int ah_node_init( t_node * node, int ni )
{
	int errVal = 1;
	if ( ni < MAX_INPUT )
	{
		node->_o = 0;

		memset(node->_w,0,ni);
		memset(node->_i,0,ni);

		errVal = 0;
	}
	return errVal;
}
