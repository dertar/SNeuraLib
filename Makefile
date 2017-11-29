CC=g++
FLAGS=-c

CXX="C:\CPPLibs\cxxtest-4.4\bin\cxxtestgen"
PYTHON=python
CXX_FLAGS=--error-printer -o
TEST_FLAGS=-I$CXXTEST -static -std=c++11


all: cxx_gen compile_cxx run_cxx

cxx_gen:
	$(PYTHON) $(CXX) $(CXX_FLAGS) runner.cpp "cxx_tests/*.hpp"

compile_cxx: ActivationFunction.o LogarithmicAtivationFunction.o SquareLossFunction.o LossFunction.o StochasticGradientLearning.o GaussianActivationFunction.o SigmoidActivationFunction.o HyperbolicActivationFunction.o LinearActivationFunction.o ErrorCorrectionLearning.o Exception.o Neuron.o Perceptron.o Learning.o SingleLayerPerceptron.o ThresholdActivationFunction.o Utils.o
	$(CC) -o runner ActivationFunction.o LogarithmicAtivationFunction.o SquareLossFunction.o LossFunction.o StochasticGradientLearning.o GaussianActivationFunction.o SigmoidActivationFunction.o HyperbolicActivationFunction.o LinearActivationFunction.o ErrorCorrectionLearning.o Exception.o Neuron.o Perceptron.o Learning.o SingleLayerPerceptron.o ThresholdActivationFunction.o Utils.o $(TEST_FLAGS) runner.cpp

run_cxx:
	runner

ActivationFunction.o: src/ActivationFunctions/ActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/ActivationFunction.cpp

ErrorCorrectionLearning.o: src/Learnings/ErrorCorrectionLearning.cpp
	$(CC) $(FLAGS) src/Learnings/ErrorCorrectionLearning.cpp

Exception.o: src/Utils/Exception.cpp
	$(CC) $(FLAGS) src/Utils/Exception.cpp

Neuron.o: src/Neuron.cpp
	$(CC) $(FLAGS) src/Neuron.cpp

Perceptron.o: src/Perceptron.cpp
	$(CC) $(FLAGS) src/Perceptron.cpp

Learning.o: src/Learnings/Learning.cpp
	$(CC) $(FLAGS) src/Learnings/Learning.cpp

SigmoidActivationFunction.o: src/ActivationFunctions/SigmoidActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/SigmoidActivationFunction.cpp

LogarithmicAtivationFunction.o: src/ActivationFunctions/LogarithmicAtivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/LogarithmicAtivationFunction.cpp

GaussianActivationFunction.o: src/ActivationFunctions/GaussianActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/GaussianActivationFunction.cpp

LinearActivationFunction.o: src/ActivationFunctions/LinearActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/LinearActivationFunction.cpp

HyperbolicActivationFunction.o: src/ActivationFunctions/HyperbolicActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/HyperbolicActivationFunction.cpp

SingleLayerPerceptron.o: src/SingleLayerPerceptron.cpp
	$(CC) $(FLAGS) src/SingleLayerPerceptron.cpp

ThresholdActivationFunction.o: src/ActivationFunctions/ThresholdActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunctions/ThresholdActivationFunction.cpp

StochasticGradientLearning.o: src/Learnings/StochasticGradientLearning.cpp
	$(CC) $(FLAGS) src/Learnings/StochasticGradientLearning.cpp

LossFunction.o: src/LossFunctions/LossFunction.cpp
	$(CC) $(FLAGS) src/LossFunctions/LossFunction.cpp

SquareLossFunction.o: src/LossFunctions/SquareLossFunction.cpp
	$(CC) $(FLAGS) src/LossFunctions/SquareLossFunction.cpp

Utils.o: cxx_tests/Utils.cpp
	$(CC) $(FLAGS) cxx_tests/Utils.cpp

clean:
	rm -rf *.o runner.cpp runner.exe runner
