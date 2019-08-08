/***********************************************/
/* GENERATED CODE. DO NOT MODIFY MANUALLY      */
/***********************************************/                   

#include <time.h>
#include <stdio.h>
#include <ah_activation_f.h>
#include <ah_model.h>


/* Pointer to NN model */
extern t_model * _az_model;

/* Bias and weight vectors */
extern float _az_biasLayer_1[];
extern float _az_weightLayer_1[];
extern float _az_biasLayer_2[];
extern float _az_weightLayer_2[];
extern float _az_biasLayer_3[];
extern float _az_weightLayer_3[];

/* Input vector */
float input_az_model[11] =
{
(float)0.0/*ioPrediction[0]*/,
(float)0.0/*ioPrediction[1]*/,
(float)0.0/*ioPrediction[2]*/,
(float)0.0/*ioPrediction[3]*/,
(float)0.0/*ioPrediction[4]*/,
(float)0.0/*ioPrediction[5]*/,
(float)0.0/*ioPrediction[6]*/,
(float)0.0/*ioPrediction[7]*/,
(float)0.0/*ioPrediction[8]*/,
(float)0.0/*ioPrediction[9]*/,
(float)0.0/*ioPrediction[10]*/,
};

/* Output vector */
float output_az_model[1];

void _az_init_model( void )
{
     /* Init model */	
     ah_model_init( _az_model );

     /* Setup model */
     ah_model_add_input_layer( _az_model, 70, 11, &ah_sigmoid );
     ah_model_set_bias(_az_model, 0, &_az_biasLayer_1[0]);
     ah_model_set_weight(_az_model, 0, &_az_weightLayer_1[0]);
	
     ah_model_add_layer(_az_model, 50, &ah_sigmoid);
     ah_model_set_bias(_az_model, 1, &_az_biasLayer_2[0]);
     ah_model_set_weight(_az_model, 1, &_az_weightLayer_2[0]);
     ah_model_add_layer(_az_model, 1, &ah_softplus);
     ah_model_set_bias(_az_model, 2, &_az_biasLayer_3[0]);
     ah_model_set_weight(_az_model, 2, &_az_weightLayer_3[0]);

	
#ifdef _TIME_HOST_
     clock_t begin = clock();
#endif
#ifdef _TIME_GPC_
     readStart();
#endif
     /* here, do your time-consuming job */
     ah_model_prediction( _az_model, input_az_model, output_az_model );
#ifdef _TIME_GPC_
     computeEnd();
     printf("PRINT TIME %llu micros\n", avg);
#endif

#ifdef _TIME_HOST_
     clock_t end = clock();
     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("TIME microsec : %lf\n",time_spent*1000000);
#endif
}
