// NewStudent.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "NewStudent.h"

extern RootNode* root;

// NewStudent 对话框

IMPLEMENT_DYNAMIC(NewStudent, CDialogEx)

NewStudent::NewStudent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

NewStudent::~NewStudent()
{
}

void NewStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewStudent, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &NewStudent::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewStudent 消息处理程序

void NewStudent::OnBnClickedButton1()
{
	CString id,name,sex,age,phonenum;
	GetDlgItem(IDC_EDIT2)->GetWindowText(id);
	GetDlgItem(IDC_EDIT3)->GetWindowText(name);
	GetDlgItem(IDC_EDIT4)->GetWindowText(sex);
	GetDlgItem(IDC_EDIT5)->GetWindowText(age);
	GetDlgItem(IDC_EDIT6)->GetWindowText(phonenum);
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT6)->SetWindowText(_T(""));
	CString classname;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	ClassNode *classNode = findClassNode(root->firstClass, CString2string(classname));
	appendStudentNode(classNode, (LPCSTR)(CStringA)(id), (LPCSTR)(CStringA)(name), (LPCSTR)(CStringA)(sex), (LPCSTR)(CStringA)(age), (LPCSTR)(CStringA)(phonenum));
	MessageBox(_T("新建成功"));
}


BOOL NewStudent::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}
