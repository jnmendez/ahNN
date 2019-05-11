#include <stdio.h>
#include <ah_activation_f.h>
#include <ah_model.h>

#define MAX_INPUT_TEST	21

float modelInput[MAX_INPUT_TEST][2] = {
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

t_model test_model;
t_model * model = &test_model;

void model_T1( void )
{
	int result ;

	ah_model_init( model );
	
	if ( model->_nl == 0 )
	{
		printf("MODEL_INIT_T1 : %d - %d : PASS\n", model->_nl, 0);
	}
	else
	{
		printf("model_INIT_T1 : %d - %d : FAIL\n", model->_nl, 0);
	}
}

void model_T2( void )
{
	int result ;

	ah_model_init( model );
	ah_model_add_input_layer( model, 2, 2, &ah_sigmoid );

	ah_model_add_layer(model, 2, &ah_sigmoid);

	float input2[2] 	= {(float)0.07585818,  (float)0.006692851};
	float weight2[2] 	= {(float)0.377540669, (float)0.010986943};
	float bias2[2] 		= {(float)0.924141820, (float)0.924141820};
	float output2[2]	= {(float)0.0, (float)0.0};

	ah_model_set_weight(model, 0, weight2);
	ah_model_set_weight(model, 1, weight2);
	ah_model_set_bias(model, 0, bias2);
	ah_model_set_bias(model, 1, bias2);

	ah_model_prediction( model, input2, output2 );
	printf("MO %f - %f \n", output2[0],output2[1]);
}
