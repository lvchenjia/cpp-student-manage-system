#pragma once
#include "afxdialogex.h"


// ModifyCourse 对话框

class ModifyCourse : public CDialogEx
{
	DECLARE_DYNAMIC(ModifyCourse)

public:
	ModifyCourse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ModifyCourse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton1();
};
