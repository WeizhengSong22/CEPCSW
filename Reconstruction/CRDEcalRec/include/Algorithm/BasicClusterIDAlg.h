#ifndef _BASICCLUSTERID_ALG_H
#define _BASICCLUSTERID_ALG_H

#include "PandoraPlusDataCol.h"

using namespace CRDEcalEDM;
class BasicClusterIDAlg{

public: 
  
  class Settings{
  public: 
    Settings(){};

    void SetInitialValue(); 

  };

  BasicClusterIDAlg() {};
  ~BasicClusterIDAlg() {};
  StatusCode Initialize();
  StatusCode RunAlgorithm( BasicClusterIDAlg::Settings& m_settings, PandoraPlusDataCol& m_datacol);
  StatusCode ClearAlgorithm();


  Settings settings; 

private:

};


#endif
