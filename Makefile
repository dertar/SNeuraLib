CC=g++
FLAGS=-c

CXX="cxxtestgen"
PYTHON=python
CXX_FLAGS=--error-printer -o
TEST_FLAGS=-I$CXXTEST -static -std=c++11


all: cxx_gen compile_cxx run_cxx

cxx_gen:
	$(PYTHON) $(CXX) $(CXX_FLAGS) runner.cpp "cxx_tests/*.hpp"

compile_cxx: activationfunction.o errorcorrectionlearning.o exception.o neuron.o perceptron.o learningagent.o singlelayerperceptron.o thresholdfunction.o utils.o
	$(CC) -o runner activationfunction.o errorcorrectionlearning.o exception.o neuron.o perceptron.o learningagent.o singlelayerperceptron.o thresholdfunction.o utils.o  $(TEST_FLAGS) runner.cpp

run_cxx:
	runner

activationfunction.o: src/ActivationFunction.cpp
	$(CC) $(FLAGS) src/ActivationFunction.cpp

errorcorrectionlearning.o: src/ErrorCorrectionLearning.cpp
	$(CC) $(FLAGS) src/ErrorCorrectionLearning.cpp

exception.o: src/Exception.cpp
	$(CC) $(FLAGS) src/Exception.cpp

neuron.o: src/Neuron.cpp
	$(CC) $(FLAGS) src/Neuron.cpp

perceptron.o: src/Perceptron.cpp
	$(CC) $(FLAGS) src/Perceptron.cpp

learningagent.o: src/LearningAgent.cpp
	$(CC) $(FLAGS) src/LearningAgent.cpp

singlelayerperceptron.o: src/SingleLayerPerceptron.cpp
	$(CC) $(FLAGS) src/SingleLayerPerceptron.cpp

thresholdfunction.o: src/ThresholdFunction.cpp
	$(CC) $(FLAGS) src/ThresholdFunction.cpp

utils.o: cxx_tests/Utils.cpp
	$(CC) $(FLAGS) cxx_tests/Utils.cpp

clean:
	rm -rf *.o runner.cpp runner.exe runner
