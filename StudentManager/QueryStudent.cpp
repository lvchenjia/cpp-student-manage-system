// QueryStudent.cpp: 实现文件
//

#include "pch.h"
#include "StudentManager.h"
#include "afxdialogex.h"
#include "QueryStudent.h"

extern RootNode* root;

// QueryStudent 对话框

IMPLEMENT_DYNAMIC(QueryStudent, CDialogEx)

QueryStudent::QueryStudent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

QueryStudent::~QueryStudent()
{
}

void QueryStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QueryStudent, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QueryStudent::OnBnClickedButton1)
END_MESSAGE_MAP()


// QueryStudent 消息处理程序


void QueryStudent::OnBnClickedButton1()
{
	CString classname;
	GetDlgItem(IDC_COMBO1)->GetWindowTextW(classname);
	ClassNode* classNode = findClassNode(root->firstClass, CString2string(classname));
	vector<string> s = getStudentIdAndName(classNode);
	CString str;
	
	for (auto i : s) {
		str += string2CString(i);
		str += _T("\n");
	}
	str += string2CString("共计"+to_string(s.size())+"个学生");
	MessageBox(str);
}


BOOL QueryStudent::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	vector<string> s = getAllClassName(root);
	for (string i : s) {
		box->AddString(CString(i.c_str()));
	}

	return TRUE;
}
