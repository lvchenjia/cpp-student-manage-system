#pragma once
#include "afxdialogex.h"


// NewStudent 对话框

class NewStudent : public CDialogEx
{
	DECLARE_DYNAMIC(NewStudent)

public:
	NewStudent(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewStudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
