// DeleteStudent.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "DeleteStudent.h"

extern RootNode* root;
// DeleteStudent 对话框

IMPLEMENT_DYNAMIC(DeleteStudent, CDialogEx)

DeleteStudent::DeleteStudent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

DeleteStudent::~DeleteStudent()
{
}

void DeleteStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteStudent, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DeleteStudent::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteStudent::OnBnClickedButton1)
END_MESSAGE_MAP()


// DeleteStudent 消息处理程序


BOOL DeleteStudent::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}


void DeleteStudent::OnCbnSelchangeCombo1()
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


void DeleteStudent::OnBnClickedButton1()
{
	CString classname, studentid;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	deleteStudentNode(classNode, CString2string(studentid));
	MessageBox(_T("删除完成"));
}
