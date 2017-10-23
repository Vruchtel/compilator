// Каждый интерфейс соответствует одному нетерминалу
#include <cstring>

/*interfaces*/

class IProgram {
	//virtual int eval() const = 0;
};

class IMainClass {	
	//virtual int eval() const = 0;
};

class IClassDeclList {
	//virtual int eval() const = 0;
};

class IClassDeclaration {
	//virtual int eval() const = 0;
};

class IVarDeclList {
	//virtual int eval() const = 0;
};

class IVarDeclaration {
	//virtual int eval() const = 0;
};

class IMethodDeclList {
	//virtual int eval() const = 0;
};

class IMethodDeclaration {
	//virtual int eval() const = 0;
};

class IType {
	//virtual int eval() const = 0;
};

class IStatementList {
	//virtual int eval() const = 0;
};

class IStatement {
	//virtual int eval() const = 0;
};

class IExp {
	//virtual int eval() const = 0;
};

class IExpList {
	
};

class IFormalList {
	
};

/*classes*/

class CProgram : public IProgram {
public:
	CProgram(const IMainClass *_mc, const IClassDeclList *_cdecllist): mc(_mc), cdecllist(_cdecllist) {}
	//virtual int eval() const {
		//return mc->eval()?? Что тут надо возвращать, я не знаю...
		//return 0;
	//}
	
private:
	const IMainClass *mc;
	const IClassDeclList *cdecllist;
};

class CMainClass : public IMainClass {
public:
	CMainClass(const IStatement *_st, const char *_mcN, const char *_asN): st(_st), mainClassName(_mcN), argsStringName(_asN) {}
	
private:
	const IStatement *st;
	const char *mainClassName;
	const char *argsStringName;
};

class CClassDeclList : public IClassDeclList {
public:
	CClassDeclList(const IClassDeclaration *_cd, const IClassDeclList *_cdl): cd(_cd), cdl(_cdl) {}
		
private:
	const IClassDeclaration *cd;
	const IClassDeclList *cdl;
};

class CClassDeclaration : public IClassDeclaration {
public:
	CClassDeclaration(const char *_className, const char *_extandableClassName, const IVarDeclList *_vdl, const IMethodDeclList *_mdl) 
		: className(_className), extandableClassName(_extandableClassName), vdl(_vdl), mdl(_mdl) {}
private:
	const char *className;
	const char *extandableClassName;
	const IVarDeclList *vdl;
	const IMethodDeclList *mdl;
};

class CVarDeclList : public IVarDeclList {
public:
	CVarDeclList(const IVarDeclaration *_vd, const IVarDeclList *_vdl) : vd(_vd), vdl(_vdl) {}
private:
	const IVarDeclaration *vd;
	const IVarDeclList *vdl;
};

class CVarDeclaration : public IVarDeclaration {
public:
	CVarDeclaration(const IType *_type, const char *_varName) : type(_type), varName(_varName) {}
private:
	const IType *type;
	const char *varName;
};

class CMethodDeclList : public IMethodDeclList {
public:
	CMethodDeclList(const IMethodDeclaration *_md, const IMethodDeclList *_mdl) : md(_md), mdl(_mdl) {}
private:
	const IMethodDeclaration *md;
	const IMethodDeclList *mdl;
};

class CMethodDeclaration : public IMethodDeclaration {
public:
	CMethodDeclaration(const IType *_returnType, const char *_methodName, const IFormalList *_fl, const IVarDeclList *_vdl,
		const IStatementList *_stl, const IExp *_exp) : 
			returnType(_returnType), methodName(_methodName), fl(_fl), vdl(_vdl), stl(_stl), exp(_exp) {}
	
private:
	const IType *returnType;
	const char *methodName;
	const IFormalList *fl; // параметры метода
	const IVarDeclList *vdl;
	const IStatementList *stl;
	const IExp *exp;
};

class CInternalType : public IType {
public:
	CInternalType() {}
	//static IntArray intArray  // я не знаю, как это надо сделать...
private:
	
};

class CClassType : public IType {
public:
	CClassType(const char *_className) : className(_className) {}
private:
	const char *className;
};

class CStatementList : public IStatementList {
public:
	CStatementList(const IStatement *_st, const IStatementList *_stl) : st(_st), stl(_stl) {}
private:
	const IStatement *st;
	const IStatementList *stl;
};

// Вложенные statement
class CEnclosedStatement : public IStatement {
public:
	CEnclosedStatement(const IStatementList *_stl) : stl(_stl) {}
private:
	const IStatementList *stl;
};

class CIfElseStatement : public IStatement {
public:
	CIfElseStatement(const IExp *_exp, const IStatement *_ifst, const IStatement *_elsest) : exp(_exp), ifst(_ifst), elsest(_elsest) {}
private:
	const IExp *exp;
	const IStatement *ifst;
	const IStatement *elsest;
};

class CWhileStatement : public IStatement {
public:
	CWhileStatement(const IExp *_exp, const IStatement *_st) : exp(_exp), st(_st) {}
private:
	const IExp *exp;
	const IStatement *st;
};

class CPrintStatement : public IStatement {
public:
	CPrintStatement(const IExp *_exp) : exp(_exp) {}
private:
	const IExp *exp;
};

class CAssignStatement : public IStatement {
public:
	CAssignStatement(const char *_varName, const IExp *_exp) : varName(_varName), exp(_exp) {}
private:
	const char *varName;
	const IExp *exp;
};

class CAssignByIdxStatement : public IStatement {
public:
	CAssignByIdxStatement(const char *_varName, const IExp *_idxExp, const IExp *_exp) : varName(_varName), idxExp(_idxExp), exp(_exp) {}
private:
	const char *varName;
	const IExp *idxExp;
	const IExp *exp;
};

class CAriphmeticExp : public IExp {
public:
	CAriphmeticExp() {} // тут тоже непонятно... спасите!!!
private:
	// TODO...
};

class CExpList : public IExpList {
public:

private:
};
