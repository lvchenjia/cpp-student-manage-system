// DeleteClass.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "DeleteClass.h"

extern RootNode* root;
// DeleteClass 对话框

IMPLEMENT_DYNAMIC(DeleteClass, CDialogEx)

DeleteClass::DeleteClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

DeleteClass::~DeleteClass()
{
}

void DeleteClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteClass::OnBnClickedButton1)
END_MESSAGE_MAP()


// DeleteClass 消息处理程序


BOOL DeleteClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}


void DeleteClass::OnBnClickedButton1()
{
	CString classname;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	deleteClassNode(root, CString2string(classname));
	MessageBox(_T("删除完成"));
}
