/**
 ============================================================================
 @Name        : ahNN.c
 @Author      : Nicolas Mendez
 @Version     :
 @Copyright   :
 @Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ah_node.h>

/*
 * \brief Initialize node
 * @param node pointer to node structure
 * @param ni number of inputs
 * @return 1 in case of error
 */
int ah_node_init( t_node * node, int ni )
{
	int errVal = 1;
	if ( ni < MAX_INPUT )
	{
		node->_o 	= 0;
		node->_ni	= ni;
		memset(node->_w,0,ni);
		memset(node->_x,0,ni);
		node->_b 	= 0;
		errVal = 0;
	}
	return errVal;
}

/*
 * \brief node prediction
 * @param node pointer to node structure
 * @param act pointer to activation function
 */
void ah_node_prediction( t_node * node, float (*act)(float)  )
{
	for ( int i = 0; i < node->_ni; i++ )
	{
		node->_o = node->_o + (node->_w[i]*node->_x[i]);
	}
	node->_o = act( node->_o + node->_b );
}


/*
 * \brief set node inputs
 * @param node pointer to node structure
 * @param inputs input vector
 */
void ah_node_set_input( t_node * node, float inputs[] )
{
	memcpy(node->_x,inputs,sizeof(float)*node->_ni);
}

/*
 * \brief set node weight
 * @param node pointer to node structure
 * @param weight weight vector
 */
void ah_node_set_weight( t_node * node, float * weight )
{
	memcpy(node->_w,weight,sizeof(float)*node->_ni);
}

/*
 * \brief set node bias
 * @param node pointer to node structure
 * @param bias value
 */
void ah_node_set_bias( t_node * node, float bias )
{
	node->_b = bias;
}

/*
 * \brief return calculated output
 * @param node pointer to node structure
 * @return calculated output
 */
float ah_node_get_output( t_node * node  )
{
	return node->_o;
}
