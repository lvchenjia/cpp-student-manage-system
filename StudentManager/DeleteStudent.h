#pragma once
#include "afxdialogex.h"


// DeleteStudent 对话框

class DeleteStudent : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteStudent)

public:
	DeleteStudent(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteStudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};
