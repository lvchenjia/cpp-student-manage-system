// NewClass.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "NewClass.h"

extern RootNode *root;
// NewClass 对话框

IMPLEMENT_DYNAMIC(NewClass, CDialogEx)

NewClass::NewClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

NewClass::~NewClass()
{
}

void NewClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &NewClass::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewClass 消息处理程序


void NewClass::OnBnClickedButton1()
{
	CString name, id;
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(id);
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	appendClassNode(root, (LPCSTR)(CStringA)(name), (LPCSTR)(CStringA)(id));
	MessageBox(_T("新建成功"));
}
