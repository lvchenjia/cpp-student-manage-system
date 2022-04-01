
// StudentManager.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CStudentManagerApp:
// 有关此类的实现，请参阅 StudentManager.cpp
//

class CStudentManagerApp : public CWinApp
{
public:
	CStudentManagerApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CStudentManagerApp theApp;

#include <string>
#include <vector>

using namespace std;

//学生的学科信息
struct CourseNode
{
	string subject;
	string mark;
	CourseNode* nextCourse;
};

//学生信息
struct StudentNode
{
	string id;
	string name;
	string sex;
	string age;
	string phonenum;
	CourseNode* firstCourse;
	StudentNode* nextStudent;
};

//班级信息
struct ClassNode
{
	string classid;
	string classname;
	StudentNode* firstStudent;
	ClassNode* nextClass;
};

//根节点
struct RootNode
{
	ClassNode* firstClass;
};

CString string2CString(string str);
string CString2string(CString str);

ClassNode* createClassNode(string classname, string classid);
StudentNode* createStudentNode(string id, string name, string sex, string age, string phonenum);
CourseNode* createCourseNode(string subject, string mark);

ClassNode* findLastClassNode(ClassNode* classNode);
StudentNode* findLastStudentNode(StudentNode* studentNode);
CourseNode* findLastCourseNode(CourseNode* courseNode);

ClassNode* findClassNode(ClassNode* classNode, string name);
StudentNode* findStudentNode(StudentNode* studentNode, string id);
CourseNode* findCourseNode(CourseNode* courseNode, string subject);

void appendClassNode(RootNode* root, string classname, string classid);
void appendStudentNode(ClassNode* classNode, string id, string name, string sex, string age, string phonenum);
void appendCourseNode(StudentNode* studentNode, string subject, string mark);

void freeCourseLink(CourseNode* courseNode);
void freeStudentLink(StudentNode* studentNode);

void deleteClassNode(RootNode* root, string classname);
void deleteStudentNode(ClassNode* classNode, string id);
void deleteCourseNode(StudentNode* studentNode, string subject);

vector<string> getAllClassName(RootNode* root);
vector<string> getStudentId(ClassNode* classNode);
vector<string> getStudentIdAndName(ClassNode* classNode);
vector<string> getSubject(StudentNode* studentNode);
vector<string> getSubjectAndMark(StudentNode* studentNode);



