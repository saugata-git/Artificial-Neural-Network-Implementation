/******************************
  Programmer : saugata
  Date : 19/6/2021
  Description :
      Implementation for Neuron.
******************************/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include "utils.h"
#include "neuron.h"

Neuron::Neuron(const int& num_synapse, const double& learning_rate)
   :bias(randD()), learning_rate(learning_rate), last_output(NULL), delta(NULL){
   for(int i = 0; i < num_synapse; i++){
      if(randD() > 0.5){
         synapse.push_back(randD());
      }
      else{
         synapse.push_back(-randD());
      }
      last_inputs.push_back(0);
   }
}

double Neuron::activate(const std::vector<double>& inputs){
   if( inputs.size() != synapse.size()){
      return -1;
   } 
   last_inputs = inputs;
   double sum = bias;
   for( int i = 0; i < inputs.size(); i++ ){
       sum += inputs[i] * synapse[i];
   }
   last_output = sigmoid(sum);
   return last_output;
}

    
double Neuron::backProp(const std::vector<double>& delta_in, 
const std::vector<double>& forward_synapse){
   if(delta_in.size() != forward_synapse.size()){
     return -1;
   }
   double error = 0;
   for( int i = 0; i < delta_in.size(); i++){
      error += delta_in[i] * forward_synapse[i];
   }
   delta = error * last_output * (1 - last_output);
   for(int i = 0; i < synapse.size(); i++){
      double temp = synapse[i] - learning_rate * delta * last_inputs[i];
      synapse[i] = temp;
   }
   bias = bias - learning_rate * delta;
   return delta;
}

double Neuron::getSynapse(const int& index) const{
   if( index >= synapse.size()){
      return -1;
   }
   return synapse[index];
}

double Neuron::getOutput() const{
   return last_output;
}

double Neuron::getDelta() const{
  return delta;
}

double sigmoid(const double& x){
   return 1.0 /(1 + exp(-x));
}
