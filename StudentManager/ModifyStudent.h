#pragma once
#include "afxdialogex.h"


// ModifyStudent 对话框

class ModifyStudent : public CDialogEx
{
	DECLARE_DYNAMIC(ModifyStudent)

public:
	ModifyStudent(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ModifyStudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};
