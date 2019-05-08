#include <stdio.h>

#include <ah_node.h>

#define MAX_INPUT_TEST	21

float nodeInput[MAX_INPUT_TEST][2] = {
		{-5.0, 0.006692851},
		{-4.5, 0.010986943},
		{-4.0, 0.017986210},
		{-3.5, 0.029312231},
		{-3.0, 0.047425873},
		{-2.5, 0.075858180},
		{-2.0, 0.119202922},
		{-1.5, 0.182425524},
		{-1.0, 0.268941421},
		{-0.5, 0.377540669},
		{ 0.0, 0.500000000},
		{ 0.5, 0.622459331},
		{ 1.0, 0.731058579},
		{ 1.5, 0.817574476},
		{ 2.0, 0.880797078},
		{ 2.5, 0.924141820},
		{ 3.0, 0.952574127},
		{ 3.5, 0.970687769},
		{ 4.0, 0.982013790},
		{ 4.5, 0.989013057},
		{ 5.0, 0.993307149}
};

t_node test_node;
t_node * node = &test_node;

void node_T1( void )
{
	int result ;
	
	for (int i = 0; i < MAX_INPUT ; i++ )
	{
		result = ah_node_init( node, i );
		
		if ( result == 0 ) 
		{
			printf("NODE_INIT_T1 : %d - %d : PASS\n", result, i);
		}
		else
		{
			printf("NODE_INIT_T1 : %d - %d : FAIL\n", result, i);			
		}
	}	
}

void node_T2( void )
{
	int result ;
	
	result = ah_node_init( node, MAX_INPUT );
	
	if ( result == 0 ) 
	{
		printf("NODE_INIT_T2 : %d - %d : FAIL\n", result, MAX_INPUT);
	}
	else
	{
		printf("NODE_INIT_T2 : %d - %d : PASS\n", result, MAX_INPUT);			
	}
}


void node_T3( void )
{
	ah_node_init( node, 2 );
	
	for ( int i = 0; i < MAX_INPUT_TEST; i++ )
	{
		ah_node_set_input( node, nodeInput[i] );		
				
		if ( node->_x[0] == nodeInput[i][0] ) 
		{
			printf("NODE_SET_IN_T3 : %f - %f : PASS\n", node->_x[0], nodeInput[i][0]);
		}
		else
		{
			printf("NODE_SET_IN_T3 : %f - %f : FAIL\n", node->_x[0], nodeInput[i][0]);
		}
		
		if ( node->_x[1] == nodeInput[i][1] ) 
		{
			printf("NODE_SET_IN_T3 : %f - %f : PASS\n", node->_x[1], nodeInput[i][1]);
		}
		else
		{
			printf("NODE_SET_IN_T3 : %f - %f : FAIL\n", node->_x[1], nodeInput[i][1]);
		}
	}
}
