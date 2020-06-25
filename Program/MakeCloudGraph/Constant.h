//
// Created by lsh on 20. 3. 4..
//

#ifndef DATAPROCESS_VER6L_CONSTANT_H
#define DATAPROCESS_VER6L_CONSTANT_H

#define Threadnum 10
#define Filenum 90000
#define MaxParticlenum 100000
#define MaxProjectnum 500
#define MaxEdepNumber 510000000
#define MaxFluxIn1Hour 1000000
#define Hour 3600
#define divide 10
#define Sensitivity 0.03125 // 0.00001 in binary
#define dx 0.001953125 //0.000000001 in binary
//#define Daynum 1000
const char RawDataDir[150] ={"/media/lsh/CosmicrayRnE/COSMICRAY_DATA/Raw_data"}; //  /media/lsh/CosmicrayRnE/COSMICRAY_DATA/Raw_data
const char ProcessedDataDir[150] ={"/media/lsh/DATA/processed"}; // /media/lsh/CosmicrayRnE/COSMICRAY_DATA/Processed
const char CloudDataDir[150] = {"/media/lsh/CosmicrayRnE/COSMICRAY_DATA/cloud"};
const char ProjectDir[150] = {"/home/lsh/G4Project"};
const char SampleDir[150] = {"/home/lsh/Documents/CosmicrayRnE/G4project/sample"};
const char Geant4ConfigDir[150] = {"/home/lsh/program/geant4/install_dir"};
const char SimulationDataDir[200] ={"/media/lsh/CosmicrayRnE/simulationData/real-simulation"};
const char RootMacroDir[200] = {"/home/lsh/Documents/CosmicrayRnE/Program/root_macro"};
const char DivideDataDir[150] = {"/home/lsh/Documents/CosmicrayRnE/COSMICRAY_DATA/Processed/result/divide"};

const char CSV[5] = {"csv"};
const char TXT[5] = {"txt"};

#endif //DATAPROCESS_VER6L_CONSTANT_H
