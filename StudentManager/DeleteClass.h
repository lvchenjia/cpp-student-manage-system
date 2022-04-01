#pragma once
#include "afxdialogex.h"


// DeleteClass 对话框

class DeleteClass : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteClass)

public:
	DeleteClass(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteClass();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
