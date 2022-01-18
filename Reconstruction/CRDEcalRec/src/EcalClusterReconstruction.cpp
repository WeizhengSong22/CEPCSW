#include "EcalClusterReconstruction.h"

void EcalClusterReconstruction::Initialize(){

  //Initialize settings
  m_LFAlgSettings  = new LocalMaxFindingAlg::Settings();
  m_ESAlgSettings  = new EnergySplittingAlg::Settings();
  m_CC2AlgSettings = new ConeClustering2DAlg::Settings();
  m_HCAlgSettings  = new HoughClusteringAlg::Settings();
  m_CMAlgSettings  = new ShadowMakingAlg::Settings(); 
  m_ETAlgSettings  = new EnergyTimeMatchingAlg::Settings();
  m_CCAlgSettings  = new ConeClusteringAlg::Settings();
  m_CLAlgSettings  = new ClusterMergingAlg::Settings();
  m_CIDAlgSettings = new BasicClusterIDAlg::Settings();


  //Initialize Algorthm
  m_localmaxfindingAlg  = new LocalMaxFindingAlg();
  m_energysplittingAlg  = new EnergySplittingAlg();
  m_coneclus2DAlg       = new ConeClustering2DAlg();
  m_houghclusAlg        = new HoughClusteringAlg();
  m_shadowmakingAlg     = new ShadowMakingAlg(); 
  m_etmatchingAlg       = new EnergyTimeMatchingAlg();
  m_coneclusterAlg      = new ConeClusteringAlg();
  m_clustermergingAlg   = new ClusterMergingAlg();
  m_clusteridAlg        = new BasicClusterIDAlg();  

}

StatusCode EcalClusterReconstruction::RunAlgorithm( EcalClusterReconstruction::Settings& settings,  PandoraPlusDataCol& dataCol ){


  //Iteration 0: pre-treatment, get initial level candidates
  m_LFAlgSettings->SetInitialValue();
  m_ESAlgSettings->SetInitialValue();
  m_CC2AlgSettings->SetInitialValue();
  m_HCAlgSettings->SetInitialValue();
  m_CMAlgSettings->SetInitialValue(); 
  m_ETAlgSettings->SetInitialValue();
  m_CCAlgSettings->SetInitialValue();
  m_CLAlgSettings->SetInitialValue();
  m_CIDAlgSettings->SetInitialValue();


  //Stage 1
  m_localmaxfindingAlg->RunAlgorithm( *m_LFAlgSettings,  dataCol );
  //m_coneclus2DAlg     ->RunAlgorithm( *m_CC2AlgSettings, dataCol );
  m_houghclusAlg      ->RunAlgorithm( *m_HCAlgSettings, dataCol );

/*
cout<<"  LongiClusterX size: "<<dataCol.LongiClusXCol.size()<<endl;
cout<<"  Loop print the longiclusterX: "<<endl;
for(int ic=0; ic<dataCol.LongiClusXCol.size(); ic++){
  cout<<"    In LongiCluster #"<<ic<<endl;
  printf("    From layer %d to %d, bar shower size %d \n", dataCol.LongiClusXCol[ic].getBeginningDlayer(), dataCol.LongiClusXCol[ic].getEndDlayer(), dataCol.LongiClusXCol[ic].getBarShowers().size());
  for(int is=0; is<dataCol.LongiClusXCol[ic].getBarShowers().size(); is++)
    printf("  (%.3f, %.3f, %.3f) \t", dataCol.LongiClusXCol[ic].getBarShowers()[is].getPos().x(), 
                                      dataCol.LongiClusXCol[ic].getBarShowers()[is].getPos().y(),
                                      dataCol.LongiClusXCol[ic].getBarShowers()[is].getPos().z() );
  cout<<endl;
}

cout<<"  LongiClusterY size: "<<dataCol.LongiClusYCol.size()<<endl;
cout<<"  Loop print the longiclusterY: "<<endl;
for(int ic=0; ic<dataCol.LongiClusYCol.size(); ic++){
  cout<<"    In LongiCluster #"<<ic<<endl;
  printf("    From layer %d to %d, bar shower size %d \n", dataCol.LongiClusYCol[ic].getBeginningDlayer(), dataCol.LongiClusYCol[ic].getEndDlayer(), dataCol.LongiClusYCol[ic].getBarShowers().size());
  for(int is=0; is<dataCol.LongiClusYCol[ic].getBarShowers().size(); is++)
    printf("  (%.3f, %.3f, %.3f) \t", dataCol.LongiClusYCol[ic].getBarShowers()[is].getPos().x(),
                                      dataCol.LongiClusYCol[ic].getBarShowers()[is].getPos().y(),
                                      dataCol.LongiClusYCol[ic].getBarShowers()[is].getPos().z() );
  cout<<endl;
}

  //m_shadowmakingAlg   ->RunAlgorithm( *m_CMAlgSettings, dataCol );

//dataCol.PrintLayer();
*/
/*
  //Stage 2:
  m_energysplittingAlg->RunAlgorithm( *m_ESAlgSettings,  dataCol );
  m_etmatchingAlg->     RunAlgorithm( *m_ETAlgSettings, dataCol );

  //m_coneclusterAlg->    RunAlgorithm( *m_CCAlgSettings, dataCol);

//dataCol.PrintLayer();


  m_CIDAlgSettings->SetDepartShower(true);
  m_clusteridAlg->RunAlgorithm( *m_CIDAlgSettings, dataCol );

  m_CCAlgSettings->SetClusterType("MIP");
  m_CCAlgSettings->SetConeValue(PI/4., 50., PI/6., 30.);
  m_CCAlgSettings->SetGoodClusLevel(5);
  m_CCAlgSettings->SetOverwrite(true);
  m_coneclusterAlg->RunAlgorithm( *m_CCAlgSettings, dataCol);

  m_CCAlgSettings->SetClusterType("EM");
  m_CCAlgSettings->SetGoodClusLevel(4);
  m_CCAlgSettings->SetOverwrite(false);
  m_coneclusterAlg->RunAlgorithm( *m_CCAlgSettings, dataCol);

  m_CCAlgSettings->SetClusterType("");
  m_CCAlgSettings->SetConeValue(PI/2., 40., PI/2., 70.);
  m_CCAlgSettings->SetGoodClusLevel(5);
  m_CCAlgSettings->SetOverwrite(false);
  m_coneclusterAlg->RunAlgorithm( *m_CCAlgSettings, dataCol);

  m_CLAlgSettings->SetMergeGoodCluster(false);
  m_CLAlgSettings->SetMergeBadCluster(false);
  m_CLAlgSettings->SetMergeEMTail(false);
  m_clustermergingAlg  ->RunAlgorithm( *m_CLAlgSettings, dataCol );
*/

  return StatusCode::SUCCESS;

}


StatusCode EcalClusterReconstruction::ClearAlgorithm(){

  delete m_energysplittingAlg;
  delete m_coneclus2DAlg; 
  delete m_houghclusAlg;
  delete m_shadowmakingAlg; 
  delete m_etmatchingAlg;
  delete m_coneclusterAlg;
  delete m_clustermergingAlg;
  delete m_clusteridAlg;

  delete m_ESAlgSettings;
  delete m_CC2AlgSettings; 
  delete m_HCAlgSettings;
  delete m_CMAlgSettings; 
  delete m_ETAlgSettings;
  delete m_CCAlgSettings;
  delete m_CLAlgSettings;
  delete m_CIDAlgSettings;


  return StatusCode::SUCCESS;

}


