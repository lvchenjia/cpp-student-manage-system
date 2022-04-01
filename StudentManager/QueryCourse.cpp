// QueryCourse.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "QueryCourse.h"

extern RootNode* root;
// QueryCourse 对话框

IMPLEMENT_DYNAMIC(QueryCourse, CDialogEx)

QueryCourse::QueryCourse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

QueryCourse::~QueryCourse()
{
}

void QueryCourse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QueryCourse, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &QueryCourse::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &QueryCourse::OnBnClickedButton1)
END_MESSAGE_MAP()


// QueryCourse 消息处理程序


BOOL QueryCourse::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}


void QueryCourse::OnCbnSelchangeCombo1()
{
	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO2);
	CString classname;
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();//更新combo状态 selchang事件触发时text并未改变 要进行此操作！
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(index);
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	vector<string> s = getStudentId(classNode);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}
}


void QueryCourse::OnBnClickedButton1()
{
	CString classname, studentid;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	StudentNode* studentNode = findStudentNode(classNode->firstStudent, CString2string(studentid));
	vector<string> s = getSubjectAndMark(studentNode);
	string str;
	str += "学号：";
	str += studentNode->id;
	str += "\n姓名：";
	str += studentNode->name;
	str += "\n年龄：";
	str += studentNode->age;
	str += "\n性别：";
	str += studentNode->sex;
	str += "\n电话：";
	str += studentNode->phonenum;
	str += "\n成绩：";
	for (string i : s) {
		str += i;
		str += "\n";
	}
	MessageBox(string2CString(str));
}
