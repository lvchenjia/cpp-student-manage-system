// ModifyStudent.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "ModifyStudent.h"

extern RootNode* root;
// ModifyStudent 对话框

IMPLEMENT_DYNAMIC(ModifyStudent, CDialogEx)

ModifyStudent::ModifyStudent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

ModifyStudent::~ModifyStudent()
{
}

void ModifyStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ModifyStudent, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ModifyStudent::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &ModifyStudent::OnBnClickedButton1)
END_MESSAGE_MAP()


// ModifyStudent 消息处理程序


BOOL ModifyStudent::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}


void ModifyStudent::OnCbnSelchangeCombo1()
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


void ModifyStudent::OnBnClickedButton1()
{
	CString classname, studentid;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	StudentNode* studentNode = findStudentNode(classNode->firstStudent, CString2string(studentid));
	CString name,sex,age,phonenum;
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(sex);
	GetDlgItem(IDC_EDIT3)->GetWindowText(age);
	GetDlgItem(IDC_EDIT4)->GetWindowText(phonenum);
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
	studentNode->name = CString2string(name);
	studentNode->sex = CString2string(sex);
	studentNode->age = CString2string(age);
	studentNode->phonenum = CString2string(phonenum);
	MessageBox(_T("修改完成"));
}
