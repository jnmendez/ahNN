#include <stdio.h>
#include <ah_activation_f.h>
#include <ah_layer.h>

#define MAX_INPUT_TEST	21

float layerInput[MAX_INPUT_TEST][2] = {
		{-5.0, (float)0.006692851},
		{-4.5, (float)0.010986943},
		{-4.0, (float)0.017986210},
		{-3.5, (float)0.029312231},
		{-3.0, (float)0.047425873},
		{-2.5, (float)0.075858180},
		{-2.0, (float)0.119202922},
		{-1.5, (float)0.182425524},
		{-1.0, (float)0.268941421},
		{-0.5, (float)0.377540669},
		{ 0.0, (float)0.500000000},
		{ 0.5, (float)0.622459331},
		{ 1.0, (float)0.731058579},
		{ 1.5, (float)0.817574476},
		{ 2.0, (float)0.880797078},
		{ 2.5, (float)0.924141820},
		{ 3.0, (float)0.952574127},
		{ 3.5, (float)0.970687769},
		{ 4.0, (float)0.982013790},
		{ 4.5, (float)0.989013057},
		{ 5.0, (float)0.993307149}
};

t_layer test_layer;
t_layer * layer = &test_layer;

void layer_T1( void )
{
	int result ;

	result = ah_layer_init( layer, 0, 0, 2, &ah_sigmoid );
	
	if ( result == 1 ) 
	{
		printf("LAYER_INIT_T1 : %d - %d : PASS\n", result, 1);
	}
	else
	{
		printf("LAYER_INIT_T1 : %d - %d : FAIL\n", result, 1);			
	}

	result = ah_layer_init( layer, 0, 2, 2, &ah_sigmoid );
	
	if ( result == 0 ) 
	{
		printf("LAYER_INIT_T1 : %d - %d : PASS\n", result, 0);
	}
	else
	{
		printf("LAYER_INIT_T1 : %d - %d : FAIL\n", result, 0);			
	}
				
	result = ah_layer_init( layer, 1, MAX_NODE, 2, &ah_sigmoid );
	
	if ( result == 0 ) 
	{
		printf("LAYER_INIT_T1 : %d - %d : PASS\n", result, 0);
	}
	else
	{
		printf("LAYER_INIT_T1 : %d - %d : FAIL\n", result, 0);
	}

	result = ah_layer_init( layer, 1, MAX_NODE+1, 2, &ah_sigmoid );

	if ( result == 1 )
	{
		printf("LAYER_INIT_T1 : %d - %d : PASS\n", result, 1);
	}
	else
	{
		printf("LAYER_INIT_T1 : %d - %d : FAIL\n", result, 1);			
	}

}

void layer_T2( void )
{
	int result ;

	result = ah_layer_init( layer, 0, 2, 2, &ah_sigmoid );
	
	ah_layer_set_input(layer,layerInput[0]);
	
	if ( layer->_node[0]._x[0] == layerInput[0][0] ) 
	{
		printf("LAYER_IN_T2.1 : %f - %f : PASS\n", layer->_node[0]._x[0], layerInput[0][0]);
	}
	else
	{
		printf("LAYER_IN_T2.1 : %f - %f : FAIL\n", layer->_node[0]._x[0], layerInput[0][0]);			
	}

	if ( layer->_node[0]._x[1] == layerInput[0][1] ) 
	{
		printf("LAYER_IN_T2.2 : %f - %f : PASS\n", layer->_node[0]._x[1], layerInput[0][1]);
	}
	else
	{
		printf("LAYER_IN_T2.2 : %f - %f : FAIL\n", layer->_node[0]._x[1], layerInput[0][1]);			
	}

	if ( layer->_node[1]._x[0] == layerInput[0][0] ) 
	{
		printf("LAYER_IN_T2.3 : %f - %f : PASS\n", layer->_node[1]._x[0], layerInput[0][0]);
	}
	else
	{
		printf("LAYER_IN_T2.3 : %f - %f : FAIL\n", layer->_node[1]._x[0], layerInput[0][0]);			
	}

	if ( layer->_node[1]._x[1] == layerInput[0][1] ) 
	{
		printf("LAYER_IN_T2.4 : %f - %f : PASS\n", layer->_node[1]._x[1], layerInput[0][1]);
	}
	else
	{
		printf("LAYER_IN_T2.4 : %f - %f : FAIL\n", layer->_node[1]._x[1], layerInput[0][1]);			
	}

}

void layer_T3( void )
{
	int result ;

	result = ah_layer_init( layer, 0, 2, 2, &ah_sigmoid );
	
	ah_layer_set_weight(layer,layerInput[6]);
	
	if ( layer->_node[0]._w[0] == layerInput[6][0] ) 
	{
		printf("LAYER_W_T3.1 : %f - %f : PASS\n", layer->_node[0]._w[0], layerInput[6][0]);
	}
	else
	{
		printf("LAYER_W_T3.1 : %f - %f : FAIL\n", layer->_node[0]._w[0], layerInput[6][0]);			
	}

	if ( layer->_node[0]._w[1] == layerInput[6][1] ) 
	{
		printf("LAYER_W_T3.2 : %f - %f : PASS\n", layer->_node[0]._w[1], layerInput[6][1]);
	}
	else
	{
		printf("LAYER_W_T3.2 : %f - %f : FAIL\n", layer->_node[0]._w[1], layerInput[6][1]);			
	}

	if ( layer->_node[1]._w[0] == layerInput[6][0] ) 
	{
		printf("LAYER_W_T3.3 : %f - %f : PASS\n", layer->_node[1]._w[0], layerInput[6][0]);
	}
	else
	{
		printf("LAYER_W_T3.3 : %f - %f : FAIL\n", layer->_node[1]._w[0], layerInput[6][0]);			
	}

	if ( layer->_node[1]._w[1] == layerInput[6][1] ) 
	{
		printf("LAYER_W_T3.4 : %f - %f : PASS\n", layer->_node[1]._w[1], layerInput[6][1]);
	}
	else
	{
		printf("LAYER_W_T3.4 : %f - %f : FAIL\n", layer->_node[1]._w[1], layerInput[6][1]);			
	}

}


void layer_T4( void )
{
	float input2[2] 	= {(float)0.07585818,  (float)0.006692851};
	float weight2[2] 	= {(float)0.377540669, (float)0.010986943};
	float bias2[2] 		= {(float)0.924141820, (float)0.924141820};
	float output2[2]	= {(float)0.0, (float)0.0};
	
	ah_layer_init( layer, 0, 2, 2, &ah_sigmoid );
	ah_layer_set_weight(layer,weight2);
	ah_layer_set_input(layer,input2);
	ah_layer_set_bias(layer, bias2);
	
	ah_layer_prediction	( layer );
	
	ah_layer_get_output( layer, output2 );
	
	if ( output2[0] == (float)0.721688959 ) 
	{
		printf("LAYER_PRED_T4.1 : %f - %f : PASS\n", output2[0], 0.721688959);
	}
	else
	{
		printf("LAYER_PRED_T4.1 : %f - %f : FAIL\n", output2[0], 0.721688959);
	}	
	
	if ( output2[1] == (float)0.721688959 ) 
	{
		printf("LAYER_PRED_T4.2 : %f - %f : PASS\n", output2[1], 0.721688959);
	}
	else
	{
		printf("LAYER_PRED_T4.2 : %f - %f : FAIL\n", output2[1], 0.721688959);
	}	

}
