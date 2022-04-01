#pragma once
#include "afxdialogex.h"


// QueryStudent 对话框

class QueryStudent : public CDialogEx
{
	DECLARE_DYNAMIC(QueryStudent)

public:
	QueryStudent(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~QueryStudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
