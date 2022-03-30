#include <iostream>
#include <string>
#include <vector>

using namespace std;

//学生的学科信息
struct CourseNode
{
	string subject;
	string mark;
	CourseNode *nextCourse;
};

//学生信息
struct StudentNode
{
	string id;
	string name;
	string sex;
	string age;
	string phonenum;
	CourseNode *firstCourse;
	StudentNode *nextStudent;
};

//班级信息
struct ClassNode
{
	string classid;
	string classname;
	StudentNode *firstStudent;
	ClassNode *nextClass;
};

//根节点
struct RootNode
{
	ClassNode *firstClass;
};

//创建新节点
ClassNode *createClassNode(string classname, string classid)
{
	ClassNode *newClass = new ClassNode();
	newClass->classid = classid;
	newClass->classname = classname;
	newClass->firstStudent = NULL;
	newClass->nextClass = NULL;
	return newClass;
}

StudentNode *createStudentNode(string id, string name, string sex, string age, string phonenum)
{
	StudentNode *newStudent = new StudentNode();
	newStudent->id = id;
	newStudent->name = name;
	newStudent->sex = sex;
	newStudent->age = age;
	newStudent->phonenum = phonenum;
	newStudent->firstCourse = NULL;
	newStudent->nextStudent = NULL;
	return newStudent;
}

CourseNode *createCourseNode(string subject, string mark)
{
	CourseNode *newCourse = new CourseNode();
	newCourse->subject = subject;
	newCourse->mark = mark;
	newCourse->nextCourse = NULL;
	return newCourse;
}

//定位到尾部节点
ClassNode *findLastClassNode(ClassNode *classNode)
{
	ClassNode *p = classNode;
	if (!p)
		return NULL;
	while (p->nextClass)
		p = p->nextClass;
	return p;
}

StudentNode *findLastStudentNode(StudentNode *studentNode)
{
	StudentNode *p = studentNode;
	if (!p)
		return NULL;
	while (p->nextStudent)
		p = p->nextStudent;
	return p;
}

CourseNode *findLastCourseNode(CourseNode *courseNode)
{
	CourseNode *p = courseNode;
	if (!p)
		return NULL;
	while (p->nextCourse)
		p = p->nextCourse;
	return p;
}

//查找结点
ClassNode *findClassNode(ClassNode *classNode, string name)
{
	ClassNode *p = classNode;
	while (p)
	{
		if (p->classname == name)
			return p;
		p = p->nextClass;
	}
	return NULL;
}

StudentNode *findStudentNode(StudentNode *studentNode, string id)
{
	StudentNode *p = studentNode;
	while (p)
	{
		if (p->id == id)
			return p;
		p = p->nextStudent;
	}
	return NULL;
}

CourseNode *findCourseNode(CourseNode *courseNode, string subject)
{
	CourseNode *p = courseNode;
	while (p)
	{
		if (p->subject == subject)
			return p;
		p = p->nextCourse;
	}
	return NULL;
}

//尾部插入新节点
void appendClassNode(RootNode *root, string classname, string classid)
{
	ClassNode *pre = findLastClassNode(root->firstClass);
	ClassNode *newClass = createClassNode(classname, classid);
	if (pre)
		pre->nextClass = newClass;
	else
		root->firstClass = newClass;
}

void appendStudentNode(ClassNode *classNode, string id, string name, string sex, string age, string phonenum)
{
	StudentNode *pre = findLastStudentNode(classNode->firstStudent);
	StudentNode *newStudent = createStudentNode(id, name, sex, age, phonenum);
	if (pre)
		pre->nextStudent = newStudent;
	else
		classNode->firstStudent = newStudent;
}

void appendCourseNode(StudentNode *studentNode, string subject, string mark)
{
	CourseNode *pre = findLastCourseNode(studentNode->firstCourse);
	CourseNode *newCourse = createCourseNode(subject, mark);
	if (pre)
		pre->nextCourse = newCourse;
	else
		studentNode->firstCourse = newCourse;
}

//释放节点及其子节点空间
void freeCourseLink(CourseNode *courseNode)
{
	if (!courseNode)
		return;
	CourseNode *p = courseNode;
	CourseNode *q = courseNode->nextCourse;
	while (p->nextCourse)
	{
		free(p);
		p = q;
		q = q->nextCourse;
	}
}

void freeStudentLink(StudentNode *studentNode)
{
	if (!studentNode)
		return;
	StudentNode *p = studentNode;
	StudentNode *q = studentNode->nextStudent;
	while (p->nextStudent)
	{
		freeCourseLink(p->firstCourse);
		free(p);
		p = q;
		q = q->nextStudent;
	}
}

//删除节点
void deleteClassNode(RootNode *root, string classname)
{
	ClassNode *p = NULL;
	ClassNode *q = root->firstClass;
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

void deleteStudentNode(ClassNode *classNode, string id)
{
	StudentNode *p = NULL;
	StudentNode *q = classNode->firstStudent;
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

void deleteCourseNode(StudentNode *studentNode, string subject)
{
	CourseNode *p = NULL;
	CourseNode *q = studentNode->firstCourse;
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
vector<string> getAllClassName(RootNode *root)
{ //获取全部班级名
	ClassNode *p = root->firstClass;
	vector<string> rst;
	while (p)
	{
		rst.push_back(p->classname);
		p = p->nextClass;
	}
	return rst;
}

vector<string> getStudentId(ClassNode *classNode)
{ //获取某班内全部学生id
	StudentNode *p = classNode->firstStudent;
	vector<string> rst;
	while (p)
	{
		rst.push_back(p->id);
		p = p->nextStudent;
	}
	return rst;
}

vector<string> getStudentIdAndName(ClassNode *classNode)
{ //获取某班内全部学生id与姓名
	StudentNode *p = classNode->firstStudent;
	vector<string> rst;
	while (p)
	{
		rst.push_back(p->id + " " + p->name);
		p = p->nextStudent;
	}
	return rst;
}

vector<string> getSubject(StudentNode *studentNode)
{ //获取某学生全部课程名
	CourseNode *p = studentNode->firstCourse;
	vector<string> rst;
	while (p)
	{
		rst.push_back(p->subject);
		p = p->nextCourse;
	}
	return rst;
}

vector<string> getSubjectAndMark(StudentNode *studentNode)
{ //获取某学生全部课程名与分数
	CourseNode *p = studentNode->firstCourse;
	vector<string> rst;
	while (p)
	{
		rst.push_back(p->subject + " " + p->mark);
		p = p->nextCourse;
	}
	return rst;
}


#define SIZE 100

typedef struct {
	int elem[SIZE];
	int li;
	int ri;	
}TwoWayStack;

bool isfull(TwoWayStack *tws){
	return tws->li==tws->ri;
}

void initstack(TwoWayStack *tws){
	tws->li = 0;
	tws->ri = SIZE-1;
}

void push(TwoWayStack *tws,int i, int x){
	if(isfull(tws))return;
	if(i){
		tws->elem[tws->li++] = x;
	}else{
		tws->elem[tws->ri++] = x;
	}
}

void pop(TwoWayStack *tws, int i){
	if(i){
		if(tws->li==0)return;
		else tws->li--;
	}else{
		if(tws->ri==SIZE-1)return;
		else tws->ri--;
	}
}