#ifndef _GUISVM_H__
#define _GUISVM_H__ 

#include "classifier/svm/SVM.h"
#include "classifier/svm/SVM_light.h"
#include "classifier/svm_cplex/SVM_cplex.h"

#ifdef SVMMPI
#include "classifier/svm_mpi/mpi_svm.h"
#endif

class CGUI ;

class CGUISVM
{

public:
	CGUISVM(CGUI*);
	~CGUISVM();

	bool new_svm(CHAR* param);
	bool train(CHAR* param);
	bool test(CHAR* param);
	bool load(CHAR* param);
	bool save(CHAR* param);
	bool set_C(CHAR* param);

	CLabels* classify(CLabels* output=NULL);
	bool classify_example(INT idx, REAL& result);

	inline CSVM* get_svm() { return svm; }

 protected:
	CGUI* gui;
	CSVM* svm;
	double C;
};
#endif
