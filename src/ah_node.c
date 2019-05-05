/**
 ============================================================================
 @Name        : ahNN.c
 @Author      : Nicolas Mendez
 @Version     :
 @Copyright   :
 @Description :
 ============================================================================
 */
#include <ah_node.h>

/*
 *	@brief Initialize node
 *	@param node pointer to node
 *	@param ni number of inputs
 *	@param bi bias
 *	@param we weight vector
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include <ah_node.h>

int ah_node_init( t_node * node, int ni )
{
	int errVal = 1;
	if ( ni < MAX_INPUT )
	{
		node->_o 	= 0;
		node->_ni	= ni;
		memset(node->_w,0,ni);
		memset(node->_x,0,ni);

		errVal = 0;
	}
	return errVal;
}

void ah_node_prediction( t_node * node, float (*act)(float)  )
{
	for ( int i = 0; i < node->_ni; i++ )
	{
		node->_o = node->_o + (node->_w[i]*node->_x[i]);
	}
	node->_o = act( node->_o + node->_b );
}


void ah_node_set_input( t_node * node, float inputs[] )
{
	memcpy(node->_x,inputs,sizeof(float)*node->_ni);
}

void ah_node_set_weight( t_node * node, float weight[] )
{
	memcpy(node->_w,weight,sizeof(float)*node->_ni);
}

float ah_node_get_output( t_node * node  )
{
	return node->_o;
}
