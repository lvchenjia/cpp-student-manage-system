
// StudentManager.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "StudentManager.h"
#include "StudentManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

RootNode* root;

// CStudentManagerApp

BEGIN_MESSAGE_MAP(CStudentManagerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CStudentManagerApp 构造

CStudentManagerApp::CStudentManagerApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CStudentManagerApp 对象

CStudentManagerApp theApp;


// CStudentManagerApp 初始化

BOOL CStudentManagerApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager* pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	root = new RootNode;
	root->firstClass = NULL;

	CStudentManagerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

CString string2CString(string str)
{
	USES_CONVERSION;
	return A2T((LPSTR)(str.c_str()));
}

string CString2string(CString str) {
	return CT2A(str.GetString());
}

//创建新节点
ClassNode* createClassNode(string classname, string classid)
{
	ClassNode* newClass = new ClassNode();
	newClass->classid = classid;
	newClass->classname = classname;
	newClass->firstStudent = NULL;
	newClass->nextClass = NULL;
	return newClass;
}

StudentNode* createStudentNode(string id, string name, string sex, string age, string phonenum)
{
	StudentNode* newStudent = new StudentNode();
	newStudent->id = id;
	newStudent->name = name;
	newStudent->sex = sex;
	newStudent->age = age;
	newStudent->phonenum = phonenum;
	newStudent->firstCourse = NULL;
	newStudent->nextStudent = NULL;
	return newStudent;
}

CourseNode* createCourseNode(string subject, string mark)
{
	CourseNode* newCourse = new CourseNode();
	newCourse->subject = subject;
	newCourse->mark = mark;
	newCourse->nextCourse = NULL;
	return newCourse;
}

//定位到尾部节点
ClassNode* findLastClassNode(ClassNode* classNode)
{
	ClassNode* p = classNode;
	if (!p)
		return NULL;
	while (p->nextClass)
		p = p->nextClass;
	return p;
}

StudentNode* findLastStudentNode(StudentNode* studentNode)
{
	StudentNode* p = studentNode;
	if (!p)
		return NULL;
	while (p->nextStudent)
		p = p->nextStudent;
	return p;
}

CourseNode* findLastCourseNode(CourseNode* courseNode)
{
	CourseNode* p = courseNode;
	if (!p)
		return NULL;
	while (p->nextCourse)
		p = p->nextCourse;
	return p;
}

//查找结点
ClassNode* findClassNode(ClassNode* classNode, string name)
{
	ClassNode* p = classNode;
	while (p)
	{
		if (p->classname == name)
			return p;
		p = p->nextClass;
	}
	return NULL;
}

StudentNode* findStudentNode(StudentNode* studentNode, string id)
{
	StudentNode* p = studentNode;
	while (p)
	{
		if (p->id == id)
			return p;
		p = p->nextStudent;
	}
	return NULL;
}

CourseNode* findCourseNode(CourseNode* courseNode, string subject)
{
	CourseNode* p = courseNode;
	while (p)
	{
		if (p->subject == subject)
			return p;
		p = p->nextCourse;
	}
	return NULL;
}

//尾部插入新节点
void appendClassNode(RootNode* root, string classname, string classid)
{
	ClassNode* pre = findLastClassNode(root->firstClass);
	ClassNode* newClass = createClassNode(classname, classid);
	if (pre)
		pre->nextClass = newClass;
	else
		root->firstClass = newClass;
}

void appendStudentNode(ClassNode* classNode, string id, string name, string sex, string age, string phonenum)
{
	StudentNode* pre = findLastStudentNode(classNode->firstStudent);
	StudentNode* newStudent = createStudentNode(id, name, sex, age, phonenum);
	if (pre)
		pre->nextStudent = newStudent;
	else
		classNode->firstStudent = newStudent;
}

void appendCourseNode(StudentNode* studentNode, string subject, string mark)
{
	CourseNode* pre = findLastCourseNode(studentNode->firstCourse);
	CourseNode* newCourse = createCourseNode(subject, mark);
	if (pre)
		pre->nextCourse = newCourse;
	else
		studentNode->firstCourse = newCourse;
}

//释放节点及其子节点空间
void freeCourseLink(CourseNode* courseNode)
{
	if (!courseNode)
		return;
	CourseNode* p = courseNode;
	CourseNode* q = courseNode->nextCourse;
	while (p->nextCourse)
	{
		free(p);
		p = q;
		q = q->nextCourse;
	}
}

void freeStudentLink(StudentNode* studentNode)
{
	if (!studentNode)
		return;
	StudentNode* p = studentNode;
	StudentNode* q = studentNode->nextStudent;
	while (p->nextStudent)
	{
		freeCourseLink(p->firstCourse);
		free(p);
		p = q;
		q = q->nextStudent;
	}
}

//删除节点
void deleteClassNode(RootNode* root, string classname)
{
	ClassNode* p = NULL;
	ClassNode* q = root->firstClass;
	while (q)
	{
		if (q->classname == classname)
			break;
		p = q;
		q = q->nextClass;
	}

	if (!p) //仅有一个节点且要删除
	{
		root->firstClass = NULL;
		freeStudentLink(q->firstStudent);
		free(q);
		return;
	}

	if (!q)
		return; //未找到待删除节点

	p->nextClass = q->nextClass;
	freeStudentLink(q->firstStudent);
	free(q);
}

void deleteStudentNode(ClassNode* classNode, string id)
{
	if (!classNode)return;
	StudentNode* p = NULL;
	StudentNode* q = classNode->firstStudent;
	while (q)
	{
		if (q->id == id)
			break;
		p = q;
		q = q->nextStudent;
	}
	if (!p)
	{
		classNode->firstStudent = NULL;
		freeCourseLink(q->firstCourse);
		free(q);
		return;
	}
	if (!q)
		return;
	p->nextStudent = q->nextStudent;
	freeCourseLink(q->firstCourse);
	free(q);
}

void deleteCourseNode(StudentNode* studentNode, string subject)
{
	if (!studentNode)return;
	CourseNode* p = NULL;
	CourseNode* q = studentNode->firstCourse;
	while (q)
	{
		if (q->subject == subject)
			break;
		p = q;
		q = q->nextCourse;
	}
	if (!p)
	{
		studentNode->firstCourse = NULL;
		free(q);
		return;
	}
	if (!q)
		return;
	p->nextCourse = q->nextCourse;
	free(q);
}

//遍历链表
vector<string> getAllClassName(RootNode* root) {//获取全部班级名
	ClassNode* p = root->firstClass;
	vector<string> rst;
	while (p) {
		rst.push_back(p->classname);
		p = p->nextClass;
	}
	return rst;
}

vector<string> getStudentId(ClassNode* classNode) {//获取某班内全部学生id
	StudentNode* p = classNode->firstStudent;
	vector<string> rst;
	while (p) {
		rst.push_back(p->id);
		p = p->nextStudent;
	}
	return rst;
}

vector<string> getStudentIdAndName(ClassNode* classNode) {//获取某班内全部学生id与姓名
	StudentNode* p = classNode->firstStudent;
	vector<string> rst;
	while (p) {
		rst.push_back(p->id + " " + p->name);
		p = p->nextStudent;
	}
	return rst;
}

vector<string> getSubject(StudentNode* studentNode) {//获取某学生全部课程名
	CourseNode* p = studentNode->firstCourse;
	vector<string> rst;
	while (p) {
		rst.push_back(p->subject);
		p = p->nextCourse;
	}
	return rst;
}

vector<string> getSubjectAndMark(StudentNode* studentNode) {//获取某学生全部课程名与分数
	CourseNode* p = studentNode->firstCourse;
	vector<string> rst;
	while (p) {
		rst.push_back(p->subject + " " + p->mark);
		p = p->nextCourse;
	}
	return rst;
}