﻿
// StudentManagerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StudentManager.h"
#include "StudentManagerDlg.h"
#include "afxdialogex.h"

#include "NewClass.h"
#include "NewStudent.h"
#include "NewCourse.h"
#include "QueryStudent.h"
#include "QueryCourse.h"
#include "DeleteClass.h"
#include "DeleteStudent.h"
#include "ModifyStudent.h"
#include "ModifyCourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern RootNode* root;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


CStudentManagerDlg::CStudentManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStudentManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEWCLASS, &CStudentManagerDlg::OnBnClickedNewclass)
	ON_BN_CLICKED(IDC_QUERYCLASS, &CStudentManagerDlg::OnBnClickedQueryclass)
	ON_BN_CLICKED(IDC_NEWSTUDENT, &CStudentManagerDlg::OnBnClickedNewstudent)
	ON_BN_CLICKED(IDC_NEWCOURSE, &CStudentManagerDlg::OnBnClickedNewcourse)
	ON_BN_CLICKED(IDC_QUERYSTUDENT, &CStudentManagerDlg::OnBnClickedQuerystudent)
	ON_BN_CLICKED(IDC_DELETECLASS, &CStudentManagerDlg::OnBnClickedDeleteclass)
	ON_BN_CLICKED(IDC_DELTETESTUDENT, &CStudentManagerDlg::OnBnClickedDeltetestudent)
	ON_BN_CLICKED(IDC_MODIFYSTUDENT, &CStudentManagerDlg::OnBnClickedModifystudent)
	ON_BN_CLICKED(IDC_MODIFYMARK, &CStudentManagerDlg::OnBnClickedModifymark)
	ON_BN_CLICKED(IDC_QUERYCOURSE, &CStudentManagerDlg::OnBnClickedQuerycourse)
END_MESSAGE_MAP()


// CStudentManagerDlg 消息处理程序

BOOL CStudentManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	appendClassNode(root, "一班", "");
	appendClassNode(root, "二班", "");
	appendClassNode(root, "三班", "");
	appendClassNode(root, "四班", "");
	ClassNode* classNode = findClassNode(root->firstClass, "一班");
	appendStudentNode(classNode, "1", "李明", "男", "19", "12345");
	appendStudentNode(classNode, "2", "李华", "男", "18", "123456");
	appendStudentNode(classNode, "3", "李梅", "女", "17", "1234567");
	StudentNode* studentNode = findStudentNode(classNode->firstStudent, "1");
	appendCourseNode(studentNode, "语文", "98");
	appendCourseNode(studentNode, "数学", "99");
	appendCourseNode(studentNode, "英语", "100");


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CStudentManagerDlg::OnBnClickedNewclass()
{
	NewClass newClassDlg;
	newClassDlg.DoModal();
}

void CStudentManagerDlg::OnBnClickedNewstudent()
{
	NewStudent newStudentDlg;
	newStudentDlg.DoModal();
}

void CStudentManagerDlg::OnBnClickedQueryclass()
{
	vector<string> s = getAllClassName(root);
	CString str;
	for (auto i : s) {
		str += string2CString(i);
		str += _T("\n");
	}
	str += string2CString("共计" + to_string(s.size()) + "个班");
	MessageBox(str);
}


void CStudentManagerDlg::OnBnClickedNewcourse()
{
	NewCourse newCourseDlg;
	newCourseDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedQuerystudent()
{
	QueryStudent qStuDlg;
	qStuDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedDeleteclass()
{
	DeleteClass dcDlg;
	dcDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedDeltetestudent()
{
	DeleteStudent dsDlg;
	dsDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedModifystudent()
{
	ModifyStudent msDlg;
	msDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedModifymark()
{
	ModifyCourse mcDlg;
	mcDlg.DoModal();
}


void CStudentManagerDlg::OnBnClickedQuerycourse()
{
	QueryCourse qcDlg;
	qcDlg.DoModal();
}
