// ModifyCourse.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "ModifyCourse.h"

extern RootNode* root;
// ModifyCourse 对话框

IMPLEMENT_DYNAMIC(ModifyCourse, CDialogEx)

ModifyCourse::ModifyCourse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{

}

ModifyCourse::~ModifyCourse()
{
}

void ModifyCourse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ModifyCourse, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ModifyCourse::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &ModifyCourse::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &ModifyCourse::OnBnClickedButton1)
END_MESSAGE_MAP()


// ModifyCourse 消息处理程序


BOOL ModifyCourse::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}


void ModifyCourse::OnCbnSelchangeCombo1()
{
	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO2);
	CString classname;
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(index);
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	if (classname.GetLength()==0)return;
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	vector<string> s = getStudentId(classNode);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}
}


void ModifyCourse::OnCbnSelchangeCombo2()
{
	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO3);
	CString studentid;
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(index);
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	if (studentid.GetLength() == 0)return;

	CString classname;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));

	StudentNode* studentNode = findStudentNode(classNode->firstStudent, CString2string(studentid));

	vector<string> s = getSubject(studentNode);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}
}


void ModifyCourse::OnBnClickedButton1()
{
	CString classname;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	CString studentid;
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	CString subject;
	GetDlgItem(IDC_COMBO3)->GetWindowTextW(subject);

	CString mark;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(mark);

	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	StudentNode* studentNode = findStudentNode(classNode->firstStudent, CString2string(studentid));
	CourseNode* courseNode = findCourseNode(studentNode->firstCourse, CString2string(subject));
	courseNode->mark = CString2string(mark);
	MessageBox(_T("修改完成"));
}
