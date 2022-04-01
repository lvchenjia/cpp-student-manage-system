#pragma once
#include "afxdialogex.h"


// QueryCourse 对话框

class QueryCourse : public CDialogEx
{
	DECLARE_DYNAMIC(QueryCourse)

public:
	QueryCourse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~QueryCourse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};
