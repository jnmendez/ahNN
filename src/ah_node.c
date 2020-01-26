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
	if ( ni < MAX_NODE)
	{
		node->_o 	= 0;
		node->_ni	= ni;
		memset(node->_w,0.0,ni);
		memset(node->_x,0.0,ni);
		node->_b 	= 0.0;
		errVal = 0;
	}
	return errVal;
}

/*
 * \brief node prediction
 * @param node pointer to node structure
 * @param act pointer to activation function
 */
AH_NN_T ah_node_prediction( t_node * node, AH_NN_T (*act)(AH_NN_T)  )
{
	/* 112 nanosec */
/*	AH_NN_T * pw = &node->_w[0];	*/
/*	AH_NN_T * px = &node->_x[0];	*/

	int rest = node->_ni % 4;

	for ( int i = 0; i < node->_ni-rest; i+=4)
	{
		node->_o = node->_o + node->_w[i]*node->_x[i];
		node->_o = node->_o + node->_w[i+1]*node->_x[i+1];
		node->_o = node->_o + node->_w[i+2]*node->_x[i+2];
		node->_o = node->_o + node->_w[i+3]*node->_x[i+3];
	}

	for ( int i = node->_ni-rest; i < node->_ni; ++i )
	{
		node->_o = node->_o + node->_w[i]*node->_x[i];
	}

	node->_o = act( node->_o + node->_b );

	return node->_o;
}

AH_NN_T ah_node_prediction_0( t_node * node, AH_NN_T (*act)(AH_NN_T)  )
{
	/* 95 nanosec 88% CPU */
	AH_NN_T * pw = &node->_w[0];
	AH_NN_T * px = &node->_x[0];

	for ( int i = 0; i < node->_ni; ++i)
	{
		node->_o = node->_o + (*pw++)*(*px++);
	}

	node->_o = act( node->_o + node->_b );

	return node->_o;
}

AH_NN_T ah_node_prediction_1( t_node * node, AH_NN_T (*act)(AH_NN_T)  )
{
	/* 87 nanosec 80% */
	AH_NN_T * pw = &node->_w[0];
	AH_NN_T * px = &node->_x[0];

	for ( int i = 0; i < node->_ni; ++i)
	{
		node->_o = node->_o + node->_w[i]*node->_x[i];
	}

	node->_o = act( node->_o + node->_b );

	return node->_o;
}

/*
 * \brief set node inputs
 * @param node pointer to node structure
 * @param inputs input vector
 */
void ah_node_set_input( t_node * node, AH_NN_T * inputs )
{
	memcpy(node->_x,inputs,sizeof(AH_NN_T)*node->_ni);
}

/*
 * \brief set node weight
 * @param node pointer to node structure
 * @param weight weight vector
 */
void ah_node_set_weight( t_node * node, AH_NN_T * weight )
{
	memcpy(node->_w,weight,sizeof(AH_NN_T)*node->_ni);
}

/*
 * \brief set node bias
 * @param node pointer to node structure
 * @param bias value
 */
void ah_node_set_bias( t_node * node, AH_NN_T bias )
{
	node->_b = bias;
}

/*
 * \brief return calculated output
 * @param node pointer to node structure
 * @return calculated output
 */
AH_NN_T ah_node_get_output( t_node * node  )
{
	return node->_o;
}
