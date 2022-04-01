// NewCourse.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "NewCourse.h"

extern RootNode* root;
// NewCourse 对话框

IMPLEMENT_DYNAMIC(NewCourse, CDialogEx)

NewCourse::NewCourse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

NewCourse::~NewCourse()
{
}

void NewCourse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewCourse, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &NewCourse::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &NewCourse::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewCourse 消息处理程序


BOOL NewCourse::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}

void NewCourse::OnCbnSelchangeCombo1()
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

void NewCourse::OnBnClickedButton1()
{
	CString subject,mark;
	GetDlgItem(IDC_EDIT1)->GetWindowText(subject);
	GetDlgItem(IDC_EDIT2)->GetWindowText(mark);
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	CString classname,studentid;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	GetDlgItem(IDC_COMBO2)->GetWindowTextW(studentid);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	StudentNode* studentNode = findStudentNode(classNode->firstStudent, CString2string(studentid));
	appendCourseNode(studentNode, (LPCSTR)(CStringA)(subject), (LPCSTR)(CStringA)(mark));
	MessageBox(_T("新建成功"));
}
