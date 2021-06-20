/**************************************************
  Programmer : saugata
  Date : 20/6/2021
  Description :
    Header file for instance class and functions.
***************************************************/

#include <string>
#include <vector>
#include <memory>
#include "instance.h"

Instance::Instance( const std::string& name, std::vector<double>* data,
    std::vector<double>* expected, std::shared_ptr<std::vector<std::string> >& features,
    std::shared_ptr<std::vector<std::string> >& classes ) 
    :name(name), data(data), expected(expected), features(features), classes(classes){

    }

Instance::Instance(const Instance& rhs)
    :name(rhs.name){
        std::vector<double>* t_data = new std::vector<double>();
        std::vector<double>* e_data = new std::vector<double>();
        for(const double d : *(rhs.data)){
           t_data->push_back(d);
        }
        for(const double e : *(rhs.expected)){
           e_data->push_back(e);
        }
        data = std::unique_ptr<std::vector<double> >(t_data);
        expected = std::unique_ptr<std::vector<double> >(e_data);
        features = std::shared_ptr<std::vector<std::string> >(rhs.features);
        classes = std::shared_ptr<std::vector<std::string> >(rhs.classes);
    }

Instance& Instance::operator=( const Instance& rhs){
    if( this != &rhs ){
        data.reset();
        expected.reset();
        features.reset();
        classes.reset();
        std::vector<double>* t_data = new std::vector<double>();
        std::vector<double>* e_data = new std::vector<double>();
        for(const double d : *(rhs.data)){
           t_data->push_back(d);
        }
        for(const double e : *(rhs.expected)){
           e_data->push_back(e);
        }
        name = rhs.name;
        data = std::unique_ptr<std::vector<double> >(t_data);
        expected = std::unique_ptr<std::vector<double> >(e_data);
        features = std::shared_ptr<std::vector<std::string> >(rhs.features);
        classes = std::shared_ptr<std::vector<std::string> >(rhs.classes);
    }
    return *this;
}

Instance::~Instance(){
   data.reset();
   expected.reset();
   features.reset();
   classes.reset();    
}

double Instance::operator[]( const int& index) const{
    return (*data)[index];
}

double Instance::getExpected( const int& index) const{
    return (*expected)[index];  
}

size_t Instance::getDataSize() const{
   return data->size();
}

size_t Instance::getExpectedSize() const{
    return expected->size();
}

std::string Instance::getFeatName(const int& index) const{
    return (*features)[index];
}

std::string Instance::getClassName(const int& index) const{
    return (*classes)[index];
}


InstanceSet::InstanceSet( std::string name, SetType type, std::vector<Instance> instances)
    : name(name), type(type), instances(instances){}

InstanceSet::InstanceSet( std::string name, SetType type)
    : name(name), type(type){}

std::string InstanceSet::getName() const{
    return name;
}

bool operator==( const InstanceSet& left, const InstanceSet& right ){
    return left.getName() == right.getName();
}

bool operator==( const InstanceSet& left, const std::string& right){
    return left.getName() == right;
}





