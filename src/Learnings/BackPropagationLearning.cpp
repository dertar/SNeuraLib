#include "BackPropagationLearning.hpp"

BackPropagationLearning::BackPropagationLearning (
    MultiLayerPerceptron *mlp,
    ELOSS_FUNCTION eloss_function
) : Learning ()
{
  this->mlp = mlp;

  if (eloss_function == ELOSS_FUNCTION_DEFAULT)
    this->lossFunction = new DefaultLossFunction ();
  else if (eloss_function == ELOSS_FUNCTION_SQUARE)
    this->lossFunction = new SquareLossFunction ();
  else
    throw Exception ("Can't define loss function");
}

std::pair<int, float> *BackPropagationLearning::teach (
  const std::vector< Signals > &patterns,
  const std::vector< Signals > &answers,
  const double rate,
  const double globalErrorMin,
  const int maxIterations,
  const bool randomFeed
)
{
  Layers *layers = this->mlp->getLayers ();

  int iterations = 0;
  double globalError;

  for (int l = 0; l < layers->size (); l++)
  {
    double randWeights = 1.0 / (2.0 * layers->at (l)->size ());
    this->initializeWeights (
      layers->at (l),
      -randWeights,
      randWeights
    );
  }
  std::cout << std::endl;
  for (int l = 0; l < layers->size (); l++)
  {
    for (int n = 0; n < layers->at(l)->size ();n++)
    {
      for(int w = 0; w < layers->at(l)->at(n)->size (); w++)
      {
        std::cout << layers->at(l)->at(n)->at(w) << " ";
      }
      std::cout << std::endl;
    }
  }
  do
  {
    globalError = 0.0;
    this->generateSequence (patterns.size (), randomFeed);

    int p;
    while (!this->isOverBatch ())
    {
      p = this->getIndexOfPattern ();
      for (int a = 0; a < answers.at (p).size (); a++)
      {
        std::vector< Signals* > *forwardpass = this->forwardpass (
          patterns.at(p), layers
        );
        // std::cout << "f\n";
        // for(int i  = 0; i< forwardpass->size (); i++){
        //   for(int j = 0; j < forwardpass->at(i)->size(); j++){
        //     std::cout << forwardpass->at(i)->at(j) << " ";
        //   }
        //   std::cout << std::endl;
        // }

        std::vector< Signals* > *backwardpass = this->backwardpass (
            forwardpass,
            layers,
            answers.at (p).at (a),
            a
        );
// std::cout << "b\n";
//         for(int i  = 0; i< backwardpass->size (); i++){
//           for(int j = 0; j < backwardpass->at(i)->size(); j++){
//             std::cout << backwardpass->at(i)->at(j) << " ";
//           }
//           std::cout << std::endl;
//         }

        globalError += fabs(
          this->lossFunction->function (
            backwardpass->at (backwardpass->size () - 1)->at (0),
            answers.at (p).at (a)
          )
        );
        this->applyErrors(layers, forwardpass, backwardpass, a, rate);
        // system("pause");
      }
      this->nextPattern ();
    }

  }while (
    /*1.0 - */globalError > globalErrorMin &&
    ++iterations < maxIterations
  );

  return new std::pair<int, float> (iterations, globalError);
}

std::vector< Signals* >* BackPropagationLearning::backwardpass (
    std::vector< Signals* >* forwardpass,
    const Layers *layers,
    Signal answer,
    const int iTeachNeuron
)
{
  std::vector< Signals* > *gradients
      = new std::vector< Signals* > (layers-> size ());

  gradients->at (layers-> size () - 1) =
    new Signals(1);

  gradients->at (layers-> size () - 1)->at (0) =
   answer - forwardpass->at (forwardpass->size () - 1)->at (iTeachNeuron) ;


  // std::cout << "forward: " << forwardpass->at (forwardpass->size () - 1)->at (iTeachNeuron) << std::endl;

  // std::cout << "error: " << gradients->at (layers-> size () - 1)->at (0) << std::endl;


  gradients->at (layers-> size () - 2) = this->getLastLayerErrors (
      layers->at (layers->size () - 1)->at (iTeachNeuron),
      gradients->at (layers-> size () - 1)->at (0)
  );
  // std::cout << "layers :" << layers->size () << std::endl;
  for (int l = layers->size () - 3; l >= 0; l--)
  {
    gradients->at (l) = this->getLayerErrors (
        layers-> at (l),
        layers-> at (l + 1),
        gradients->at (l + 1)
    );
  }

  return gradients;
}

Signals* BackPropagationLearning::getLayerErrors (
    Neurons *layer,
    Neurons *layerForward,
    Signals *errorsForward
  )
{
  Signals* errors = new Signals (layer->size ());
  // std::cout << "Sdsds\n";
  for (int n = 0; n < layer->size (); n++)
  {
    errors-> at(n) = 0;
    for (int f = 0; f < layerForward->size (); f++)
    {
      double w = layerForward->at (f)->at (n + 1);
      double error = errorsForward->at (f);
      // std::cout << "cur:" << errors-> at(n) << "->" << w << "*" << error << "=" << w * error;
      errors-> at(n) = errors-> at(n) + w * error;
      // std::cout << "; " << errors-> at(n) << "\n";
    }
  }
  return errors;
}

std::vector< Signals* >* BackPropagationLearning::forwardpass (
  const Signals &impulse,
  const Layers *layers
)
{
  std::vector< Signals* > *ret =
      new std::vector< Signals* > (layers->size () + 1);

  ret->at (0) = new Signals (impulse);

  for (int l = 0; l < layers->size (); l++)
  {
    ret->at (l + 1) = new Signals (this->mlp->impulse (*ret->at (l), l));
  }

  for (int l = 0; l < ret->size () - 1; l++)
  {
    ret->at (l)->insert (ret->at (l)->begin (), ZERO_WEIGHT);
  }

  return ret;
}

void BackPropagationLearning::applyErrors (
  Layers *layers,
  std::vector< Signals* >* forwardpass,
  std::vector< Signals* >* backwardpass,
  const int iTeachNeuron,
  const double rate
)
{
  forwardpass->at (forwardpass->size () - 1)->insert(forwardpass->at (forwardpass->size () - 1)->begin(), 1.0);
  ActivationFunction *activationFunction = this->mlp->getActivationFunction ();
  for (int l = 0; l < layers->size (); l++)
  {
    for (int n = 0; n < layers->at (l)->size (); n++)
    {
      for (int w = 0; w < layers->at (l)->at(n)->size(); w++)
      {
          double W = layers->at (l)->at (n)->at (w);
          double d = backwardpass->at(l)->at(n);
          double s = forwardpass->at(l + 1)->at(n + 1);
          double fs = activationFunction->derivative (s);
          double x = forwardpass->at(l)->at(w);
          // std::cout << "W: " << W << ";" << "d: " << d << ";" "S: " << s << ";"
          // "x: " << x << ";\n";
          layers->at (l)->at (n)->at (w) = W + d * fs * x * rate;
      }
    }
  }
}

Signals* BackPropagationLearning::getLastLayerErrors (
    Neuron *neuronInLastLayer,
    const Signal error
)
{
  Signals *errors = new Signals(neuronInLastLayer->size () - 1);

  for (int w = 1; w < neuronInLastLayer->size (); w++)
  {
    errors-> at(w - 1) = neuronInLastLayer->at (w)
          * error;
  }

  return errors;
}
