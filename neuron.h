/******************************
  Programmer : saugata
  Date : 18/6/2021
  Description :
      Header file for Neuron.
******************************/

#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED
#include <vector>

class Neuron{
private:
     std::vector<double> synapse;
     double bais;
     const double learning_rate;
     //Stores last activation's inputs. Used for back propagation and debugging.
     std::vector<double> last_inputs;
     //Stores last activation's output. Also used for back propagation and debugging.
     double last_output;
     //Error from last back propagation.
     double delta;
public:
     // Constructor for Neuron. num_synapse: number of inputs synapse required for
     // this neuron. Typically this is the number of neurons in the previous layer,
     // or number of features.
     Neuron(const int& num_synapse, const double& learning_rate);

     //Activates neuron and synapse. inputs: vector of input features.
     double activate(const std::vector<double>& inputs);

     //Back propagate
     double backProp(const std::vector<double>& delta_in, const std::vector<double>& forward_synapse);

     // Returns the weight of requested synapse.
     double getSynapse(const int& index) const;

     // Returns output from last activation.
     double getOutput() const;

     // Returns delta from last back propagation.
     double getDelta() const;
};

double sigmoid(const double& x);
#endif
