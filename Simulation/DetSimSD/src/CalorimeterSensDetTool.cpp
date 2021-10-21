#include "CalorimeterSensDetTool.h"

#include "G4VSensitiveDetector.hh"

#include "DetSimSD/CaloSensitiveDetector.h"

#include "DD4hep/Detector.h"

DECLARE_COMPONENT(CalorimeterSensDetTool);

StatusCode
CalorimeterSensDetTool::initialize() {
    StatusCode sc;


    m_geosvc = service<IGeomSvc>("GeomSvc");
    if (!m_geosvc) {
        error() << "Failed to find GeomSvc." << endmsg;
        return StatusCode::FAILURE;
    }


    return sc;
}

StatusCode
CalorimeterSensDetTool::finalize() {
    StatusCode sc;

    return sc;
}

G4VSensitiveDetector*
CalorimeterSensDetTool::createSD(const std::string& name) {

    dd4hep::Detector* dd4hep_geo = m_geosvc->lcdd();

    bool flagUnmerge = false;
    for(auto cal_name : m_unmergeCals){
      if(cal_name==name){
	flagUnmerge = true;
	break;
      }
    }
    G4VSensitiveDetector* sd = new CaloSensitiveDetector(name, *dd4hep_geo, flagUnmerge);
    debug() << name << " set to merge true/false = " << !flagUnmerge << endmsg;

    return sd;
}


